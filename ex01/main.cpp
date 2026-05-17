#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
    try
    {
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat bob("Bob", 50);
        Bureaucrat boss("Boss", 1);

        std::cout << bob << std::endl;
        std::cout << boss << std::endl;

        std::cout << "\n=== Creating Form ===" << std::endl;
        Form contract("Contract", 30, 10);

        std::cout << contract << std::endl;

        std::cout << "\n=== Bob tries to sign ===" << std::endl;
        bob.signForm(contract);
        std::cout << contract << std::endl;

        std::cout << "\n=== Boss tries to sign ===" << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
//0