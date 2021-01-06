# DevCommeLesPros-2020-Ex2
Modèle de départ pour exercices d'introduction au makefile, à une structure de projet et aux bibliothèques logicielles.


## Instructions de départ

Ces intructions présupposent que vous avez déjà suivi les instructions de l'[exercice précédent](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex1#instructions-de-d%C3%A9part) pour la création de compte et l'installation des programmes et extensions nécéssaires.

1. Créez votre dépôt sur github.com en utilisant ce dépôt-ci (https://github.com/thierryseegers/DevCommeLesPros-2020-Ex2) comme modèle.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template.
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez ces instructions: https://help.github.com/en/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository
        - Nom d'utilisateur à ajouter: `thierryseegers`.
1. Clonez votre dépôt vers votre espace de travail local.
    - Suivez ces instructions: https://help.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository
    - Attention à ne pas cloner https://github.com/thierryseegers/DevCommeLesPros-2020-Ex2 mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes:
        - `> cd [nom de votre dépôt]`
        - `> code .`
1. Si vous voyez le message `The debug type is not recognized. Make sure that you have a corresponding debug extension installed and that it is enabled.`, n'en tenez pas compte.
1. Compilez une première fois le programme.
    - Menu: `View` > `Command Palette` > `Tasks: Run Build Task`
1. Vous devriez observer dans l'onglet `TERMINAL` le résultat suivant:
    - Sous Linux: 
        - `collect2: error: ld returned 1 exit status`
    - Sous MacOS: 
        - `clang: error: linker command failed with exit code 1`


## Objectif principal

1. Réparez le fichier `makefile` pour faire en sorte que la bibliothèque `libchiffrage.a` contienne tous les fichiers objets nécéssaires (fussent-ils eux-même temporairement incomplets) et que le programme `test` puisse être correctment lié et lancé.
1. Implémentez correctement toutes les fonctions de chiffrages (à l'exception de `chiffre_Vigenere_flux_binaire` et `dechiffre_Vigenere_flux_binaire`) pour que le programme `test` retourne `0`.

Il vous est permis: 
- De modifier le fichier `makefile`.
- De modifier les fichiers `lib/ROT13.c`, `lib/Cesar.c` et `lib/Vigenere.c` afin d'implémenter les fonctions qu'ils contiennent.

Il ne vous est pas permis:
- De modifier le fichier `test/main.c`.
- De modifier les fichiers d'entête `lib/chiffrage.h`, `lib/ROT13.h`, `lib/Cesar.h`, `lib/Vigenere.h` et `lib/chiffrage.h`.

### Objectif bonus 1 (disponible à tous)

Le mécanisme de chiffrage ROT13 n'est en fait qu'un cas particulier du mécanisme de chiffrage Cesar. C'est-à-dire que la fonction `chiffre_ROT13` peut être implementée en terme de la fonction `chiffre_Cesar`. Il en est de même pour la fonction `dechiffre_ROT13`. Le même raisonnement s'applique pour les fonctions `(de)chiffre_Cesar` qui sont elle-mêmes des cas particuliers des fonctions `(de)chiffre_Vigenere`.

1. Complétez l'objectif principal.
1. Revenez sur votre implémentation des fonctions `(de)chiffre_ROT13` et faites en sorte que leur travail soit accompli en appelant les fonctions `(de)chiffre_Cesar`.
1. Revenez sur votre implétation des fonctions `(de)chiffre_Cesar` et faites en sorte que leur travail soit accompli en appelant les fonctions `(de)chiffre_Vigenere`.

Ce bonus est sans limite de temps.

### Objectif bonus 2 (compétitif)

Vous sentez-vous l'âme d'un cryptanalyste ? Il y a un fichier texte à déchiffrer.

1. Complétez l'objectif principal.
1. Completez le fichier `makefile` pour compiler et lier un programme appelé `chiffre` constitué de la bibliothèque de chiffrage `libchiffrage.a` et du code dans le fichier `bin/main.c`.
1. [Cryptanalysez](https://fr.wikipedia.org/wiki/Cryptanalyse) le [fichier texte chiffré bonus](https://amubox.univ-amu.fr/s/WzgGAyMf8nHktrg). La clé est un mot français sans accent.
1. Déchiffrez le fichier texte chiffré bonus avec votre programme `chiffre` et la bonne clé.
    - `> chiffre -c [clé] -d < chiffré.txt` devrait afficher à l'écran le texte en clair.
1. Publiez votre code à votre dépôt sur github.com.
1. Envoyez un e-mail au professeur (thierry.seegers@yahoo.com) avec la clé et l'auteur du texte.

Ce bonus est sans limite de temps.

### Objectif bonus 3 (compétitif)

Vous sentez-vous l'âme d'un cryptanalyste ? Il y a un fichier MP3 à déchiffrer.

1. Complétez l'objectif principal.
1. Completez le fichier `makefile` pour compiler et lier un programme appelé `chiffre` constitué de la bibliothèque de chiffrage `libchiffrage.a` et du code dans le fichier `bin/main.c`.
1. Implémentez correctement les fonctions de chiffrages `chiffre_Vigenere_flux_binaire` et `dechiffre_Vigenere_flux_binaire`.
1. [Cryptanalysez](https://fr.wikipedia.org/wiki/Cryptanalyse) le [fichier MP3 chiffré bonus(https://amubox.univ-amu.fr/s/WzgGAyMf8nHktrg)]. La clé est un mot français sans accent (différent de l'objectif bonus 2).
1. Déchiffrez le fichier MP3 chiffré bonus avec votre programme `chiffre` et la bonne clé.
    - `> chiffre -b -c [clé] -d < chiffré.mp3 > clair.mp3` devrait produire un fichier MP3 lisible par un programme de lecture.
1. Publiez votre code à votre dépôt sur github.com.
1. Envoyez un e-mail au professeur (thierry.seegers@yahoo.com) avec la clé et l'auteur de la musique.

Ce bonus est sans limite de temps.

## Instructions de travail

1. Créez une nouvelle branche qui servira de branche de travail pour réparer une première suite de tests.
    - `> git branch [nom de la branche]`
    - `> git checkout [nom de la branche]`
    - Exemple: `> git branch reparation-ROT13`, `> git checkout reparation-ROT13`.
1. Au fur et à mesure de vos modifications au code, intégrez-les au dépôt local avec une description des modifications apportées.
    - `> git add [fichiers]`
    - `> git commit -m "Description des modifications apportées"`
    - Exemple: `> git add lib/ROT13.c`, `> git commit -m "Passe les tests de chiffrage sans ponctuations."`
1. Périodiquement, publiez votre branche de votre dépôt local à votre dépôt sur github.com.
    - `> git push origin [nom de la branche]`
    - Exemple: `> git push origin reparation-ROT13`.
1. Lorsqu'une suite de tests est réparée, ouvrez un "Pull Request" sur github.com pour fusionner la branche de travail à la branche `master`.
    - Suivez ces instructions: https://help.github.com/en/desktop/contributing-to-projects/creating-a-pull-request
1. Fusionnez la branche de travail sur github.com.
    - Suivez ces instructions: https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/merging-a-pull-request#merging-a-pull-request-on-github
    - Choisissez `Create a merge commit` à l'étape 3. 
1. Revenez sur la branche `master` de votre dépôt local et synchronisez-la avec la branche `master` de votre dépôt sur github.com.
    - `> git checkout master`
    - `> git pull origin master`
1. Répétez ces étapes jusqu'à ce que tout les tests passent.

Avec la commande `> git log --all --decorate --oneline --graph`, l'historique de votre travail devrait au fil du temps ressembler à ceci (lire du bas vers le haut):

```
*   cac0381 (origin/master, origin/HEAD, master) Merge pull request #3 from [compte]/reparation-Cesar
|\
| * dd15e7c Passe tout les tests de déchiffrage aussi.
| * 329025a Passe tout les tests de chiffrage.
| * 6247b82 Passe tout les tests sans ponctuation.
| * 3829cc5 Oups ! Maintenant passe vraiment tous les tests avec lettres minuscules.
| * 49261da Passe les tests de chiffrage avec les lettres minuscules.
| * 4569e14 Passe les test avec chaînes longues mais j'ai cassé les tests avec chaînes courtes. J'y reviendrai.
| * 4297b0e Passe les tests avec chaînes courtes.
|/
*   34678ab Merge pull request #2 from [compte]/reparation-ROT13
|\
| * 6c93b12 Passe tout les tests de déchiffrage aussi. Facile ! En fait, c'est la même chose dans les deux sens.
| * b658f2b Passe tout les tests de chiffrage.
| * 5d8c89b Passe les tests de chiffrage sans ponctuations.
|/
*   34678ab Merge pull request #1 from [compte]/reparation-makefile
|\
| * 5d8c89b Peut compiler, lancer et déboguer le programme test.
|/
* 68cb404 Initial commit
```

## "J'ai un problème !"

Outre les indications données dans l'[exercice précedent](https://github.com/thierryseegers/DevCommeLesPros-2020-Ex1#jai-un-probl%C3%A8me-) à ce sujet, le site https://cryptii.com peut vous aider à comprendre et tester différentes méthodes de (dé)chiffrage sur un texte en clair.

## ## Évaluation

Dans le répertoire `correction`, vous trouverez le script que le professeur utilisera pour automatiser une première partie du processus de correction.
Pour une liste de dépôts donnée dans `correction/depots.txt`, le script clone et compile le dépôt, lance le programme et affiche le résultat.
Vous pouvez tester votre propre dépôt comme le fera le professeur:
1. Installez le module pygit2 avec `> pip3 install pygit2` à l'invite de commandes.
1. Ajoutez le nom de votre dépôt à la liste `correction/depots.txt`.
1. Lancez le script à l'invite de commandes:
    - `> cd correction`
    - `> python3 correction.py`

La deuxième partie de la correction est une inspection visuelle de votre code.

Seul le code de la branche `master` de votre dépôt sur http://github.com compte !
