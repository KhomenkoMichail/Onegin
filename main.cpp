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
    getStructNovel (&Onegin,"OriginalOnegin.txt");

    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == (", i);
        myPuts(Onegin.arrOfPtrsToStrings[i]);
        puts(")");
    }

    stringsBubbleSort(&Onegin, &reversedMyStrcmp);
    for(size_t i = 0; i < Onegin.numberOfStrings; i++){
        printf("[%d] == (", i);
        myPuts(Onegin.arrOfPtrsToStrings[i]);
        puts(")");
    }
    free(Onegin.text);
    free(Onegin.arrOfPtrsToStrings);
    return 0;
}

