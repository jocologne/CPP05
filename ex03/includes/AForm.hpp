#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
	bool _signed;
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
public:
	//Canonical
	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	//Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	//Exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	//Functions
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;
protected:
	void checkExecutionRequirements(const Bureaucrat& executor) const;
};
//Operator <<
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif