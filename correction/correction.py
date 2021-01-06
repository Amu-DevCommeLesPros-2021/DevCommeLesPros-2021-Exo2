"""Correction script for this exercise.
For each depot name found in depots.txt:
- clones the repo.
- confirms main.c is the same as the original.
- invokes make test.
- runs test.
- prints the return code of test or a negative value if an earlier error occured:
    - -1: failed to clone the repo.
    - -2: mismatch detected between original in main.c and depot's main.c.
    - -3: failed to compile.
"""

import argparse
import datetime
import hashlib
import itertools
import os
import platform
import sys
import subprocess

import pygit2

ARGPARSER = argparse.ArgumentParser()
ARGPARSER.add_argument('-t', '--timestamp', dest='timestamp', action='store', metavar='TIMESTAMP(DD-MM-YYY HH24:MM)',
                       help='Date and time at which to clone the repositories.')
ARGPARSER.add_argument('-l', '--show-log', dest='showlog', action='store_true',
                       help='Print git log of repositories.')
ARGS = ARGPARSER.parse_args()

# Verify timestamp format, if present.
if ARGS.timestamp:
    try:
        datetime.datetime.strptime(ARGS.timestamp, "%d/%m/%Y %H:%M")
    except ValueError:
        print('Bad timestamp', sys.exc_info())
        sys.exit(100)

def hash_test_code(main_path):
    """Hashes file main_path."""
    with open(main_path) as main:
        test_code_hash = hashlib.sha256()
        for line in main:
            test_code_hash.update(line.encode())
    return test_code_hash.hexdigest()

PROFESSOR_TEST_CODE_HEXDIGEST = '22c0d504a3335886a369d75f72f07474b1d10599c294b1b45770e9ffdbc43b95'
PROFESSOR_CHIFFRE_HEXDIGEST = '60ff41b09e4e1011d3a5f33704ec53df319a248d1de48250a131b809a85cb2db'
PROFESSOR_CLAIR_HEXDIGEST = '4ef57703aad7ffd9f3129bb46c81a15308f1963e1f12ab00718f3569fde090f3'
CALLBACKS = pygit2.RemoteCallbacks(credentials=pygit2.KeypairFromAgent("git"))

with open('depots.txt') as depots_lines:
    for depots_line in itertools.dropwhile(lambda line: line.startswith('#'),
                                           depots_lines):
        try:
            cells = depots_line.rstrip().split(",")

            # Craft URL to clone given a depot name.
            remote_depot_name = cells[0]
            remote_depot_url = 'ssh://git@github.com/' + remote_depot_name + '.git'
            local_depot_path = remote_depot_name.replace('/', '-')
            print(local_depot_path, end=' ')

            # Clone the repo.
            if (not os.path.exists(local_depot_path)) and \
               (pygit2.clone_repository(remote_depot_url, local_depot_path, callbacks=CALLBACKS) is None):
                raise RuntimeError('-1 unable to clone repo')

            # If timestamp is specified, checkout at that point in time.
            timestamp = None
            if len(cells) > 1:
                try:
                    datetime.datetime.strptime(cells[1], "%d/%m/%Y %H:%M")
                    timestamp = cells[1]
                except:
                    raise RuntimeError('-1')
            elif ARGS.timestamp is not None:
                timestamp = ARGS.timestamp

            if timestamp is not None:
                try:
                    rev_list_cmd = subprocess.run('git rev-list -n 1 --before="' + timestamp + '" master',
                                                  cwd=local_depot_path, stdout=subprocess.PIPE, shell=True,
                                                  text=True, check=True)
                    if not rev_list_cmd.stdout:
                        raise RuntimeError('-1 repo non-existant at timestamp')
                except subprocess.CalledProcessError:
                    raise RuntimeError('-1 git rev-list failed')
                else:
                    print(timestamp, end=' ')
                    os.system('cd ' + local_depot_path + ' && ' +
                              'git checkout --quiet ' + rev_list_cmd.stdout)

            # Confirm test code is intact.
            if hash_test_code(local_depot_path + '/test/main.c') != PROFESSOR_TEST_CODE_HEXDIGEST or \
               hash_test_code(local_depot_path + '/test/chiffre.txt') != PROFESSOR_CHIFFRE_HEXDIGEST or \
               hash_test_code(local_depot_path + '/test/clair.txt') != PROFESSOR_CLAIR_HEXDIGEST:
                raise RuntimeError('-2')

            # Compile.
            if os.system('cd ' + local_depot_path + ' && make -s test') != 0:
                raise RuntimeError('-3')

            # Run and print result.
            print(str(os.WEXITSTATUS(os.system('cd ' + local_depot_path + ' && build/' + \
                      platform.system() + '/test'))))

            # If show-log is specified, show log.
            if ARGS.showlog:
                os.system('cd ' + local_depot_path + ' && git log --oneline --graph --decorate')
        except pygit2.GitError:
            print('-1')
        except RuntimeError as error:
            print(error.args[0])
