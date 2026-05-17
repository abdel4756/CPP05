#include "Form.hpp"


Form::Form(std::string n, int sign, int requi) : name(n),  grade_signe(sign),grade_requi(requi)
{
    if(sign  < 1 ||requi < 1)
        throw GradeToolHightException();
    else if(sign > 125 || requi > 125)
        throw GradeTooLowException();
    signe = false;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

void    Form::beSigned(const Bureaucrat &k)
{
    if(k.getGrade() > grade_signe)
        throw   GradeTooLowException();
    else
        signe = true;
}

std::string Form::getname_form() const
{
    return name;
}

int         Form::getgrade_requi()
{
    return grade_requi;
}

int         Form::getgrade_signe()
{
    return grade_signe;
}

bool    Form::getsigne_form() const
{
    return  signe;
}

const char* Form::GradeToolHightException::what() const throw()
{
    return(" grade too High ");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return(" grade too low ");
}

std::ostream& operator << (std::ostream &out, Form &k)
{
    out << "Form " << k.getname_form()
       << ", signed: " << k.getsigne_form()
       << ", grade to sign: " << k.getgrade_signe()
       << ", grade to execute: " << k.getgrade_requi();
    
    return out;
}