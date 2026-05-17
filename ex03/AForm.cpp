#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string n, int sign, int requi) : _name(n), _gradeSign(sign) , _gradeExec(requi)
{
    if(sign  < 1 ||requi < 1)
        throw GradeTooHighException();
    else if(sign > 150 || requi > 150)
        throw GradeTooLowException();
    signe = false;
}

AForm::~AForm()
{
    std::cout << "Desctructor of AForme base called !" << std::endl;
}

void    AForm::beSigned(const Bureaucrat &k)
{
    if(k.getGrade() > _gradeSign)
        throw GradeTooLowException();
    else
        signe = true;
}

std::string AForm::getname_form() const
{
    return _name;
}

int     AForm::getgrade_signe() const
{
    return _gradeSign;
}

int AForm::getgrade_requi() const
{
    return _gradeExec;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return(" Form Not Signed ");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return(" GRade to High ");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return(" GRade to Low ");
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!signe)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();

    executeAction();  // appelle la fonction spécifique de la classe dérivée
}