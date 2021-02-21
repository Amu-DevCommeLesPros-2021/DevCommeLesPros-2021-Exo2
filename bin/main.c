#include "chiffrage.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char cle[1024] = {'\0'};
    bool dechiffrage = false;

    // Décodage des paramètres.
    //  -c mot  obligatoire, utilise "mot" comme clé de chiffrage ou de déchiffrage.
    //                       Longueur maximum de 1023 caractères.
    //  -d      optionnel, indique qu'il faut déchiffrer le flux d'entré. Par
    //                     défaut, le flux est chiffré.
    int opt;
    while((opt = getopt(argc, argv, "c:d")) != -1)
    {
        switch(opt)
        {
            case 'c':
                strcpy(cle, optarg);
                break;
            case 'd':
                dechiffrage = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-d] -c clé\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(!cle[0]) // Paramètre "-c clé" manquant.
    {
        fprintf(stderr, "Usage: %s [-d] -c clé\n", argv[0]);
        return EXIT_FAILURE;
    }

    if(dechiffrage)
    {
        dechiffre_Vigenere_flux_texte(stdout, stdin, cle);
    }
    else
    {
        chiffre_Vigenere_flux_texte(stdout, stdin, cle);
    }

    return EXIT_SUCCESS;
}
