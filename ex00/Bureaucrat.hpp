#pragma once
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
public:
	class GradeTooHighException: public std::exception {
	public:
		virtual char const * what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual char const * what() const throw();
	};
	Bureaucrat( std::string const & name = "bureaucrat", int grade = 150 )
		throw ( GradeTooHighException, GradeTooLowException );
	Bureaucrat( Bureaucrat const & src )
		throw ( GradeTooHighException, GradeTooLowException );
	~Bureaucrat();
	Bureaucrat &		operator=( Bureaucrat const & rhs );
	std::string			getName() const;
	int					getGrade() const;
private:
	std::string	const	_name;
	int					_grade;
	void checkGrade() throw ( GradeTooHighException, GradeTooLowException );
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );
