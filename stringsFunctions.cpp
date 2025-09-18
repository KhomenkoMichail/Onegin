#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>
#include <ctype.h>

#include "stringsFunctions.h"
#include "textStructs.h"

int myPuts(const char* str) {
    assert (str);

    int returnableValue = 0;
    for (int i = 0; (str[i] != '\0') && (str[i] != '\n') ; i++)
        returnableValue = putchar (str[i]);

    return returnableValue;
}

int myFputs(const char* str, FILE* file) {
    assert (str);

    int returnableValue = 0;
    for (int i = 0; (str[i] != '\0') && (str[i] != '\n') ; i++)
        returnableValue = fputc (str[i], file);

    fputc('\n', file);

    return returnableValue;
}

const char* myStrchr (const char* str, int searchedSymbol) {
    assert(str);

    const char* symbolAddress = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == searchedSymbol)
            symbolAddress = str + i;
    }
    return symbolAddress;
}

size_t myStrlen (const char* str) {
    assert(str);

    size_t lengthOfString = 0;
    for (int i = 0; (str[i] != '\0') && (str[i] != '\n'); i++)
        lengthOfString++;
    return lengthOfString;
}

char* myStrcat (char* changedString, const char* addedString) {
    assert(changedString);
    assert(addedString);

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
    assert(changedString);
    assert(addedString);

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
    assert(str);

    int num = 0;
    for (int i = 0; (str[i] >= '0') && (str[i] <= '9'); i++)
        num = num*10 + (str[i] - '0');
    return num;
}

char* myFgets (char* str, int stringSize, FILE* file) {
    assert(str);
    assert(file);

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
    assert(str);

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
    assert(n);
    assert(file);

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
    assert(str1);
    assert(str2);

    size_t numOfChar1  = 0;
    size_t numOfChar2  = 0;

    size_t sizeOfFirstStr  = myStrlen(str1) + 1;
    size_t sizeOfSecondStr = myStrlen(str2) + 1;

    while ((str1[numOfChar1] != '\0') && (str2[numOfChar2] != '\0') && (str1[numOfChar1] != '\n') && (str2[numOfChar2] != '\n')) {
        while ((!isalpha(str1[numOfChar1])) && (str1[numOfChar1] != '\0') && (str1[numOfChar1] != '\n'))
            numOfChar1++;

        while ((!isalpha(str2[numOfChar2])) && (str2[numOfChar2] != '\0') && (str2[numOfChar2] != '\n'))
            numOfChar2++;

        if (tolower(str1[numOfChar1]) != tolower(str2[numOfChar2]))
            return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));

        if (numOfChar1 < (sizeOfFirstStr))
            numOfChar1++;

        if (numOfChar2 < (sizeOfSecondStr))
            numOfChar2++;
    }
    return (tolower(str1[numOfChar1]) - tolower(str2[numOfChar2]));
}

int reversedMyStrcmp(const char* str1, const char* str2) {
    assert(str1);
    assert(str2);

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

    assert ("Error in function reversedMyStrcmp" && 0);
    return 0;
}

void swapStringContents(char* str1, char* str2) {
    assert(str1);
    assert(str2);

    size_t sizeOfFirstStr  = myStrlen(str1) + 1;
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

int myStrcmp2 (const char* str1, const char* str2) {
    assert(str1);
    assert(str2);

    const char* firstStringCharPtr  = str1;
    const char* secondStringCharPtr  = str2;

    size_t sizeOfFirstStr  = myStrlen(str1) + 1;
    size_t sizeOfSecondStr = myStrlen(str2) + 1;

    while ((*firstStringCharPtr != '\0') && (*secondStringCharPtr != '\0') && (*firstStringCharPtr != '\n') && (*secondStringCharPtr != '\n')) {
        moveCharPointer(&firstStringCharPtr);
        moveCharPointer(&secondStringCharPtr);

        if (tolower(*firstStringCharPtr) != tolower(*secondStringCharPtr))
            return (tolower(*firstStringCharPtr) - tolower(*secondStringCharPtr));

        if (firstStringCharPtr < (str1 + sizeOfFirstStr))
            firstStringCharPtr++;

        if (secondStringCharPtr < (str2 + sizeOfSecondStr))
            secondStringCharPtr++;
    }
    return (tolower(*firstStringCharPtr) - tolower(*secondStringCharPtr));
}

void moveCharPointer(const char** charPointer) {
    assert(charPointer);

    while ((!isalpha(**charPointer)) && (**charPointer != '\0') && (**charPointer != '\n'))
        (*charPointer)++;
}

void swapStringContents2(char* str1, char* str2) {
    assert(str1);
    assert(str2);

    char cell = 0;
    size_t lengthOfStr1 = myStrlen(str1) + 1;
    size_t lengthOfStr2 = myStrlen(str2) + 1;
    printf("%d\n%d\n", lengthOfStr1, lengthOfStr2);

    for(size_t numOfChar = 0; (numOfChar < lengthOfStr1) &&
                              (numOfChar < lengthOfStr2); numOfChar++) {

        cell = str1[numOfChar];
        putchar(cell);
        str1[numOfChar] = str2[numOfChar];
        printf("[%d] == %c\n", numOfChar, str1[numOfChar]);
        str2[numOfChar] = cell;
    }

    str1[lengthOfStr1] = '\0';
    str2[lengthOfStr2] = '\0';
}

int myStrcmp3 (const struct line str1, const struct line str2) {
    assert(str1.ptrToString);
    assert(str2.ptrToString);

    const char* firstStringCharPtr  = str1.ptrToString;
    const char* secondStringCharPtr  = str2.ptrToString;

    size_t sizeOfFirstStr  = str1.lengthOfString;
    size_t sizeOfSecondStr = str2.lengthOfString;

    while ((*firstStringCharPtr != '\0') && (*secondStringCharPtr != '\0') && (*firstStringCharPtr != '\n') && (*secondStringCharPtr != '\n')) {
        moveCharPointer(&firstStringCharPtr);
        moveCharPointer(&secondStringCharPtr);

        if (tolower(*firstStringCharPtr) != tolower(*secondStringCharPtr))
            return (tolower(*firstStringCharPtr) - tolower(*secondStringCharPtr));

        if (firstStringCharPtr < (str1.ptrToString + sizeOfFirstStr))
            firstStringCharPtr++;

        if (secondStringCharPtr < (str2.ptrToString + sizeOfSecondStr))
            secondStringCharPtr++;
    }
    return (tolower(*firstStringCharPtr) - tolower(*secondStringCharPtr));
}

int reversedMyStrcmp2(const void* str1, const void* str2) {
    assert(str1);
    assert(str2);

    const struct line* line1 = (const struct line*)(str1);
    const struct line* line2 = (const struct line*)(str2);

    size_t numOfChar1  = line1->lengthOfString - 1;
    size_t numOfChar2  = line2->lengthOfString - 1;

    while ((numOfChar1 != 0) && (numOfChar2 != 0)) {
        while ((!isalpha(line1->ptrToString[numOfChar1])) && (numOfChar1 != 0))
            numOfChar1--;

        while ((!isalpha(line2->ptrToString[numOfChar2])) && (numOfChar2 != 0))
            numOfChar2--;

        if (tolower(line1->ptrToString[numOfChar1]) != tolower(line2->ptrToString[numOfChar2]))
            return (tolower(line1->ptrToString[numOfChar1]) - tolower(line2->ptrToString[numOfChar2]));

        if ((numOfChar1 > 0) && (numOfChar2 > 0))
            numOfChar1--;
            numOfChar2--;
    }
    if ((numOfChar1 == 0) && (numOfChar2 == 0))
        return (tolower(line1->ptrToString[numOfChar1]) - tolower(line2->ptrToString[numOfChar2]));
    if (numOfChar1 == 0)
        return (tolower(line2->ptrToString[numOfChar2 - 1]));
    if (numOfChar2 == 0)
        return (tolower(line1->ptrToString[numOfChar1 - 1]));

    assert ("Error in function reversedMyStrcmp" && 0);
    return 0;
}
