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
    unsigned int height;
    unsigned int width;
    char content[WIDTH_MAX][HEIGHT_MAX];
} Mountain;

// ---------- //
// Prototypes //
// ---------- //

void checkArgc(int argc);
void isWaterAndDirtDifferent(char *dirt, char *water);
void isSingleArg(char *s);
void isArrayHeightsValid(unsigned int  width);
int toString(char []);
void addWater(Mountain* mountain, ArrayHeights* array_heights, char water, char dirt);
int getArrayHeightsMax(ArrayHeights array_heights);
void createArrayHeights(ArrayHeights* array_heights,char *str);
void createMountain(Mountain* mountain, ArrayHeights array_heights, char dirt);
void showMountain(Mountain mountain);

int main(int argc, char *argv[]) {
    checkArgc(argc);
    isWaterAndDirtDifferent(argv[1],argv[2]);
    isSingleArg(argv[1]);
    isSingleArg(argv[2]);

    ArrayHeights array_heights;
    ArrayHeights* p_array_heights = &array_heights;
    createArrayHeights(p_array_heights, argv[argc-1]);

    isArrayHeightsValid(array_heights.width);

    char dirt = argv[1][0];
    char water = argv[2][0];

    Mountain mountain;
    Mountain* p_mountain = &mountain;
    createMountain(p_mountain,array_heights, dirt);
    addWater(p_mountain, p_array_heights, water, dirt);
    showMountain(mountain);
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
void isArrayHeightsValid(unsigned int width){
    if ( width > WIDTH_MAX){
        printf("Largeur invalide: le nombre de hauteurs doit etre entre 1 et %d\n",WIDTH_MAX);
        exit(1);
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

int getArrayHeightsMax(ArrayHeights array_heights){
    unsigned int i;
    int max = array_heights.content[0];
    for (i = 1; i < array_heights.width; i++){
        if (max < array_heights.content[i]){
            max = array_heights.content[i];
        }
    }
    return max;
}

void createArrayHeights(ArrayHeights* array_heights,char *str){
    const char s[2] = ",";
    char *token;
    unsigned int index = 0;

    token = strtok(str,s);
    while (token != NULL){
        if (toString(token) < 0 || toString(token) > 15){
            printf("Hauteur invalide: la hauteur doit etre un nombre entre 0 et %d\n",HEIGHT_MAX);\
            exit(1);
        }
        array_heights->content[index] = toString(token);
        index++;
        token = strtok(NULL,s);
    }
    array_heights->width = index;
}

void createMountain(Mountain* mountain, ArrayHeights array_heights, char dirt){
    mountain->width = array_heights.width;
    mountain->height = getArrayHeightsMax(array_heights);
    int top = getArrayHeightsMax(array_heights);
    unsigned int i,j;
    for (i=0; i< mountain->height; i++){
        for (j=0; j < mountain->width; j++) {
            if (array_heights.content[j] >= top){
            mountain->content[i][j] = dirt;
            }else{
            mountain->content[i][j] = EMPTY_CHAR;
            }
        }
        top--;
    }
}

void showMountain(Mountain mountain){
    unsigned int i,j;
    for (i = 0; i < mountain.height; i++) {
        for (j = 0; j < mountain.width; j++) {
        printf("%c",mountain.content[i][j]);
        }
        printf("\n");
    }
}

void addWater(Mountain* mountain, ArrayHeights* array_heights,char water, char dirt){
    int start = -1, end = -1;
    unsigned int i, j;
    for (i=0; i< mountain->height; i++){
        for (j=0; j < mountain->width; j++) {
            if (mountain->content[i][j] == dirt && start == -1){
                start = j;
            }else if (mountain->content[i][j] == dirt){
                end = j;
                start++;
                for(start;start<end;start++){
                    mountain->content[i][start] = water;
                }
                start = end;
            }
        }
        start = -1; end =-1;
    }
}