#include <stdio.h>
#include <assert.h>
#include <TXLib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "bestOneginReader.h"
#include "stringsFunctions.h"

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
    printf("%d\n", sizeOfFile);
    printf("%d\n", read(fileDescriptor, fileCopyBuffer, sizeOfFile));

    if (read(fileDescriptor, fileCopyBuffer, sizeOfFile) == -1) {
        perror ("Ошибка чтения файла");
        return 0;
    }
    else return fileCopyBuffer;

    return NULL;
}





ssize_t getSizeOfFile (int fileDescriptor) {
    struct stat fileInfo;

    if (fstat(fileDescriptor, &fileInfo) == 0)
        return fileInfo.st_size;

    perror("Ошибка получения размера файла");
    return -1;
}

