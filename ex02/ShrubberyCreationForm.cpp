#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string trg) : AForm(trg, 145, 137), target(trg)
{
}

void    ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((this->target + "_shrubbery").c_str());
    if(file.is_open())
    {
        file << "                   /\\\n";
        file << "                  /**\\\n";
        file << "                 /****\\\n";
        file << "                /******\\\n";
        file << "               /********\\\n";
        file << "              /**********\\\n";
        file << "             /************\\\n";
        file << "            /**************\\\n";
        file << "           /****************\\\n";
        file << "          /******************\\\n";
        file << "                 |||||||\n";
        file << "                 |||||||\n";
        file << "                 |||||||\n\n";
    }
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructer of Shrubbery called ." << std::endl;
}