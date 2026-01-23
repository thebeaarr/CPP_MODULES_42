#include "RPN.hpp"
RPN::RPN()
{

}


RPN::RPN(std::string &s) : expr(s)
{
}


RPN::RPN(const RPN &obj) : expr(obj.expr),operands( obj.operands )
{
}



RPN &RPN::operator=(const RPN &obj)
{
    if(&obj != this)
    {
        this->expr  = obj.expr ;
        this->operands= obj.operands;
    }
    return *this;  
}




RPN::~RPN(){}



void RPN::reverse_polish_notation()
{
    str_it it = expr.begin();
    for(; it != expr.end() ; ++it)
    {
        if(std::isdigit(*it) && it != expr.begin() && std::isdigit(*(it  -1 )) )
            throw std::runtime_error("ERROR");
        if(std::isdigit(*it))
        {
            int val = *it - '0';
            operands.push(val);
            continue ;
        }
        if(isOp(*it) && operands.size() >= 2 )
        {
            int a = operands.top(); operands.pop();
            int b = operands.top() ; operands.pop();
            int c = doOpe(b, a , *it);
            operands.push(c);
            continue ;
        }
        if(!std::isspace(*it))
            throw std::runtime_error("ERROR");
    }
    std::cout << operands.top() << std::endl;
}

bool RPN::isOp(char c )
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true ;
    return false;
}



int RPN::doOpe(int &a  ,int &b , char c)
{
    int op  = 0;
    switch(c)
    {
        case '+' :
            op  = a +b ;
        break;
        case '*':
            op = a * b ;
        break;
        case '/' :
            if(b == 0 )
                throw std::runtime_error("ERROR: Devision by zero");
            op = static_cast<int>(a / b);
        break;
        case '-':
            op = a - b ;
        break;
        default :;


    }
    return op ;
}



