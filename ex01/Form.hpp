#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool signe;
        const int grade_signe;
        const int grade_requi;
        
    public :

        class GradeToolHightException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            const char* what() const throw();
        };

        Form(std::string n, int sign, int requi);
        ~Form();
        void    beSigned(const Bureaucrat &k);
        std::string getname_form() const;
        int     getgrade_signe();
        int     getgrade_requi();
        bool    getsigne_form() const;
};

std::ostream& operator <<(std::ostream &out, Form &k);

#endif