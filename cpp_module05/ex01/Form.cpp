#include "Form.hpp"

Form::Form() : name("unkown") ,gradetoExcute(0),gradetoSign(0) , isSigned(false)
{

}
Form::Form(Form const &obj) : name(obj.getName()), isSigned(obj.getisSigned()), gradetoSign(obj.getgradetoSign()), gradetoExcute(obj.getgradetoExcute())
{
} 

Form::Form(std::string const &namec , bool isSignedc, int gradetoSignc , int gradetoExcutec) : name(namec) , isSigned(isSignedc) , gradetoExcute(gradetoExcutec) , gradetoSign(gradetoSignc)
{

}
