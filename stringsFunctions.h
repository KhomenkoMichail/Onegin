#ifndef STRINGS_FUNCTIONS_H
#define STRINGS_FUNCTIONS_H

int myPuts(const char* str);

const char* myStrchr (const char* str, int searchedSymbol);

size_t myStrlen (const char* str);

char* myStrcat (char* changedString, const char* addedString);

char* myStrncat(char* changedString, const char* addedString, size_t n);

int myAtoi(const char* str);

char* myFgets (char* str, int stringSize, FILE* file);

char* myStrdup(const char* str);

ssize_t myGetline(char** lineptr, size_t* n, FILE* file);

int myStrcmp(const char* str1, const char* str2);

int reversedMyStrcmp(const char* str1, const char* str2);

void swapStringContents(char* str1, char* str2);

int myStrcmp2 (const char* str1, const char* str2);

void moveCharPointer(const char** charPointer);

void swapStringContents2(char* str1, char* str2);
#endif
