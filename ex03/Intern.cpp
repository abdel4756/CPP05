#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
      std::cout << "Intern Constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructer ." << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern Copy Constructor called." << std::endl;    
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern Copy Constructor called." << std::endl;
    return *this;
}



static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

struct FormFactory
{
    std::string name;
    AForm* (*create)(const std::string& target);
};



AForm* Intern::makeForm(std::string forname, std::string target)
{
    FormFactory form[] = {
         {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };

    for(int i = 0; i < 3; i++)
    {
        if(forname == form[i].name)
        {
            std::cout << "Intern creates " << forname << std::endl;
            return form[i].create(target);
        }
    }

    std::cout << "Error: form " << forname << " does not exist" << std::endl;
    return NULL;
}

