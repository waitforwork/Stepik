#include "stringpointer.h"

StringPointer::StringPointer()
{

}
std::string* StringPointer::operator->()
    {
        if (!pointer)
        {
            pointer = new std::string();
            std::cerr << "Bad pointer!" << std::endl;
        }
        return pointer;
    }

StringPointer::operator std::string*()
{
    return pointer;
}

StringPointer::StringPointer(std::string *Pointer): pointer(Pointer) {}
