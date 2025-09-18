#include <stdio.h>
#include <assert.h>
#include <TXLib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "structNovelFunctions.h"
#include "stringsFunctions.h"
#include "textStructs.h"
#include "sorts.h"
#include "helpingFunctions.h"

char* copyFileContent (struct novel* structAddress, const char* fileName) {
    assert(fileName);

    int fileDescriptor = open(fileName, O_RDONLY, 0);
    if (fileDescriptor == -1) {
        fprintf(stderr, "Error of opening file \"%s\"", fileName);
        perror("");
        return NULL;
    }

    ssize_t sizeOfFile = getSizeOfFile(fileDescriptor);
    if (sizeOfFile < 1) {
        close(fileDescriptor);
        return NULL;
    }

    char* fileCopyBuffer = (char*)calloc(sizeOfFile + 1, sizeof(char));

    size_t numOfReadSymbols = read(fileDescriptor, fileCopyBuffer, sizeOfFile);
    fileCopyBuffer[numOfReadSymbols] = '\0';

    if(close(fileDescriptor) != 0) {
        fprintf(stderr, "Error of closing file \"%s\"", fileName);
        perror("");
        return NULL;
    }

    structAddress->sizeOfText = numOfReadSymbols;

    return fileCopyBuffer;
}

void getStructNovel (struct novel* structAddress, const char* fileName) {
    assert(structAddress);
    assert(fileName);

    char* buffer = copyFileContent(structAddress, fileName);
    assert(buffer);

    size_t numberOfStrings    = getNumberOfSymbols(buffer, '\n');
    char** arrOfPtrsToStrings = (char**)calloc(numberOfStrings, sizeof(*arrOfPtrsToStrings));

    structAddress->text               = buffer;
    structAddress->numberOfStrings    = numberOfStrings;

    getArrOfStringStructs(structAddress);

}

void getArrOfStringStructs (struct novel* structAddress) {
    assert(structAddress);

    structAddress->arrOfStringStructs = (struct line*)calloc(structAddress->numberOfStrings, sizeof(struct line));
    size_t line = 0;
    (structAddress->arrOfStringStructs[line]).ptrToString = structAddress->text;
    (structAddress->arrOfStringStructs[line]).lengthOfString = myStrlen((structAddress->arrOfStringStructs[line]).ptrToString) + 1;
    line++;

    size_t numOfCharInText = 0;
    for( ; (structAddress->text[numOfCharInText] != '\0') && (line < structAddress->numberOfStrings) ; numOfCharInText++) {

        if (structAddress->text[numOfCharInText] == '\n') {
            (structAddress->arrOfStringStructs[line]).ptrToString = structAddress->text + numOfCharInText + 1;
            line++;
        }
    }

    getLengthOfStrings(structAddress);
}

void getLengthOfStrings (struct novel* structAddress) {
    assert(structAddress);

    for(size_t line = 0; line < structAddress->numberOfStrings - 1; line++)
        (structAddress->arrOfStringStructs[line]).lengthOfString = (size_t)((structAddress->arrOfStringStructs[line+1]).ptrToString - (structAddress->arrOfStringStructs[line]).ptrToString);

    (structAddress->arrOfStringStructs[structAddress->numberOfStrings - 1]).lengthOfString = myStrlen((structAddress->arrOfStringStructs[structAddress->numberOfStrings - 1]).ptrToString) + 1;
}

void fwriteNovel (struct novel nameOfNovel, FILE* file) {
    assert(file);

    for(size_t line = 0; line < nameOfNovel.numberOfStrings; line++) {
        assert(((nameOfNovel.arrOfStringStructs)[line]).ptrToString);
        myFputs(((nameOfNovel.arrOfStringStructs)[line]).ptrToString, file);
    }
}

void fwriteNovelAlphabetically (struct novel* structAddress, FILE* file) {
    assert(structAddress);
    assert(file);

    stringsBubbleSort(structAddress, &myStrcmp);

    fputs("FOR SCIENTISTS ONLY:\n\n", file);
    fwriteNovel (*structAddress, file);
    fputs("------------------------------------------------------------------\n\n\n", file);
}

void fwriteNovelAlphabeticallyFromEnd (struct novel* structAddress, FILE* file) {
    assert(structAddress);
    assert(file);

    qsort(structAddress->arrOfStringStructs, structAddress->numberOfStrings, sizeof(struct line), &reversedMyStrcmp);

    fputs("FOR RAPPERS ONLY:\n\n", file);
    fwriteNovel (*structAddress, file);
    fputs("--------------------------------------------------------------------\n\n\n", file);
}

void fwriteNovelOriginal (struct novel novelName, FILE* file) {
    assert(file);
    assert(novelName.text);

    fputs("IMPERISHABLE CLASSIC:\n\n", file);
    fputs(novelName.text, file);
}
