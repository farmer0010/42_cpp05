#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

public:
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    AForm(std::string name, int signGrade, int execGrade);

    std::string getName() const;
    bool        getIsSigned() const;
    int         getSignGrade() const;
    int         getExecGrade() const;

    void        beSigned(const Bureaucrat& bureaucrat);
    void        execute(const Bureaucrat& executor) const;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

protected:
    virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
