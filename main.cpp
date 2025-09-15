#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "arrayFunctions.h"
#include "arrOfStringsFunctions.h"
#include "bestOneginReader.h"
#include "textStructs.h"


int main (void) {
/*
    char text1[270][40] = {};
    getSquareStringArr(text1, 270, 40, "OriginalOnegin.txt");
    printSquareStringArr(text1, 270);
    swapStringContents(text1[1], text1[2]);
    printSquareStringArr(text1, 270);
*/

/*
    char* text [10] = {};
    badGetArrOfPtr(text, 10, "OriginalOnegin.txt");
    for(int i = 0; i < 10; i++)
        printf("[%d] = %p\n", i, text[i]);
    printArrOfPtr(text, 10);
*/

/*
    goodGetArrOfPtr(text, 10, "OriginalOnegin.txt");
    for(int i = 0; i < 10; i++)
        printf("[%d] = %p\n", i, text[i]);
    printArrOfPtr(text, 10);
*/
    struct novel Onegin;

    getStructNovel (&Onegin, "OriginalOnegin.txt");
    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == ", i);
        myPuts(Onegin.arrOfPtrsToStrings[i]);
        putchar('\n');}
    free(Onegin.text);
    free(Onegin.arrOfPtrsToStrings);

    return 0;
}

