#ifndef DERIVATIVE_H
#define DERIVATIVE_H
#include "iostream"
#include <map>


class Derivative
{
private:
    std::string koef = "";      //f=a(n)*x^n+a(n-1)*x^n-1+...+a(0)
    std::string stepen = "";
    std::string result = "";
    int a = 0;
    int b = 0;
    bool flag_stepen = false;
    bool fl_b = false;
    bool fl_x = false;
    std::map <int,int> element;
public:
    Derivative();
    std::string func_derivative(std::string polynom);
};

#endif // DERIVATIVE_H
