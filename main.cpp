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



int main (void) {


    struct novel Onegin = {};
    getStructNovel2 (&Onegin,"Onegin.txt");

    FILE* file = fopen("result.txt", "w");

    fwriteNovelAlphabetically(&Onegin, file);
    fwriteNovelAlphabeticallyFromEnd(&Onegin, file);
    fwriteNovelOriginal(Onegin, file);

    fclose(file);
    free(Onegin.text);
    free(Onegin.arrOfStringStructs);
    return 0;

}

