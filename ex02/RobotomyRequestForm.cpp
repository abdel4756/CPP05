#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
RobotomyRequestForm::RobotomyRequestForm(std::string trg) : AForm(trg, 72, 45) , target(trg)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "destructer of Robotomy called ." << std::endl; 
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzzzz... drilling noises..." << std::endl;

    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}