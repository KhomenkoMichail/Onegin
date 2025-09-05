#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"

int main (void) {

    const char* str1 = "ABC";
    char str2[8] = "XYZ";
    myPuts(str1);

    printf("&C = %p, &C = %p\n", &str1[2], myStrchr(str1, 'C'));

    printf("length of str = %d\n", myStrlen(str1) );
}
