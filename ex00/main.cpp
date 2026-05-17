#include "Bureaucrat.hpp"


int main()
{
    
    try{
        Bureaucrat k("asi", 1);
        std::cout << k << std::endl;
        k.increment_Bureau();
         std::cout << "sssssssssssssssssssssssssss\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n \n \n";

    try{
        Bureaucrat s("tana", 125);
        std::cout << s << std::endl;
        s.decrement_Bureau();
        std::cout << "ooooooooooooooooooooooooooo\n";
    }
    catch(std::exception &p)
    {
        std::cout << p.what() << std::endl;
    }
    return 0;
}