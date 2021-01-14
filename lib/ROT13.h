#pragma once

// Chiffre et déchiffre une chaîne de caractères suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/ROT13.
// La fonction modifie la chaîne de caractères donnée.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
// Retourne un pointeur au début de la chaîne.
char* chiffre_ROT13(
    char* clair);   // Texte en clair qui sera modifié.

char* dechiffre_ROT13(
    char* chiffre); // Texte chiffré qui sera modifié.
