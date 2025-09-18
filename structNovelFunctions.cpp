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

char** getPointersToStrings(char** arrOfPtr, size_t numberOfStrings, char* text) {
    assert(arrOfPtr);
    assert(text);

    size_t line = 0;
    arrOfPtr[line] = text;
    line++;

    size_t numOfCharInText = 0;
    for( ; (text[numOfCharInText] != '\0') && (line < numberOfStrings) ; numOfCharInText++)
            if (text[numOfCharInText] == '\n') {
                arrOfPtr[line] = text + numOfCharInText + 1;
                line++;
            }

    return arrOfPtr;
}
/*
void getStructNovel (struct novel* structAddress, const char* fileName) {
    assert(structAddress);
    assert(fileName);

    char* buffer = copyFileContent(structAddress, fileName);
    assert(buffer);

    size_t numberOfStrings    = getNumberOfSymbols(buffer, '\n');
    char** arrOfPtrsToStrings = (char**)calloc(numberOfStrings, sizeof(char*));

    getPointersToStrings(arrOfPtrsToStrings, numberOfStrings, buffer);

    structAddress->text               = buffer;
    structAddress->arrOfPtrsToStrings = arrOfPtrsToStrings;
    structAddress->numberOfStrings    = numberOfStrings;
}
*/
///
void getStructNovel2 (struct novel* structAddress, const char* fileName) {
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
    //size_t lengthOfString = 0;
    for( ; (structAddress->text[numOfCharInText] != '\0') && (line < structAddress->numberOfStrings) ; numOfCharInText++) {
        //lengthOfString++;
        if (structAddress->text[numOfCharInText] == '\n') {
            (structAddress->arrOfStringStructs[line]).ptrToString = structAddress->text + numOfCharInText + 1;
            //(structAddress->arrOfStringStructs[line]).lengthOfString = lengthOfString + 1;
            line++;
            //lengthOfString = 0;
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

    stringsBubbleSort(structAddress, &myStrcmp3);

    fputs("FOR SCIENTISTS ONLY:\n\n", file);
    fwriteNovel (*structAddress, file);
    fputs("------------------------------------------------------------------\n\n\n", file);
}

void fwriteNovelAlphabeticallyFromEnd (struct novel* structAddress, FILE* file) {
    assert(structAddress);
    assert(file);

    qsort(structAddress->arrOfStringStructs, structAddress->numberOfStrings, sizeof(struct line), &reversedMyStrcmp2);

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
