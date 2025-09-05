#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"

int myPuts(const char* str) {
    assert (str != NULL);

    int returnableValue = 0;
    for (int i = 0; str[i] != '\0'; i++)
        returnableValue = putchar (str[i]);
    return returnableValue;
}

const char* myStrchr (const char* str, int c) {
    assert(str != NULL);

    const char* symbolAddress = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            symbolAddress = &str[i];
    }
    return symbolAddress;
}

size_t myStrlen (const char* str) {
    assert(str != NULL);

    size_t lengthOfString = 0;
    for (int i = 0; str[i] != '\0'; i++)
        lengthOfString++;
    return lengthOfString;
}

char* myStrcat (char* str1, const char* str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i = 0;
    for (i = 0; str1[i] != '\0'; i++)
        continue;

    for (int j = 0; 1; j++, i++) {
        str1[i] = str2[j];
        if(str2[j] == '\0')
            break;
    }
    return str1;
}

char* myStrncat(char* str1, const char* str2, size_t n) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i = 0;
    for (i = 0; str1[i] != '\0'; i++)
        continue;

    for (unsigned int j = 0; j < n; j++, i++) {
        str1[i] = str2[j];
        if(str2[j] == '\0')
            break;
    }
    return str1;
}

int myAtoi(const char* str) {
    assert(str != NULL);

    int num = 0;
    for (int i = 0; (str[i] > 47) && (str[i] < 58); i++)
        num = num*10 + (str[i] - 48);
    return num;
}

char* myFgets (char* str, int stringSize, FILE* file) {
    assert(str != NULL);
    assert(file != NULL);

    for (int i = 0; i <=  stringSize; i++) {
        str[i] = (char)fgetc(file);
        if (str[i] == EOF) {
            str[i] = '\0';
            break;
        }
        else if (str[i] == '\n') {
            str[i+1] = '\0';
            break;
        }
    }
    return str;
}

char* myStrdup(const char* str) {
    int lengthOfStr = 0;
    for(int i = 0; str[i] != '\0'; i++)
        lengthOfStr++;
    char* newStr = (char* )calloc( (lengthOfStr+1), sizeof(char));
    for (int n = 0; str[n] != '\0'; n++)
        newStr[n] = str[n];
    newStr[lengthOfStr+1] = '\0';

    return newStr;
}

ssize_t myGetline(char** lineptr, size_t* n, FILE* file) {
    assert(n != NULL);
    assert(file != NULL);

    unsigned int lengthOfString = 0;
    char* lengthFindingString = 0;

    if (*lineptr == NULL)
        *lineptr = (char* )calloc(*n, sizeof(char));

    for (int i = 0; lengthFindingString[i] != '\0'; i++)
        lengthOfString++;
    if ( (lengthOfString + 1) > *n) {
        *n = lengthOfString + 1;
        realloc( *lineptr, *n);
    }

    for (int i = 0; ; i++) {
        *lineptr[i] = (char)fgetc(file);
        if (*lineptr[i] == '\0')
            break;
        if (*lineptr[i] == '\n') {
            *lineptr[i+1] = '\0';
            break;
        }
        if (*lineptr[i] == EOF)
            return -1;
    }
    return lengthOfString;
}



