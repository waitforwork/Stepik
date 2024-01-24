#include <iostream>
#include <stdint.h>
#include <derivative.h>
#include <stringpointer.h>

using namespace std;




int main()
{
    // проверка многочлена полинома
    /*Derivative new_func;
    std::cout << new_func.func_derivative("x^13+33x^2+x^7+x") << std::endl;
*/
    //проверка умного указателя на строку

    std::string s1 = "Hello, world!";
    StringPointer sp1(&s1);
    StringPointer sp2(NULL);
    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;

    return 0;
}
