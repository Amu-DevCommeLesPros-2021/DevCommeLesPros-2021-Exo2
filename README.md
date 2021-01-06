# DevCommeLesPros-2021-Ex02

Modèle de départ pour exercices d'introduction au makefile, à une structure de projet et aux bibliothèques logicielles.

## Instructions de départ

Ces intructions présupposent que vous avez déjà suivi les instructions du [zérotième exercice](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo0#instructions-de-d%C3%A9part) pour la création d'un compte GitHub et l'installation des programmes et extensions nécéssaires.

1. Créez votre dépôt sur github.com en utilisant ce dépôt-ci (https://github.com/thierryseegers/DevCommeLesPros-2021-Exo2) comme modèle.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template.
    - Choisissez l'option `Private` à l'étape 5.
1. Ajoutez le professeur comme collaborateur à votre dépôt.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository.
        - Nom d'utilisateur à ajouter: `thierryseegers`.
1. Clonez votre dépôt vers votre espace de travail local.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/creating-cloning-and-archiving-repositories/cloning-a-repository.
    - Attention à ne pas cloner https://github.com/thierryseegers/DevCommeLesPros-2021-Exo2 mais bien votre dépôt nouvellement créé.
1. Lancez Visual Studio Code.
    - À l'invite de commandes :
        - `$ cd [nom de votre dépôt]`
        - `$ code .`
1. Compilez une première fois le programme.
    - Menu: `View` > `Command Palette` > `Tasks: Run Build Task`
1. Vous devriez observer dans l'onglet `TERMINAL` le résultat suivant :
    - Sous Linux : 
        - `collect2: error: ld returned 1 exit status`
    - Sous MacOS : 
        - `clang: error: linker command failed with exit code 1`

## Objectif

Dans ce dépôt se trouve des fichiers de code qui composent une bibliothèque statique `libchiffrage.a`.
Cette bibliothèque contient des fonctions servant à chiffer et à déchiffrer des chaînes de charatères suivant des méthodes diverses (bien qu'anciennes et peu sécuritaires !).
Il se trouve aussi un programme de test (`build/test`) qui confirme que les fonctions sont bien implémentées.

1. Réparez le fichier `makefile` pour faire en sorte que la bibliothèque `libchiffrage.a` contienne tous les fichiers objets nécéssaires (fussent-ils eux-même temporairement incomplets) et que le programme `test` puisse être correctment lié et lancé.
1. Implémentez correctement toutes les fonctions de chiffrages pour que le programme `build/test` renvoie `0` à l'invite de commande.

Il vous est permis : 
- De modifier le fichier `makefile`.
- De modifier les fichiers `lib/ROT13.c`, `lib/Cesar.c` et `lib/Vigenere.c` afin d'implémenter les fonctions qu'ils contiennent.

Il ne vous est pas permis :
- De modifier le fichier `test/main.c`.
- De modifier les fichiers d'entête `lib/chiffrage.h`, `lib/ROT13.h`, `lib/Cesar.h`, `lib/Vigenere.h` et `lib/chiffrage.h`.

## Instructions de travail

1. Créez une nouvelle branche qui servira de branche de travail pour réparer une première suite de tests.
    - `$ git branch [nom de la branche]`
    - `$ git checkout [nom de la branche]`
    - Exemple: `$ git branch reparation-ROT13` suivi de `$ git checkout reparation-ROT13`.
1. Au fur et à mesure de vos modifications au code, intégrez-les au dépôt local avec une description des modifications apportées.
    - `$ git add [fichiers]`
    - `$ git commit -m "Description des modifications apportées"`
    - Exemple: `$ git add lib/ROT13.c` suivi de `$ git commit -m "Passe les tests de chiffrage sans ponctuations."`
1. Périodiquement, publiez votre branche de votre dépôt local à votre dépôt sur GitHub.
    - `$ git push origin [nom de la branche]`
    - Exemple: `$ git push origin reparation-ROT13`.
1. Lorsqu'une suite de tests est réparée, ouvrez un "Pull Request" sur GitHub pour fusionner la branche de travail à la branche `master`.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/desktop/contributing-and-collaborating-using-github-desktop/creating-an-issue-or-pull-request.
1. Fusionnez la branche de travail sur GitHub.
    - Suivez ces instructions : https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/merging-a-pull-request#merging-a-pull-request-on-github.
    - Choisissez `Create a merge commit` à l'étape 3. 
1. Revenez sur la branche `master` de votre dépôt local et synchronisez-la avec la branche `master` de votre dépôt sur GitHub.
    - `$ git checkout master`
    - `$ git pull origin master`
1. Répétez ces étapes jusqu'à ce que tous les tests passent.

Avec la commande `$ git log --all --decorate --oneline --graph`, l'historique de votre travail devrait au fil du temps ressembler à ceci (lire du bas vers le haut) :

```
*   cac0381 (origin/master, origin/HEAD, master) Merge pull request #3 from [compte]/reparation-Cesar
|\
| * dd15e7c Passe tous les tests de déchiffrage aussi.
| * 329025a Passe tous les tests de chiffrage.
| * 6247b82 Passe tous les tests sans ponctuation.
| * 3829cc5 Oups ! Maintenant passe vraiment tous les tests avec lettres minuscules.
| * 49261da Passe les tests de chiffrage avec les lettres minuscules.
| * 4569e14 Passe les test avec chaînes longues mais j'ai cassé les tests avec chaînes courtes. J'y reviendrai.
| * 4297b0e Passe les tests avec chaînes courtes.
|/
*   34678ab Merge pull request #2 from [compte]/reparation-ROT13
|\
| * 6c93b12 Passe tous les tests de déchiffrage aussi. Facile ! En fait, c'est la même chose dans les deux sens.
| * b658f2b Passe tous les tests de chiffrage.
| * 5d8c89b Passe les tests de chiffrage sans ponctuations.
|/
*   34678ab Merge pull request #1 from [compte]/reparation-makefile
|\
| * 5d8c89b Peut compiler, lancer et déboguer le programme test.
|/
* 68cb404 Initial commit
```

## Questions-Réponses

### «J'ai un problème !»

Outre les indications données dans le [premier exercice](https://github.com/thierryseegers/DevCommeLesPros-2021-Exo1#jai-un-probl%C3%A8me-) à ce sujet, le site https://cryptii.com peut vous aider à comprendre et tester différentes méthodes de (dé)chiffrage sur un texte en clair.

## Évaluation

1. Le suivi des instructions de travail.
1. Le nombre de tests réussis.
1. La qualité des modifications apportées.

Attention ! *Seul le code **de la branche `master`** de votre dépôt sur GitHub compte !*
