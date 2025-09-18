#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "arrayFunctions.h"
#include "arrOfStringsFunctions.h"
#include "bestOneginReader.h"
#include "textStructs.h"
#include "sorts.h"



int main (void) {


    struct novel Onegin = {};
    getStructNovel2 (&Onegin,"Onegin.txt");
/*
    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == (", i);
        myPuts((Onegin.arrOfStringStructs[i]).ptrToString);
        printf(") length == %d\n", (Onegin.arrOfStringStructs[i]).lengthOfString);
    }

    stringsBubbleSort(&Onegin, &myStrcmp3);
    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == (", i);
        myPuts((Onegin.arrOfStringStructs[i]).ptrToString);
        printf(") length == %d\n", (Onegin.arrOfStringStructs[i]).lengthOfString);
    }
*/
    qsort(Onegin.arrOfStringStructs, Onegin.numberOfStrings, sizeof(struct line), &reversedMyStrcmp2);

    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == (", i);
        myPuts((Onegin.arrOfStringStructs[i]).ptrToString);
        printf(") length == %d\n", (Onegin.arrOfStringStructs[i]).lengthOfString);
    }

    free(Onegin.text);
    free(Onegin.arrOfStringStructs);
    return 0;

}

