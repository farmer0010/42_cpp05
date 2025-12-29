#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

	AForm* (Intern::*funcPtrs[3])(std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

	for (int i=0; i<3; i++)
	{
		if(name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*funcPtrs[i])(target);
		}
	}
	std::cout << "Intern cannot create " << name << " because it doesn't exist." << std::endl;
    throw std::runtime_error("Form name not found");
}
