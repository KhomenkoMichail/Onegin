#include <stdio.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "sorts.h"
#include "textStructs.h"

typedef int (*comparefunc_t)(const struct line str1, const struct line str2);

void intBubbleSort (int* arr, size_t sizeOfArr) {
    assert(arr);

    for(unsigned int numOfCycle = 0; numOfCycle < sizeOfArr; numOfCycle++)
        for (size_t numOfChar = 0; numOfChar < (sizeOfArr - numOfCycle); numOfChar++) {
            if (arr[numOfChar] > arr[numOfChar + 1]) {
                int cell = arr[numOfChar];
                arr[numOfChar] = arr[numOfChar + 1];
                arr[numOfChar + 1] = cell;
            }
        }
}
/*
void stringsBubbleSort (struct novel* structAddress, comparefunc_t compareFuncAddress) {
    assert(structAddress);

    for(unsigned int numOfCycle = 0; numOfCycle < structAddress->numberOfStrings; numOfCycle++)

        for (size_t numOfPtr = 0; numOfPtr < (structAddress->numberOfStrings - numOfCycle - 1); numOfPtr++) {

            assert((structAddress->arrOfPtrsToStrings)[numOfPtr]);
            assert((structAddress->arrOfPtrsToStrings)[numOfPtr + 1]);

            if ((*compareFuncAddress)((structAddress->arrOfPtrsToStrings)[numOfPtr], (structAddress->arrOfPtrsToStrings)[numOfPtr + 1]) > 0) {
                char* cell = (structAddress->arrOfPtrsToStrings)[numOfPtr];
                (structAddress->arrOfPtrsToStrings)[numOfPtr] = (structAddress->arrOfPtrsToStrings)[numOfPtr + 1];
                (structAddress->arrOfPtrsToStrings)[numOfPtr + 1] = cell;
            }
        }
}

*/

void stringsBubbleSort (struct novel* structAddress, comparefunc_t compareFuncAddress) {
    assert(structAddress);

    for(unsigned int numOfCycle = 0; numOfCycle < structAddress->numberOfStrings; numOfCycle++)

        for (size_t numOfPtr = 0; numOfPtr < (structAddress->numberOfStrings - numOfCycle - 1); numOfPtr++) {

            assert(((structAddress->arrOfStringStructs)[numOfPtr]).ptrToString);
            assert(((structAddress->arrOfStringStructs)[numOfPtr + 1]).ptrToString);

            if ((*compareFuncAddress)((structAddress->arrOfStringStructs)[numOfPtr], (structAddress->arrOfStringStructs)[numOfPtr + 1]) > 0) {
                struct line cell = (structAddress->arrOfStringStructs)[numOfPtr];
                (structAddress->arrOfStringStructs)[numOfPtr] = (structAddress->arrOfStringStructs)[numOfPtr + 1];
                (structAddress->arrOfStringStructs)[numOfPtr + 1] = cell;
            }
        }
}
