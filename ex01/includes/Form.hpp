#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	bool _signed;
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
public:
	//Canonical
	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	//Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	//Exceptions
	class GradeTooHighExcepion : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	//Sign
	void beSigned(const Bureaucrat& bureaucrat);
};
//Operator <<
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif