#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "helpingFunctions.h"
#include "textStructs.h"
#include "structNovelFunctions.h"
#include "textStructs.h"

void supportEndOfProgram (struct novel* structAddress, FILE* file) {
    assert(structAddress);
    assert(file);

    if (fclose(file) != 0)
        perror("Error of getting the size of the file");

    free(structAddress->text);
    free(structAddress->arrOfStringStructs);
}

ssize_t getSizeOfFile (int fileDescriptor) {
    struct stat fileInfo = {};

    if (fstat(fileDescriptor, &fileInfo) == 0)
        return fileInfo.st_size;

    perror("Error of getting the size of the file");
    return -1;
}

size_t getNumberOfSymbols (char* text, char searchedSymbol) {
    assert(text);

    size_t numOfSymbolsFound = 0;
    for(size_t numOfChar = 0; text[numOfChar] != '\0'; numOfChar++)
        if (text[numOfChar] == searchedSymbol)
            numOfSymbolsFound++;

    return numOfSymbolsFound;
}

FILE* fillTheFile (struct novel* structAddress, const char* nameOfFile) {
    assert(structAddress);
    assert(nameOfFile);

    FILE* file = fopen("result.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error of opening file \"%s\"", nameOfFile);
        perror("");
        return NULL;
    }

    fwriteNovelAlphabetically(structAddress, file);
    fwriteNovelAlphabeticallyFromEnd(structAddress, file);
    fwriteNovelOriginal(*structAddress, file);

    return file;
}


