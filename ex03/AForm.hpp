#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
    protected:
        const std::string _name;
        bool signe;
        const int _gradeSign;
        const int _gradeExec;
    public :
        class  GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };
        AForm(std::string n, int sign, int requi);
        virtual ~AForm();
        void    beSigned(const Bureaucrat &k);
        std::string getname_form() const;
        int     getgrade_signe() const;
        int     getgrade_requi() const;
        bool    getsigne_form() const;
        void execute(Bureaucrat const & executor) const; 
        virtual void   executeAction() const = 0;
};


#endif