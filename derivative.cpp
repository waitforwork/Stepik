#include "derivative.h"


Derivative::Derivative()
{

}

std::string Derivative::func_derivative(std::string polynom)
    {
        std::string s= polynom;
        s=s+'+'; //для верной обработки последнего слагаемого полинома(а0)
        if (s[0]=='-')
        {
            koef='-';
        }
        if (s[0]=='+' || s[0]=='-')
        {
            s=s.substr(1); //убираем 0 символ, который или + или -
        }
        for (auto i = s.begin(); i != s.end(); i++)
        {
            if (*i=='+'|| *i=='-') //если текущий элемент строки знак, то надо степень и коэф перед степень занести в мап
            {
                koef=*i;
                if (!fl_x)
                {
                    continue;
                }
                if (fl_x && !flag_stepen)
                {
                    stepen = "1";
                }
                fl_x = false;
                flag_stepen = false;
                b = stoi(stepen); // преобразование строки в целочисленный тип
                stepen = "";
                for (auto j = element.begin(); j != element.end(); j++)
                {
                    if (j->first == (b-1))
                    {
                        j->second += a*b;
                        fl_b = true;
                    }
                }
                if (!fl_b) //степени кончились, текущее слагаемое полинома кончилось, сохраняем его в мап
                {
                    element.insert(std::pair<int,int>(b-1,a*b));
                }
                fl_b=false;
                continue;
            }
            if (*i=='x') // если дошли до х, то нужно сохранить коэф перед ним
            {
                fl_x=true;
                if (koef=="-" || koef=="+" || koef=="")
                {
                    koef+='1';
                }
                a = stoi(koef);
            }
            if (isdigit(*i) && !(flag_stepen))
            {
                koef +=*i;
            }
            if (isdigit(*i) && flag_stepen)// если текущий элемент цифра и мы в степени дополняем степень
            {
                stepen+= *i;
            }
            if (*i=='^') // переход в степень
            {
                flag_stepen=true;
            }
        }
        // вывод в порядке убывания степеней и с учетом особых случаев
        for (auto j=element.begin(); j!=element.end(); j++)
        {
            if (j->second==0)
            {
                continue;
            }
            if (j->first==0)
            {
                result=std::to_string(j->second)+result;
                if (j->second>0)
                {
                    result="+"+result;
                }
                continue;
            }
            if (j->first == 1)
            {
                result = "x" + result;
            }
            if (j->first > 1)
            {
                result = "x^" + std::to_string(j->first) + result;
            }
            if (j->second == -1)
            {
                result = "-" + result;
            }
            if (abs(j->second)>1)
            {
                result = std::to_string(j->second) + "*" +result;
            }
            if (j->second > 0)
            {
                result = "+" + result;
            }
        }
        if (result[0] == '+')
        {
            result = result.substr(1);
        }
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
