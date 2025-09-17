#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "arrOfStringsFunctions.h"
#include "stringsFunctions.h"

void getSquareStringArr (char textArr[][40], size_t numOfLines, size_t lengthOfLines, const char* pathToFile) {
    assert(textArr);

    FILE* file = fopen(pathToFile, "r");
    assert(file);

    for (size_t line = 0; line < numOfLines; line++)
        fgets (textArr[line], lengthOfLines, file);

    fclose(file);
}

void printSquareStringArr (char textArr[][40], size_t numOfLines) {
    assert(textArr);

    for(size_t line = 0; line < numOfLines; line++) {
        printf("[%d] = ", line);
        myPuts(textArr[line]);
        putchar('\n');
    }
}

void badGetArrOfPtr(char* arrOfPtr[], size_t numOfLines, const char* pathToFile) {
    assert(arrOfPtr);

    FILE* file = fopen(pathToFile, "r");
    assert(file);
    char str[40] = {};

    for(size_t line = 0; line < numOfLines; line++) {
        fgets(str, 40, file);
        arrOfPtr[line] = str;
    }
    fclose(file);
}

void goodGetArrOfPtr(char* arrOfPtr[], size_t numOfLines, const char* pathToFile) {
    assert(arrOfPtr);

    FILE* file = fopen(pathToFile, "r");
    assert(file);

    for(size_t line = 0; line < numOfLines; line++) {
        char str[40] = {};
        fgets(str, 39, file);
        arrOfPtr[line] = myStrdup(str);
    }
    fclose(file);
}
