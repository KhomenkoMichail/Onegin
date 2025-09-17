#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "arrayFunctions.h"
#include "stringsFunctions.h"

void fillingSquareArr (int* array, size_t sizeY, size_t sizeX) {
    assert(array);

    for (size_t y = 0; y < sizeY; y++)
        for (size_t x = 0; x < sizeX; x++)
            scanf("%d", ((int* )array + y*sizeX + x));
}

void printSquareArr (int* array, size_t sizeY, size_t sizeX) {
    assert(array);

    for (size_t y = 0; y < sizeY; y++) {
        for (size_t x = 0; x < sizeX; x++)
            printf("[%d][%d] = %d  ", y, x, *((int* )array + y*sizeX + x));
        putchar('\n');
    }
}

int sumSquareArr (int* array, size_t sizeY, size_t sizeX) {
    assert(array);

    int sum = 0;
    for (size_t y = 0; y < sizeY; y++)
        for (size_t x = 0; x < sizeX; x++)
            sum += *((int*)array + y*sizeX + x);

    return sum;
}

int* findNumInSquareArr (int* array, size_t sizeY, size_t sizeX, int requiredNumber) {
    assert(array);
    int* pointerToRequiredNumber = NULL;

    for (size_t y = 0; y < sizeY; y++)
        for (size_t x = 0; x < sizeX; x++)
            if (*((int*)array + y*sizeX + x) == requiredNumber)
                pointerToRequiredNumber = ((int*)array + y*sizeX + x);

    return pointerToRequiredNumber;
}

void fillingTriangularArr (int* array, size_t sizeOfArr) {
    assert(array);

    size_t sizeY = (-1 + (size_t)sqrt(1 + 8*sizeOfArr))/2;
    size_t sizeX = 0;
    for (size_t y = 0; y < sizeY; y++) {
        sizeX++;
        for (size_t x = 0; x < sizeX; x++)
            scanf("%d", ((int*)array + (1+y)*y/2 + x));
    }
}

void printTriangularArr (int* array, size_t sizeOfArr) {
    assert(array);

    size_t sizeY = (-1 + (size_t)sqrt(1 + 8*sizeOfArr))/2;
    size_t sizeX = 0;
    for (size_t y = 0; y < sizeY; y++) {
        sizeX++;
        for (size_t x = 0; x < sizeX; x++)
            printf("[%d][%d] = %d  ", y, x, *((int*)array + (1+y)*y/2 + x));
        putchar('\n');
    }
}

void fillingArrOfPtr (char** arrayOfPtr, size_t numOfPtr) {
    assert (arrayOfPtr);

    for (size_t string = 0; string < numOfPtr; string++) {
        size_t sizeOfString = 1;
        myGetline(&(arrayOfPtr[string]), &sizeOfString, stdin);
        printf ("size of [%d] = %d\n", string, sizeOfString);
    }
}

void printArrOfPtr (char** arrayOfPtr, size_t numOfPtr) {
    assert (arrayOfPtr);

    for (size_t string = 0; string < numOfPtr; string++) {
        printf ("[%d] = ", string);
        myPuts(arrayOfPtr[string]);
    }
}

void freeArrOfPtr (char* arrayOfPtr[], size_t numOfPtr) {
    assert (arrayOfPtr);

    for (size_t string = 0; string < numOfPtr; string++) {
        free(arrayOfPtr[string]);
    }
}

void reverseArrOfPtr (char** arrayOfPtr, size_t numOfPtr) {
    assert (arrayOfPtr);

    char* ptr = NULL;
    for (size_t string = 0; string < (numOfPtr/2); string++) {
        ptr = arrayOfPtr[string];
        arrayOfPtr[string] = arrayOfPtr[numOfPtr - string -1];
        arrayOfPtr[numOfPtr - string - 1] = ptr;
    }
}
