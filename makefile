# Création d'une variable qui nommera le système d'exploitation ("Darwin" pour macOS et "Linux" pour Linux).
OS_NAME := $(shell uname -s)

# Création d'une variable pour nommer le compilateur, dépendant du système d'exploitation.
ifeq ($(OS_NAME), Darwin)
	cc := clang
else
	cc := gcc
endif


# La cible par défault sera le programme de test.
.DEFAULT_GOAL := test

.PHONY: clean


# Liste des cibles.

# Efface tous les fichiers temporaires et les produits finaux.
clean:
	rm -rf build/$(OS_NAME)

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux (ROT13.o, chiffrage.a, test, etc.).
build/$(OS_NAME):
	mkdir -p build/$(OS_NAME)

# Bibliothèque de chiffrage. Quatre cibles, trois pour compiler les codes de chiffrage en fichiers objets (ROT13.o, etc.) et 
# une pour les lier en bibliothèque statique (libchiffrage.a).
build/$(OS_NAME)/ROT13.o: lib/ROT13.c | build/$(OS_NAME)
	$(cc) -Wall -pedantic -g -c lib/ROT13.c -I ./lib -o build/$(OS_NAME)/ROT13.o

build/$(OS_NAME)/libchiffrage.a: build/$(OS_NAME)/ROT13.o | build/$(OS_NAME)
	ar crs build/$(OS_NAME)/libchiffrage.a build/$(OS_NAME)/ROT13.o

# Programme de test. Trois cibles, une pour compiler le code de test en fichier objet, une pour lier le fichier objet avec 
# la bibliothèque statique de chiffrage et une dernière de "commodité" pour faire plus court à l'invite de commandes.
build/$(OS_NAME)/test.o: test/main.c | build/$(OS_NAME)
	$(cc) -Wall -pedantic -g -c test/main.c -I ./lib -o build/$(OS_NAME)/test.o

build/$(OS_NAME)/test: build/$(OS_NAME)/test.o build/$(OS_NAME)/libchiffrage.a | build/$(OS_NAME)
	$(cc) build/$(OS_NAME)/test.o -Lbuild/$(OS_NAME) -lchiffrage -o build/$(OS_NAME)/test

test: build/$(OS_NAME)/test
