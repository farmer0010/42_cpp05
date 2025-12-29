#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf = NULL;

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);

        delete rrf;
        rrf = NULL;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        if (rrf) delete rrf;
    }

    std::cout << "\n-----------------------------------\n" << std::endl;

    try {
        rrf = someRandomIntern.makeForm("non existent form", "Target");
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
