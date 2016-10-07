#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// ---------- //
// Constantes //
// ---------- //

#define CARACTERE_VIDE '-'
#define HAUTEUR_MAX 15
#define LARGEUR_MAX 20

void test_argc(int argc);

int main(int argc, char *argv[]) {
    test_argc(argc);
}

void test_argc(int argc){
    if (argc < 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
    }
}   

