#ifndef STRINGPOINTER_H
#define STRINGPOINTER_H
#include <iostream>

class StringPointer
{
private:
    std::string* pointer;
public:
    StringPointer();
    std::string *operator->();
    operator std::string*();
    StringPointer(std::string *Pointer);
    ~StringPointer() {};
};

#endif // STRINGPOINTER_H
