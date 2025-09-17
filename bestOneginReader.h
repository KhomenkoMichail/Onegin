#ifndef BEST_ONEGIN_READER_H
#define BEST_ONEGIN_READER_H

char* copyFileContent (struct novel* structAddress, const char* fileName);

ssize_t getSizeOfFile (int fileDescriptor);

size_t getNumberOfSymbols (char* text, char searchedSymbol);

char** getPointersToStrings (char** arrOfPtr, size_t numberOfStrings, char* text);

void getStructNovel (struct novel* structAddress, const char* fileName);

#endif
