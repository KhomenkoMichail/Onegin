#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "arrayFunctions.h"
#include "arrOfStringsFunctions.h"
#include "bestOneginReader.h"


int main (void) {
/* TASK1
    char text1[270][40] = {};
    getSquareStringArr(text1, 270, 40, "OriginalOnegin.txt");
    printSquareStringArr(text1, 270);
    swapStringContents(text1[1], text1[2]);
    printSquareStringArr(text1, 270);
*/

/* TASK2
    char* text [10] = {};
    badGetArrOfPtr(text, 10, "OriginalOnegin.txt");
    for(int i = 0; i < 10; i++)
        printf("[%d] = %p\n", i, text[i]);
    printArrOfPtr(text, 10);
*/

/* TASK3
    goodGetArrOfPtr(text, 10, "OriginalOnegin.txt");
    for(int i = 0; i < 10; i++)
        printf("[%d] = %p\n", i, text[i]);
    printArrOfPtr(text, 10);
*/

    char* buffer = copyFileContent("OriginalOnegin.txt");
    myPuts(buffer);
    free(buffer);

    return 0;
}

