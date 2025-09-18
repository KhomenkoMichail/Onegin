#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

void supportEndOfProgram (struct novel* structAddress, FILE* file);

ssize_t getSizeOfFile (int fileDescriptor);

size_t getNumberOfSymbols (char* text, char searchedSymbol);

FILE* fillTheFile (struct novel* structAddress, const char* nameOfFile);

#endif
