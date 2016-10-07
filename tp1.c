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
void test_single_args(char *str1, char *str2);

int main(int argc, char *argv[]) {
    test_argc(argc);
    test_single_args(argv[1],argv[2]);
}

void test_argc(int argc){
    if (argc < 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
    }
}

void test_single_args(char *str1, char *str2){
    if (strcmp(str1,str2) == 0){
        printf("Les codes doivent etre distincts\n");
    }
}

