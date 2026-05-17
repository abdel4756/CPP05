#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class AForm;

class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string trg);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ShrubberyCreationForm(const ShrubberyCreationForm &objet);
        ~ShrubberyCreationForm();
         void executeAction() const; 
};

#endif