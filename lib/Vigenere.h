#pragma once

#include <stdio.h>

// Chiffre et déchiffre une chaîne de caractères suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/Chiffre_de_Vigen%C3%A8re.
// La clé doit être une chaîne de caractères compris entre 'a' et 'z'.
// La fonction modifie la chaîne de caractères donnée.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
// Retourne un pointeur au début de la chaîne.
char* chiffre_Vigenere(char* clair, char const* cle);
char* dechiffre_Vigenere(char* chiffre, char const* cle);

// Chiffre et déchiffre un flux de texte vers un autre flux.
// L'implémentation et les restrictions sont les mêmes que (de)chiffre_Vigenere.
void chiffre_Vigenere_flux_texte(FILE* chiffre, FILE* clair, char const* cle);
void dechiffre_Vigenere_flux_texte(FILE* clair, FILE* chiffre, char const* cle);

// Chiffre et déchiffre un flux binaire vers un autre flux.
// La clé doit être une chaîne de caractères compris entre 'a' et 'z'.
// La fonction lit le fichier avec getc et chiffre les caractères reçus un par un en les incrémentant d'une valeur donné par la clé.
// La fonction suit le même principe d'utilisation de la clé que (de)chiffre_Vigenere.
// Les caractères doivent être considérés comme de type "unsigned char". De ce fait, si la valeur
// incrémentée dépasse la valeur maximale d'un "unsigned char" (c.-à-d. 255), on doit utiliser un modulo. (e.g. 252 + 12 -> 9)
// Exemple:
// Fichier clair: [0x00, 0x01, 0x02, 0x10, 0xAB, 0xFC]
// Clé: "fil"
// Fichier chiffré: [0x05, 0x09, 0x0D, 0x15, 0xB3, 0x09]
// Explication: [0x00 + 'f' -> 0x05, 0x01 + 'i' -> 0x09, 0x02 + 'l' -> 0x0D, 0x10 + 'f' -> 0x15, 0xAB + 'i' -> 0xB3, 0xFC + 'l' -> 0x09]
void chiffre_Vigenere_flux_binaire(FILE* chiffre, FILE* clair, char const* cle);
void dechiffre_Vigenere_flux_binaire(FILE* clair, FILE* chiffre, char const* cle);
