#ifndef SORTS_H
#define SORTS_H

typedef int (*comparefunc_t)(const char* str1, const char* str2);

void intBubbleSort (int* arr, size_t sizeOfArr);

void stringsBubbleSort (struct novel* structAddress, comparefunc_t compareFuncAddress);

#endif
