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

const char* myStrchr (const char* str, int searchedSymbol) {
    assert(str != NULL);

    const char* symbolAddress = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == searchedSymbol)
            symbolAddress = str + i;
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

char* myStrcat (char* changedString, const char* addedString) {
    assert(changedString != NULL);
    assert(addedString != NULL);

    size_t lengthOfFirst = 0;
    size_t lengthOfSecond = 0;

    for ( ; changedString[lengthOfFirst] != '\0'; lengthOfFirst++)
        continue;

    for ( ; 1; lengthOfSecond++) {
        changedString[lengthOfFirst + lengthOfSecond] = addedString[lengthOfSecond];
        if(addedString[lengthOfSecond] == '\0')
            break;
    }
    changedString[lengthOfFirst + lengthOfSecond + 1] = '\0';
    return changedString;
}

char* myStrncat(char* changedString, const char* addedString, size_t n) {
    assert(changedString != NULL);
    assert(addedString != NULL);

    size_t lengthOfFirst = 0;
    size_t lengthOfSecond = 0;

    for ( ; changedString[lengthOfFirst] != '\0'; lengthOfFirst++)
        continue;

    for (; lengthOfSecond < n; lengthOfSecond++) {
        changedString[lengthOfFirst + lengthOfSecond] = addedString[lengthOfSecond];
        if(addedString[lengthOfSecond] == '\0')
            break;
    }
    changedString[n-1] = '\0';
    return changedString;
}

int myAtoi(const char* str) {
    assert(str != NULL);

    int num = 0;
    for (int i = 0; (str[i] >= '0') && (str[i] <= '9'); i++)
        num = num*10 + (str[i] - '0');
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
    assert(str != NULL);

    size_t lengthOfStr = 0;

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

    size_t charactersCount = 0;

    if (*lineptr == NULL)
        *lineptr = (char* )calloc(*n, sizeof(char));

    for (; ; charactersCount++) {
        if (charactersCount == *n) {
            *n *= 2;
            *lineptr = (char*)realloc(*lineptr, *n);
        }

        if ((*lineptr)[charactersCount] == EOF)
            return -1;

        (*lineptr)[charactersCount] = (char)fgetc(file);

        if ((*lineptr)[charactersCount] == '\0')
            break;

        if ((*lineptr)[charactersCount] == '\n') {
            (*lineptr)[charactersCount+1] = '\0';
            break;
        }
    }
    return charactersCount;
}





