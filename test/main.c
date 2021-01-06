#include "chiffrage.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Pour chaque test qui échoue, cette variable sera incrémentée de 1.
    // Le but est de la garder à 0.
    int resultat = 0;

// Compare deux chaînes de caractères a et b avec strcmp. Incrémente résultat si a est NULL ou si les deux chaînes sont différentes.
#define TEST_STR(a, b)  {                                           \
                            char *s = a;                            \
                            if((s == NULL) || (strcmp(s, b) != 0))  \
                            {                                       \
                                resultat += 1;                      \
                            }                                       \
                        }

// Compare le contenu de deux fichiers aux chemins a et b avec la commande diff. Incrémente résultat si les fichiers sont différents.
// La sortie de la commande diff est redirigé vers /dev/null uniquement pour garder ce programme complètement muet.
#define TEST_FILE(a, b) {                                                                   \
                            int const r = system("diff --text " a " " b " > /dev/null");    \
                            resultat += WEXITSTATUS(r);                                     \
                        }


    char clair[128];

    // Tests chiffre_ROT13
    strcpy(clair, "a");
    TEST_STR(chiffre_ROT13(clair), "n");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_ROT13(clair), "nopqrstuvwxyzabcdefghijklm");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_ROT13(clair), "nOpqRStuvWXYzabcDEFGhIjKlM");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_ROT13(clair), "N, n.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_ROT13(clair), "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.");

    // Tests dechiffre_ROT13.
    strcpy(clair, "n");
    TEST_STR(dechiffre_ROT13(clair), "a");
    strcpy(clair, "nopqrstuvwxyzabcdefghijklm");
    TEST_STR(dechiffre_ROT13(clair), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "nOpqRStuvWXYzabcDEFGhIjKlM");
    TEST_STR(dechiffre_ROT13(clair), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "N, n.");
    TEST_STR(dechiffre_ROT13(clair), "A, a.");
    strcpy(clair, "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.");
    TEST_STR(dechiffre_ROT13(clair), "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");


    // Test chiffre_Cesar.
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'a'), "a");
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'c'), "c");
    strcpy(clair, "a");
    TEST_STR(chiffre_Cesar(clair, 'z'), "z");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'c'), "cdefghijklmnopqrstuvwxyzab");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Cesar(clair, 'z'), "zabcdefghijklmnopqrstuvwxy");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'c'), "cDefGHijkLMNopqrSTUVwXyZaB");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Cesar(clair, 'z'), "zAbcDEfghIJKlmnoPQRStUvWxY");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'a'), "A, a.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'c'), "C, c.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Cesar(clair, 'z'), "Z, z.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'c'), "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Cesar(clair, 'z'), "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");

    // Tests dechiffre_Cesar.
    strcpy(clair, "a");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "a");
    strcpy(clair, "c");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "a");
    strcpy(clair, "z");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "a");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "cdefghijklmnopqrstuvwxyzab");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "zabcdefghijklmnopqrstuvwxy");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "cDefGHijkLMNopqrSTUVwXyZaB");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "zAbcDEfghIJKlmnoPQRStUvWxY");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "A, a.");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "A, a.");
    strcpy(clair, "C, c.");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "A, a.");
    strcpy(clair, "Z, z.");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "A, a.");
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(dechiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.");
    TEST_STR(dechiffre_Cesar(clair, 'c'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");
    TEST_STR(dechiffre_Cesar(clair, 'z'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");


    // Tests chiffre_Vigenere.
    strcpy(clair, "a");
    TEST_STR(chiffre_Vigenere(clair, "a"), "a");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Vigenere(clair, "a"), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Vigenere(clair,"abc"), "acedfhgikjlnmoqprtsuwvxzya");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(chiffre_Vigenere(clair,"zzz"), "zabcdefghijklmnopqrstuvwxy");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Vigenere(clair, "a"), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Vigenere(clair, "abc"), "aCedFHgikJLNmoqpRTSUwVxZyA");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(chiffre_Vigenere(clair, "zzz"), "zAbcDEfghIJKlmnoPQRStUvWxY");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Vigenere(clair, "a"), "A, a.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Vigenere(clair, "abc"), "A, b.");
    strcpy(clair, "A, a.");
    TEST_STR(chiffre_Vigenere(clair, "zzz"), "Z, z.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Vigenere(clair, "a"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Vigenere(clair, "abc"), "Jf najusf oet difps à nc spgus ? Poo ! À ooo pewgu ? Kcmbks ! Tgrb razé ne dqmqve ew tbklmgus. Tifp avz pbwvsgs.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(chiffre_Vigenere(clair, "zzz"), "Id kzhrrd ldr ahdmr à lz rndtq ? Mnm ! À lnm mdudt ? Izlzhr ! Rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");

    // Tests dechiffre_Vigenere.
    strcpy(clair, "a");
    TEST_STR(dechiffre_Vigenere(clair, "a"), "a");
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST_STR(dechiffre_Vigenere(clair, "a"), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "acedfhgikjlnmoqprtsuwvxzya");
    TEST_STR(dechiffre_Vigenere(clair,"abc"), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "zabcdefghijklmnopqrstuvwxy");
    TEST_STR(dechiffre_Vigenere(clair,"zzz"), "abcdefghijklmnopqrstuvwxyz");
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST_STR(dechiffre_Vigenere(clair, "a"), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "aCedFHgikJLNmoqpRTSUwVxZyA");
    TEST_STR(dechiffre_Vigenere(clair, "abc"), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "zAbcDEfghIJKlmnoPQRStUvWxY");
    TEST_STR(dechiffre_Vigenere(clair, "zzz"), "aBcdEFghiJKLmnopQRSTuVwXyZ");
    strcpy(clair, "A, a.");
    TEST_STR(dechiffre_Vigenere(clair, "a"), "A, a.");
    strcpy(clair, "A, b.");
    TEST_STR(dechiffre_Vigenere(clair, "abc"), "A, a.");
    strcpy(clair, "Z, z.");
    TEST_STR(dechiffre_Vigenere(clair, "zzz"), "A, a.");
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST_STR(dechiffre_Vigenere(clair, "a"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Jf najusf oet difps à nc spgus ? Poo ! À ooo pewgu ? Kcmbks ! Tgrb razé ne dqmqve ew tbklmgus. Tifp avz pbwvsgs.");
    TEST_STR(dechiffre_Vigenere(clair, "abc"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    strcpy(clair, "Id kzhrrd ldr ahdmr à lz rndtq ? Mnm ! À lnm mdudt ? Izlzhr ! Rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");
    TEST_STR(dechiffre_Vigenere(clair, "zzz"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");


    // Tests chiffre_Vigenere_flux_texte.
    mkdir("build/test", 0755);
    FILE *fichier_resultat = fopen("build/test/resultat.txt", "w");
    FILE *fichier_clair = fopen("test/clair.txt", "r");
    chiffre_Vigenere_flux_texte(fichier_resultat, fichier_clair, "agatha");
    fclose(fichier_clair);
    fclose(fichier_resultat);
    TEST_FILE("build/test/resultat.txt", "test/chiffre.txt");

    // Tets dechiffre_Vigenere_flux_texte.
    fichier_resultat = fopen("build/test/resultat.txt", "w");
    FILE *fichier_chiffre = fopen("test/chiffre.txt", "r");
    dechiffre_Vigenere_flux_texte(fichier_resultat, fichier_chiffre, "agatha");
    fclose(fichier_chiffre);
    fclose(fichier_resultat);
    TEST_FILE("build/test/resultat.txt", "test/clair.txt");

    return resultat;
}
