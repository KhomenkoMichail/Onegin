#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>
#include <ctype.h>

#include "stringsFunctions.h"

int myPuts(const char* str) {
    assert (str != NULL);
    //int n = 1;
    int returnableValue = 0;
    //printf("[%d]", 0);
    for (int i = 0; (str[i] != '\0') && (str[i] != '\n') ; i++) {
        //printf("[%d]", i);
        returnableValue = putchar (str[i]);
        //if (str[i] == '\n')
            //printf("\n\n");

        /*if (str[i] == '\n') {
            printf("[%d]", n);
            n++;
        }*/
    }
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
    for (int i = 0; (str[i] != '\0') && (str[i] != '\n'); i++)
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
    newStr[lengthOfStr] = '\0';

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

int myStrcmp(const char* str1, const char* str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t numOfChar1  = 0;
    size_t numOfChar2  = 0;

    while ((str1[numOfChar1] != '\0') && (str2[numOfChar2] != '\0') && (str1[numOfChar1] != '\n') && (str2[numOfChar2] != '\n')) {
        while ((!isalpha(str1[numOfChar1])) && (str1[numOfChar1] != '\0') && (str1[numOfChar1] != '\n'))
            numOfChar1++;

        while ((!isalpha(str2[numOfChar2])) && (str2[numOfChar2] != '\0') && (str2[numOfChar2] != '\n'))
            numOfChar2++;

        if (tolower(str1[numOfChar1]) != tolower(str2[numOfChar2]))
            return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));

        if (numOfChar1 < (myStrlen(str1) + 1))
            numOfChar1++;

        if (numOfChar2 < (myStrlen(str2) + 1))
            numOfChar2++;
    }
    return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));
}

int reversedMyStrcmp(const char* str1, const char* str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    const int ERROR_TERMINATION = 1111;
    size_t numOfChar1  = myStrlen(str1);
    size_t numOfChar2  = myStrlen(str2);

    while ((numOfChar1 != 0) && (numOfChar2 != 0)) {
        while ((!isalpha(str1[numOfChar1])) && (numOfChar1 != 0))
            numOfChar1--;

        while ((!isalpha(str2[numOfChar2])) && (numOfChar2 != 0))
            numOfChar2--;

        if (tolower(str1[numOfChar1]) != tolower(str2[numOfChar2]))
            return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));

        if ((numOfChar1 > 0) && (numOfChar2 > 0))
            numOfChar1--;
            numOfChar2--;
    }
    if ((numOfChar1 == 0) && (numOfChar2 == 0))
        return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));
    if (numOfChar1 == 0)
        return (tolower(str2[numOfChar2 - 1]));
    if (numOfChar2 == 0)
        return (tolower(str1[numOfChar1 - 1]));

    return ERROR_TERMINATION;
}

void swapStringContents(char* str1, char* str2) {
    assert(str1 != NULL);
    assert(str2 != NULL);

    size_t sizeOfFirstStr = myStrlen(str1) + 1;
    size_t sizeOfSecondStr = myStrlen(str2) + 1;

    char* memoryString = (char*)calloc(sizeOfFirstStr, sizeof(char));

    for(size_t i = 0; i <= sizeOfFirstStr; i++)
        memoryString[i] = str1[i];

    for(size_t i = 0; i <= sizeOfFirstStr; i++)
        str1[i] = '\0';
    for(size_t i = 0; i <= sizeOfSecondStr; i++)
        str1[i] = str2[i];

    for(size_t i = 0; i <= sizeOfSecondStr; i++)
        str2[i] = '\0';
    for(size_t i = 0; i <= sizeOfFirstStr; i++)
        str2[i] = memoryString[i];

    free(memoryString);
}
