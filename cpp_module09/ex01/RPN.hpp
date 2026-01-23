#pragma once
#include <algorithm>
#include <exception>
#include <iostream>

#include <algorithm>
#include <stack>

class RPN
{


    private:
        std::string expr  ;
        std::stack<int> operands ;
        typedef std::string::iterator str_it;
        bool isOp(char c);
        int doOpe(int &a , int &b , char c  );

    public:
        RPN();
        RPN(std::string &s );
        RPN(const RPN &obj);
        ~RPN();
        RPN &operator=(const RPN &obj);
        void reverse_polish_notation();
};