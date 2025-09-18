#ifndef SORTS_H
#define SORTS_H

typedef int (*comparefunc_t)(struct line str1, struct line str2);

void intBubbleSort (int* arr, size_t sizeOfArr);

void stringsBubbleSort (struct novel* structAddress, comparefunc_t compareFuncAddress);

#endif
