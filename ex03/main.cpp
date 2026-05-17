#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"




int main()
{
    Intern someIntern;

    std::cout << "===== TEST 1: Création d'un ShrubberyCreationForm =====" << std::endl;
    AForm* f1 = someIntern.makeForm("shrubbery creation", "home");
    if (f1) {
        Bureaucrat bob("Bob", 130);
        bob.signForm(*f1);
        bob.executeForm(*f1);
        delete f1;
    }

    std::cout << "\n===== TEST 2: Création d'un RobotomyRequestForm =====" << std::endl;
    AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
    if (f2) {
        Bureaucrat alice("Alice", 40);
        alice.signForm(*f2);
        alice.executeForm(*f2);
        delete f2;
    }

    std::cout << "\n===== TEST 3: Création d'un PresidentialPardonForm =====" << std::endl;
    AForm* f3 = someIntern.makeForm("presidential pardon", "Arthur Dent");
    if (f3) {
        Bureaucrat president("President", 1);
        president.signForm(*f3);
        president.executeForm(*f3);
        delete f3;
    }

    std::cout << "\n===== TEST 4: Formulaire inconnu =====" << std::endl;
    AForm* f4 = someIntern.makeForm("unknown form", "Nobody");
    if (f4) {
        delete f4;
    }

    return 0;
}