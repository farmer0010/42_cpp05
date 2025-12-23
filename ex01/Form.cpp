#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();

    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(){

}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too High for this Form";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too Low for this Form";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade();
    return os;
}
