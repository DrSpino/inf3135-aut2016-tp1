#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// ---------- //
// Constants  //
// ---------- //

#define EMPTY_CHAR '-'
#define HEIGHT_MAX 15
#define WIDTH_MAX 20

// --------------------- //
//    DATA STRUCTURES    //
// --------------------- //

typedef struct ArrayHeights {
    unsigned int width;
    int content[WIDTH_MAX + 1];
} ArrayHeights;

typedef struct Mountain {
    unsigned int HEIGHT;
    unsigned int WIDTH;
    char content[WIDTH_MAX][HEIGHT_MAX];
} Mountain;

// ---------- //
// Prototypes //
// ---------- //

void checkArgc(int argc);
void isWaterAndDirtDifferent(char *dirt, char *water);
void isSingleArg(char *s);
void isArrayHeightsValid(ArrayHeights array_heights);
int toString(char []);
void createArrayHeights(ArrayHeights array_heights,char *str);

int main(int argc, char *argv[]) {
    checkArgc(argc);
    isWaterAndDirtDifferent(argv[1],argv[2]);
    isSingleArg(argv[1]);
    isSingleArg(argv[2]);

    ArrayHeights array_heights;

    createArrayHeights(array_heights, argv[argc-1]);
    //isArrayHeightsValid(array_heights);
}

void checkArgc(int argc){
    if (argc < 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
        exit(1);
    }
}

void isWaterAndDirtDifferent(char *dirt, char *water){
    if (strcmp(dirt,water) == 0){
        printf("Les codes doivent etre distincts\n");
        exit(1);
    }
}

void isSingleArg(char *s){
    if (strlen(s) != 1){
        printf("Code %s invalide: il doit etre un caractere unique\n",s);
        exit(1);
    }
}
void isArrayHeightsValid(ArrayHeights array_heights){
    unsigned int i;
    for (i = 0; i < array_heights.width; i++){
        printf("%d\n",array_heights.content[i]);
        }
}

int toString(char a[]) {
  int c, sign, offset, n;
 
  if (a[0] == '-') {
    sign = -1;
  }
 
  if (sign == -1) {
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}


void createArrayHeights(ArrayHeights array_heights,char *str){
    const char s[2] = ",";
    char *token;
    int index = 0;

    token = strtok(str,s);
    while (token != NULL){
        if (toString(token) < 0 || toString(token) > 15){
            printf("Hauteur invalide: la hauteur doit etre un nombre entre 0 et %d\n",HEIGHT_MAX);\
            exit(1);
        }
        array_heights.content[index] = toString(token);
        printf("%d\n",array_heights.content[index]);
        index++;
        token = strtok(NULL,s);
    }
    array_heights.width = index;
}
