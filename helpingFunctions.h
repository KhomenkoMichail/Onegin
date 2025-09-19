#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

void freeStruct (struct novel* structAddress);

ssize_t getSizeOfFile (int fileDescriptor);

size_t getNumberOfSymbols (char* text, char searchedSymbol);

void fillTheFile (struct novel* structAddress, const char* nameOfFile);

#endif
