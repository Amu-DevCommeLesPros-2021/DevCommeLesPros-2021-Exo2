# La cible par défault sera le programme de test.
.DEFAULT_GOAL := build/test

.PHONY: clean

# Liste des cibles.

# Efface tous les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits 
# finaux (ROT13.o, libchiffrage.a, test, etc.).
build:
	mkdir -p build

# Bibliothèque de chiffrage. Quatre cibles : trois pour compiler les codes de 
# chiffrage en fichiers objets (ROT13.o, etc.) et une pour les lier en 
# bibliothèque statique (libchiffrage.a).
build/ROT13.o: lib/ROT13.c lib/ROT13.h | build
	gcc -Wall -Werror -pedantic --debug -c lib/ROT13.c -I ./lib -o build/ROT13.o

# ... ?

build/libchiffrage.a: lib/chiffrage.h build/ROT13.o | build
	ar crs build/libchiffrage.a build/ROT13.o


# Programme de test. Trois cibles : une pour compiler le code de test en fichier 
# objet, une pour lier le fichier objet avec la bibliothèque statique de 
# chiffrage et une dernière de "commodité" pour directement lancer le programme 
# de test à l'invite de commandes.
build/test.o: test/main.c | build
	gcc -Wall -Werror -pedantic --debug -c test/main.c -I ./lib -o build/test.o

build/test: build/test.o build/libchiffrage.a | build
	gcc build/test.o -L build -l chiffrage -o build/test

check: build/test
	./build/test

# Construit le programme "chiffre", un programme à utiliser à l'invite de commande 
# pour chiffer ou déchiffrer des fluxs de texte avec l'algorithme de Vigenère.
# Exemple : 
# $ ./build/chiffre -c banane -d <<< "Nef frpjcvtnxjoas"
build/chiffre: bin/main.c build/libchiffrage.a | build
	gcc -Wall -Werror -pedantic --debug bin/main.c -I ./lib -L build -l chiffrage -o build/chiffre
