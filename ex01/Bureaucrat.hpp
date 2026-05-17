#ifndef BUREAUCARAT_HPP
#define BUREAUCARAT_HPP

#include <string>
#include <iostream>
 
class Form;

class Bureaucrat
{
    private :
        const std::string   name;
        int                 grade;
    public :
        class GradeTooHighException : public std::exception 
        {
            public :
            virtual const char* waht() const throw();
        };

        class GradeTooLowExceptio : public std::exception 
        {
            public:
            virtual const char* what() const throw();
        };
    
        Bureaucrat(std::string str, int i);
        std::string      getName() const;
        int    getGrade() const;
        void    increment_Bureau();
        void    decrement_Bureau();
        void    signForm(Form &f);
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif