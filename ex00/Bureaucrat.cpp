#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::waht() const throw()
{
    return("throw GradeTooHighException");
}

const char * Bureaucrat::GradeTooLowExceptio::what() const throw()
{
    return("throw GradeTooHighException ");
}

Bureaucrat::Bureaucrat(std::string str, int i) : name(str) , grade(i)
{
    std::cout << "Constructer of Parametre Called ." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructer Called !" << std::endl;
}

std::string    Bureaucrat::getName() const
{
    return(this->name);
}

int    Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::increment_Bureau()
{
    if(this->grade != 1)
        this->grade--;
    else
        throw Bureaucrat::GradeTooLowExceptio ();
}

void    Bureaucrat::decrement_Bureau()
{
    if(this->grade != 125)
        this->grade++;
    else
        throw Bureaucrat::GradeTooLowExceptio();
}

std::ostream& operator<< (std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << " , bureaucrat grade " << b.getGrade();
    return(out);
}
