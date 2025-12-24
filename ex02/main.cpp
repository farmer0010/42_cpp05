#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat alba("Alba", 140);

        ShrubberyCreationForm  shrub("home");
        RobotomyRequestForm    robot("Target_A");
        PresidentialPardonForm pardon("Criminal_B");

        std::cout << "\n--- 1. Shrubbery Test (Low Grade) ---" << std::endl;
        alba.signForm(shrub);
        alba.executeForm(shrub);

        std::cout << "\n--- 2. Robotomy Test (Middle Grade) ---" << std::endl;
        alba.signForm(robot);
        boss.signForm(robot);
        boss.executeForm(robot);

        std::cout << "\n--- 3. Presidential Test (High Grade) ---" << std::endl;
        boss.executeForm(pardon);
        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
