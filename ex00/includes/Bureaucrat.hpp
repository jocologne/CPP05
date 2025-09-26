#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
	std::string _name;
	int _grade;
public:
	//Canonical
	Bureaucrat(const std::string& _name, int _grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	//Getters
	const std::string& getName() const;
	int getGrade() const;
	//Increment-Decrement
	void incrementGrade();
	void decrementGrade();
	//Exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif