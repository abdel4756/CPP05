#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void    Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getname_form() << std::endl;
    }
    catch(std::exception &d)
    {
        std::cout << this->name << " couldn’t sign " << f.getname_form() << " because" << d.what()<< std::endl;
    }
}
