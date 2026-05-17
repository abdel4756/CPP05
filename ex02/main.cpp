#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"




int main()
{
    std::cout << "===== TEST 1: ShrubberyCreationForm =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");

        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: RobotomyRequestForm =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot); // tester plusieurs fois (50%)
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: PresidentialPardonForm =====" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Grade trop bas =====" << std::endl;
    try
    {
        Bureaucrat low("Intern", 150);
        PresidentialPardonForm pardon("Ford Prefect");

        low.signForm(pardon);      // devrait échouer
        low.executeForm(pardon);   // ne devrait pas s'exécuter
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Form non signée =====" << std::endl;
    try
    {
        Bureaucrat chief("Chief", 1);
        RobotomyRequestForm robot("Marvin");

        // On ne signe PAS le formulaire
        chief.executeForm(robot); // devrait lancer une exception
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}