#include <stdio.h>
#include <assert.h>
#include <TXLib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "bestOneginReader.h"
#include "stringsFunctions.h"
#include "textStructs.h"

char* copyFileContent (const char* fileName) {
    assert(fileName != NULL);

    int fileDescriptor = open(fileName, O_RDONLY, 0);
    if (fileDescriptor == -1) {
        perror("Ошибка открытия файла");
        return NULL;
    }

    ssize_t sizeOfFile = getSizeOfFile(fileDescriptor);
    if (sizeOfFile < 1) {
        close(fileDescriptor);
        return NULL;
    }

    char* fileCopyBuffer = (char*)calloc(sizeOfFile + 1, sizeof(char));

    size_t numOfReadedSymbols = read(fileDescriptor, fileCopyBuffer, sizeOfFile);
    fileCopyBuffer[numOfReadedSymbols] = '\0';
    return fileCopyBuffer;
    /*if (read(fileDescriptor, fileCopyBuffer, sizeOfFile) == -1) {
        perror ("Ошибка чтения файла");
        return 0;
    }
    else return fileCopyBuffer;

    return NULL;*/
}

ssize_t getSizeOfFile (int fileDescriptor) {
    struct stat fileInfo;

    if (fstat(fileDescriptor, &fileInfo) == 0)
        return fileInfo.st_size;

    perror("Ошибка получения размера файла");
    return -1;
}

size_t getNumberOfStrings (char* text) {
    assert(text != NULL);

    size_t numOfStrings = 0;
    for(size_t numOfChar = 0; text[numOfChar] != '\0'; numOfChar++)
        if (text[numOfChar] == '\n')
            numOfStrings++;

    return numOfStrings;
}

char** getPointersToStrings(char** arrOfPtr, size_t numberOfStrings, char* text) {
    assert(arrOfPtr != NULL);
    assert(text != NULL);

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

void getStructNovel (struct novel* structAddress, const char* fileName) {
    assert(structAddress != NULL);
    assert(fileName != NULL);

    char* buffer = copyFileContent(fileName);

    size_t numberOfStrings = getNumberOfStrings(buffer);
    char** arrOfPtrsToStrings = (char**)calloc(numberOfStrings, sizeof(char*));

    getPointersToStrings(arrOfPtrsToStrings, numberOfStrings, buffer);

    *structAddress = {
        .text = buffer,
        .arrOfPtrsToStrings = arrOfPtrsToStrings,
        .sizeOfText = strlen(buffer),
        .numberOfStrings = numberOfStrings
    };
}
