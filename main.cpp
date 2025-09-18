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

    FILE* file = fillTheFile(&Onegin, "result.txt");

    supportEndOfProgram (&Onegin, file);

    return 0;

}

