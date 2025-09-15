#ifndef TEXT_STRUCTS_H
#define TEXT_STRUCTS_H

struct novel {
    char* text;
    char** arrOfPtrsToStrings;
    size_t sizeOfText;
    size_t numberOfStrings;
};

#endif
