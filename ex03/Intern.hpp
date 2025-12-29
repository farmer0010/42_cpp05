#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm* makeShrubbery(std::string target);
    AForm* makeRobotomy(std::string target);
    AForm* makePresidential(std::string target);

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};
#endif
