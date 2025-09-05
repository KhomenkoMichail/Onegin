#ifndef STRINGS_FUNCTIONS_H
#define STRINGS_FUNCTIONS_H

int myPuts(const char* str);

const char* myStrchr (const char* str, int c);

size_t myStrlen (const char* str);

char* myStrcat (char* str1, const char* str2);

char* myStrncat(char* str1, const char* str2, size_t n);

int myAtoi(const char* str);

char* myFgets (char* str, int stringSize, FILE* file);

char* myStrdup(const char* str);

ssize_t myGetline(char** lineptr, size_t* n, FILE* file);

#endif
