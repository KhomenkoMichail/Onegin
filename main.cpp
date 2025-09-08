#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <assert.h>

#include "stringsFunctions.h"

int main (void) {

    const char* str1 = "ABC";
    char str2[10] = "ZXC";
    char* str3 = NULL;
    size_t n = 20;

    myPuts(str1);
    putchar('\n');

    printf("&C = %p, &C = %p\n", &str1[2], myStrchr(str1, 'C'));

    printf("length of str = %d\n", myStrlen(str1) );

    myPuts(str2);
    putchar('\n');
    myStrcat(str2, str1);
    myPuts(str2);
    putchar('\n');

    myStrncat(str2, str1, 1);
    myPuts(str2);
    putchar('\n');


    printf("%d\n", myAtoi("1252") + 3);

    myFgets(str2, 10, stdin);
    myPuts(str2);
    putchar('\n');

    char* newStr = myStrdup(str1);
    myPuts(newStr);
    putchar('\n');
    free(newStr);


    myGetline(&str3, &n, stdin);
    myPuts(str3);
    free(str3);
    putchar('\n');

    printf("lengthOfString = %d\n", n);


    return 0;
}
