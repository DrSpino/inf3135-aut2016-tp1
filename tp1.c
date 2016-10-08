// ----------------------------------------------------------------------//
// Copyright [2016] [istvan Szalai szalai972@gmail.com]
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//----------------------------------------------------------------------//

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

/*Structure for easier manipulation on the last arguments see@ argv[argc-1]*/
typedef struct ArrayHeights {
    unsigned int width;
    int content[WIDTH_MAX + 1];
} ArrayHeights;

/*Structure for mountain creation, manipulation and display*/
typedef struct Mountain {
    unsigned int height;
    unsigned int width;
    char content[WIDTH_MAX][HEIGHT_MAX];
} Mountain;

// ---------- //
// Prototypes //
// ---------- //

/**
* display an error message and close the program if the 
* number of arguments passed to main is different of 3;    
*
* @param    int argc [number of arguments passed to main dunction] 
*/
void checkArgc(int argc);

/**
* display an error message and close the program if the 
* the first and second argument passed to the main function
* are the same.    
*
* @param    char *dirt [char pointer on first main argument]
* @param    char *water [char pointer on second main argument]
*/
void isWaterAndDirtDifferent(char *dirt, char *water);

/**
* display an error message and close the program if the @param
* has a lenght > 1.  
*
* @param    char *s [char pointer]
*/
void isSingleArg(char *s);

/**
* display an error message and close the program if 
* the lenght of the param is > WIDTH_MAX.    
*
* @param    int argc [length of ] 
* @see      WIDTH_MAX
*/
void isArrayHeightsValid(unsigned int  width);

/**
* Convert as much as possible an array of char to the associated integer.
*
* @param    char a[] [an array of char]
* @return   return the integer equivalent of @param 
*/
int toString(char a[]);

/**
* Add water according to the specs to a Mountain struct.   
*
* @param    Mountain* mountain [pointer of a mountain struct]
* @param    ArrayHeights* array_heights [pointer of an ArrayHeights struc]
* @param    char water  [char that is used to represent water]
* @param    char dirt   [char that is used to represent dirt]
*/
void addWater(Mountain* mountain, ArrayHeights* array_heights, char water, char dirt);

/**
* display an error message and close the program.    
*
* @param   ArrayHeights array_heights [copy of an ArrayHeights struct]  
* @return  [return the max value of in ArrayHeights.content]
*/
int getArrayHeightsMax(ArrayHeights array_heights);

/**
* display an error message and close the program.    
*
* @param  int argc [number of arguments passed to main dunction]
* @param  
* @return      the image at the specified URL
*/
void createArrayHeights(ArrayHeights* array_heights,char *str);

/**
* display an error message and close the program.    
*
* @param  int argc [number of arguments passed to main dunction]
* @param  
*/
void createMountain(Mountain* mountain, ArrayHeights array_heights, char dirt);

/**
* display mountain.content and close teh program.    
*
* @param  Mountain mountain [a copy of a Mountain structure]
*/
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