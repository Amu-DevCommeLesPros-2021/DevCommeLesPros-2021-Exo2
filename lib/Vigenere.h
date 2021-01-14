#pragma once

#include <stdio.h>

// Chiffre et déchiffre une chaîne de caractères suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/Chiffre_de_Vigen%C3%A8re.
// La clé doit être une chaîne de caractères compris entre 'a' et 'z'.
// La fonction modifie la chaîne de caractères donnée.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
// Retourne un pointeur au début de la chaîne.
char* chiffre_Vigenere(
    char* clair,        // Texte en clair qui sera modifié.
    char const* cle);

char* dechiffre_Vigenere(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const* cle);

// Chiffre et déchiffre un flux de texte vers un autre flux.
// L'implémentation et les restrictions sont les mêmes que (de)chiffre_Vigenere.
void chiffre_Vigenere_flux_texte(
    FILE* chiffre,      // Flux de sortie.
    FILE* clair,        // Flux d'entrée.
    char const* cle);
void dechiffre_Vigenere_flux_texte(
    FILE* clair,        // Flux de sortie.
    FILE* chiffre,      // Flux d'entrée.
    char const* cle);
