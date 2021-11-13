#pragma once
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
public:
	class GradeTooHighException: public std::exception {
	public:
		GradeTooHighException( int grade );
		virtual char const * what() const throw();
		int	const		grade;
	};
	class GradeTooLowException: public std::exception {
	public:
		GradeTooLowException( int grade );
		virtual char const * what() const throw();
		int	const		grade;
	};
	Bureaucrat( std::string const & name = "bureaucrat", int grade = 150 )
		throw ( GradeTooHighException, GradeTooLowException );
	Bureaucrat( Bureaucrat const & src )
		throw ( GradeTooHighException, GradeTooLowException );
	~Bureaucrat();
	Bureaucrat &	operator=( Bureaucrat const & rhs )
		throw ( GradeTooHighException, GradeTooLowException );
	std::string		getName() const throw();
	int				getGrade() const throw();
	int				incrementGrade() throw ( GradeTooHighException );
	int				decrementGrade() throw ( GradeTooLowException );
	void			signForm( Form & );
private:
	std::string	const	_name;
	int					_grade;
	void			checkGrade( int grade )
		throw ( GradeTooHighException, GradeTooLowException );
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i ) throw();
