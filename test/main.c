#include "chiffrage.h"

#include "test_harness/test_harness.h"

#include <stdlib.h>
#include <string.h>

// Valeurs pour le harnais de test spécifiques à ce programme.
int const tests_total = 68;
int const test_column_width = 80;

int main()
{
    char clair[128];

    // Tests chiffre_ROT13
    strcpy(clair, "a");
    TEST(strcmp(chiffre_ROT13(clair), "n") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_ROT13(clair), "nopqrstuvwxyzabcdefghijklm") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_ROT13(clair), "nOpqRStuvWXYzabcDEFGhIjKlM") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_ROT13(clair), "N, n.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_ROT13(clair), "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.") == 0);

    // Tests dechiffre_ROT13.
    strcpy(clair, "n");
    TEST(strcmp(dechiffre_ROT13(clair), "a") == 0);
    strcpy(clair, "nopqrstuvwxyzabcdefghijklm");
    TEST(strcmp(dechiffre_ROT13(clair), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "nOpqRStuvWXYzabcDEFGhIjKlM");
    TEST(strcmp(dechiffre_ROT13(clair), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "N, n.");
    TEST(strcmp(dechiffre_ROT13(clair), "A, a.") == 0);
    strcpy(clair, "Wr ynvffr zrf ovraf à zn fbrhe ? Aba ! À zba arirh. Wnznvf fren cnlé yr pbzcgr qh gnvyyrhe. Evra nhk cnhierf.");
    TEST(strcmp(dechiffre_ROT13(clair), "Je laisse mes biens à ma soeur ? Non ! À mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.") == 0);


    // Test chiffre_Cesar.
    strcpy(clair, "a");
    TEST(strcmp(chiffre_Cesar(clair, 'a'), "a") == 0);
    strcpy(clair, "a");
    TEST(strcmp(chiffre_Cesar(clair, 'c'), "c") == 0);
    strcpy(clair, "a");
    TEST(strcmp(chiffre_Cesar(clair, 'z'), "z") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Cesar(clair, 'c'), "cdefghijklmnopqrstuvwxyzab") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Cesar(clair, 'z'), "zabcdefghijklmnopqrstuvwxy") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Cesar(clair, 'c'), "cDefGHijkLMNopqrSTUVwXyZaB") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Cesar(clair, 'z'), "zAbcDEfghIJKlmnoPQRStUvWxY") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Cesar(clair, 'a'), "A, a.") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Cesar(clair, 'c'), "C, c.") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Cesar(clair, 'z'), "Z, z.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Cesar(clair, 'c'), "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Cesar(clair, 'z'), "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.") == 0);

    // Tests dechiffre_Cesar.
    strcpy(clair, "a");
    TEST(strcmp(dechiffre_Cesar(clair, 'a'), "a") == 0);
    strcpy(clair, "c");
    TEST(strcmp(dechiffre_Cesar(clair, 'c'), "a") == 0);
    strcpy(clair, "z");
    TEST(strcmp(dechiffre_Cesar(clair, 'z'), "a") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(dechiffre_Cesar(clair, 'a'), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "cdefghijklmnopqrstuvwxyzab");
    TEST(strcmp(dechiffre_Cesar(clair, 'c'), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "zabcdefghijklmnopqrstuvwxy");
    TEST(strcmp(dechiffre_Cesar(clair, 'z'), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(dechiffre_Cesar(clair, 'a'), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "cDefGHijkLMNopqrSTUVwXyZaB");
    TEST(strcmp(dechiffre_Cesar(clair, 'c'), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "zAbcDEfghIJKlmnoPQRStUvWxY");
    TEST(strcmp(dechiffre_Cesar(clair, 'z'), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(dechiffre_Cesar(clair, 'a'), "A, a.") == 0);
    strcpy(clair, "C, c.");
    TEST(strcmp(dechiffre_Cesar(clair, 'c'), "A, a.") == 0);
    strcpy(clair, "Z, z.");
    TEST(strcmp(dechiffre_Cesar(clair, 'z'), "A, a.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(dechiffre_Cesar(clair, 'a'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Lg nckuug ogu dkgpu à oc uqgwt. Pqp à oqp pgxgw. Lcocku ugtc rcaé ng eqorvg fw vcknngwt. Tkgp cwz rcwxtgu.");
    TEST(strcmp(dechiffre_Cesar(clair, 'c'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Id kzhrrd ldr ahdmr à lz rndtq. Mnm à lnm mdudt. Izlzhr rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");
    TEST(strcmp(dechiffre_Cesar(clair, 'z'), "Je laisse mes biens à ma soeur. Non à mon neveu. Jamais sera payé le compte du tailleur. Rien aux pauvres.") == 0);


    // Tests chiffre_Vigenere.
    strcpy(clair, "a");
    TEST(strcmp(chiffre_Vigenere(clair, "a"), "a") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Vigenere(clair, "a"), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Vigenere(clair,"abc"), "acedfhgikjlnmoqprtsuwvxzya") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(chiffre_Vigenere(clair,"zzz"), "zabcdefghijklmnopqrstuvwxy") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Vigenere(clair, "a"), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Vigenere(clair, "abc"), "aCedFHgikJLNmoqpRTSUwVxZyA") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(chiffre_Vigenere(clair, "zzz"), "zAbcDEfghIJKlmnoPQRStUvWxY") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Vigenere(clair, "a"), "A, a.") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Vigenere(clair, "abc"), "A, b.") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(chiffre_Vigenere(clair, "zzz"), "Z, z.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Vigenere(clair, "a"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Vigenere(clair, "abc"), "Jf najusf oet difps à nc spgus ? Poo ! À ooo pewgu ? Kcmbks ! Tgrb razé ne dqmqve ew tbklmgus. Tifp avz pbwvsgs.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(chiffre_Vigenere(clair, "zzz"), "Id kzhrrd ldr ahdmr à lz rndtq ? Mnm ! À lnm mdudt ? Izlzhr ! Rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.") == 0);

    // Tests dechiffre_Vigenere.
    strcpy(clair, "a");
    TEST(strcmp(dechiffre_Vigenere(clair, "a"), "a") == 0);
    strcpy(clair, "abcdefghijklmnopqrstuvwxyz");
    TEST(strcmp(dechiffre_Vigenere(clair, "a"), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "acedfhgikjlnmoqprtsuwvxzya");
    TEST(strcmp(dechiffre_Vigenere(clair,"abc"), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "zabcdefghijklmnopqrstuvwxy");
    TEST(strcmp(dechiffre_Vigenere(clair,"zzz"), "abcdefghijklmnopqrstuvwxyz") == 0);
    strcpy(clair, "aBcdEFghiJKLmnopQRSTuVwXyZ");
    TEST(strcmp(dechiffre_Vigenere(clair, "a"), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "aCedFHgikJLNmoqpRTSUwVxZyA");
    TEST(strcmp(dechiffre_Vigenere(clair, "abc"), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "zAbcDEfghIJKlmnoPQRStUvWxY");
    TEST(strcmp(dechiffre_Vigenere(clair, "zzz"), "aBcdEFghiJKLmnopQRSTuVwXyZ") == 0);
    strcpy(clair, "A, a.");
    TEST(strcmp(dechiffre_Vigenere(clair, "a"), "A, a.") == 0);
    strcpy(clair, "A, b.");
    TEST(strcmp(dechiffre_Vigenere(clair, "abc"), "A, a.") == 0);
    strcpy(clair, "Z, z.");
    TEST(strcmp(dechiffre_Vigenere(clair, "zzz"), "A, a.") == 0);
    strcpy(clair, "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.");
    TEST(strcmp(dechiffre_Vigenere(clair, "a"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Jf najusf oet difps à nc spgus ? Poo ! À ooo pewgu ? Kcmbks ! Tgrb razé ne dqmqve ew tbklmgus. Tifp avz pbwvsgs.");
    TEST(strcmp(dechiffre_Vigenere(clair, "abc"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.") == 0);
    strcpy(clair, "Id kzhrrd ldr ahdmr à lz rndtq ? Mnm ! À lnm mdudt ? Izlzhr ! Rdqz ozxé kd bnlosd ct szhkkdtq. Qhdm ztw oztuqdr.");
    TEST(strcmp(dechiffre_Vigenere(clair, "zzz"), "Je laisse mes biens à ma soeur ? Non ! À mon neveu ? Jamais ! Sera payé le compte du tailleur. Rien aux pauvres.") == 0);


    // Tests chiffre_Vigenere_flux_texte.
    FILE *fichier_resultat = fopen("build/resultat.txt", "w");
    FILE *fichier_clair = fopen("test/clair.txt", "r");
    chiffre_Vigenere_flux_texte(fichier_resultat, fichier_clair, "agatha");
    fclose(fichier_clair);
    fclose(fichier_resultat);
    TEST_FILE("build/resultat.txt", "test/chiffre.txt");

    // Tets dechiffre_Vigenere_flux_texte.
    fichier_resultat = fopen("build/resultat.txt", "w");
    FILE *fichier_chiffre = fopen("test/chiffre.txt", "r");
    dechiffre_Vigenere_flux_texte(fichier_resultat, fichier_chiffre, "agatha");
    fclose(fichier_chiffre);
    fclose(fichier_resultat);
    TEST_FILE("build/resultat.txt", "test/clair.txt");

    return tests_total - tests_successful;
}
