#pragma once
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
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

	Form(   std::string const & name = "form"
		  , int gradeToSign = 1, int gradeToExecute = 1 )
		throw ( GradeTooHighException, GradeTooLowException );
	Form( Form const & src )
		throw ( GradeTooHighException, GradeTooLowException );
	~Form();

	Form &		operator=( Form const & rhs );
	std::string	getName() const throw();
	int			getGradeToSign() const throw();
	int			getGradeToExecute() const throw();
	bool		getIsSigned() const throw();
	void		beSigned( Bureaucrat const & signer )
		throw ( GradeTooLowException );
private:
	std::string	const	_name;
	int	const			_gradeToSign;
	int	const			_gradeToExecute;
	bool				_isSigned;

	void		checkGrade( int grade )
		throw ( GradeTooHighException, GradeTooLowException );
};

std::ostream &	operator<<( std::ostream & o, Form const & i ) throw();
