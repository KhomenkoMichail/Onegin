#include <stdio.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "sorts.h"
#include "textStructs.h"

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

void stringsBubbleSort (struct novel* structAddress) {
    assert(structAddress);

    for(unsigned int numOfCycle = 0; numOfCycle < structAddress->numberOfStrings; numOfCycle++)
        for (size_t numOfPtr = 0; numOfPtr < (structAddress->numberOfStrings - numOfCycle - 1); numOfPtr++) {
            assert((structAddress->arrOfPtrsToStrings)[numOfPtr]);
            assert((structAddress->arrOfPtrsToStrings)[numOfPtr + 1]);

            if (myStrcmp2((structAddress->arrOfPtrsToStrings)[numOfPtr], (structAddress->arrOfPtrsToStrings)[numOfPtr + 1]) > 0) {
                char* cell = (structAddress->arrOfPtrsToStrings)[numOfPtr];
                (structAddress->arrOfPtrsToStrings)[numOfPtr] = (structAddress->arrOfPtrsToStrings)[numOfPtr + 1];
                (structAddress->arrOfPtrsToStrings)[numOfPtr + 1] = cell;
            }
        }
}



