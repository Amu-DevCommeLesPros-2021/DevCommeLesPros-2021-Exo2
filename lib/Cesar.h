#pragma once

// Chiffre et déchiffre une chaîne de caractères suivant l'algorithme décrit ici: https://fr.wikipedia.org/wiki/Chiffrement_par_d%C3%A9calage.
// La clé doit être un caractère compris entre 'a' et 'z'.
// La fonction modifie la chaîne de caractères donnée.
// Seuls les caractères de 'a' à 'z' et de 'A' à 'Z' de la chaîne seront chiffrés ou déchiffrés.
// Retourne un pointeur au début de la chaîne.
char* chiffre_Cesar(char* clair, char const cle);
char* dechiffre_Cesar(char* chiffre, char const cle);
