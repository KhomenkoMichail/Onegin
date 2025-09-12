#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

void fillingSquareArr (int* array, size_t sizeY, size_t sizeX);

void printSquareArr (int* array, size_t sizeY, size_t sizeX);

int sumSquareArr (int* array, size_t sizeY, size_t sizeX);

int* findNumInSquareArr (int* array, size_t sizeY, size_t sizeX, int requiredNumber);

void fillingTriangularArr (int* array, size_t sizeOfArr);

void printTriangularArr (int* array, size_t sizeOfArr);

void fillingArrOfPtr (char* arrayOfPtr[], size_t numOfPtr);

void printArrOfPtr (char* arrayOfPtr[], size_t numOfPtr);

void freeArrOfPtr (char* arrayOfPtr[], size_t numOfPtr);

void reverseArrOfPtr (char** arrayOfPtr, size_t numOfPtr);

#endif
