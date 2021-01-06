# La cible par défault sera le programme de test.
.DEFAULT_GOAL := test

.PHONY: clean

# Liste des cibles.

# Efface tous les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux (ROT13.o, chiffrage.a, test, etc.).
build:
	mkdir -p build

# Bibliothèque de chiffrage. Quatre cibles, trois pour compiler les codes de chiffrage en fichiers objets (ROT13.o, etc.) et 
# une pour les lier en bibliothèque statique (libchiffrage.a).
build/ROT13.o: lib/ROT13.c | build
	gcc -Wall -Werror -pedantic --debug -c lib/ROT13.c -I ./lib -o build/ROT13.o

# ... ?

build/libchiffrage.a: build/ROT13.o | build
	ar crs build/libchiffrage.a build/ROT13.o


# Programme de test. Trois cibles, une pour compiler le code de test en fichier objet, une pour lier le fichier objet avec 
# la bibliothèque statique de chiffrage et une dernière de "commodité" pour directement lancer le programme à l'invite de commandes.
build/test.o: test/main.c | build
	gcc -Wall -Werror -pedantic --debug -c test/main.c -I ./lib -o build/test.o

build/test: build/test.o build/libchiffrage.a | build
	gcc build/test.o -Lbuild -lchiffrage -o build/test

check: build/test
	./build/test
