#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();

    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm(){

}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if(this->_isSigned == false)
		throw FormNotSignedException();
	if(executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	this -> executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too High for this Form";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too Low for this Form";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade();
    return os;
}
