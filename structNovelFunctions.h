#ifndef STRUCT_NOVEL_FUNCTIONS_H
#define STRUCT_NOVEL_FUNCTIONS_H

char* copyFileContent (struct novel* structAddress, const char* fileName);

void getStructNovel (struct novel* structAddress, const char* fileName);

void getLengthOfStrings (struct novel* structAddress);

void getArrOfStringStructs (struct novel* structAddress);

void fwriteNovel (struct novel Onegin, FILE* file);

void fwriteNovelAlphabetically (struct novel* structAddress, FILE* file);

void fwriteNovelAlphabeticallyFromEnd (struct novel* structAddress, FILE* file);

void fwriteNovelOriginal (struct novel novelName, FILE* file);

#endif
