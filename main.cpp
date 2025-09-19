#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"
#include "arrayFunctions.h"
#include "arrOfStringsFunctions.h"
#include "structNovelFunctions.h"
#include "textStructs.h"
#include "sorts.h"
#include "helpingFunctions.h"


int main (void) {
    struct novel Onegin = {};
    getStructNovel(&Onegin,"Onegin.txt");

    fillTheFile(&Onegin, "result.txt");

    freeStruct(&Onegin);
    return 0;
}

