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
	class IsNotSignedException: public std::exception {
	public:
		virtual char const * what() const throw();
	};

	Form(   std::string const & name, std::string const & target
		  , int gradeToSign, int gradeToExecute )
		throw ( GradeTooHighException, GradeTooLowException );
	Form( Form const & src )
		throw ( GradeTooHighException, GradeTooLowException );
	virtual ~Form();

	Form &			operator=( Form const & rhs );
	std::string		getName() const throw();
	std::string		getTarget() const throw();
	int				getGradeToSign() const throw();
	int				getGradeToExecute() const throw();
	bool			getIsSigned() const throw();
	void			beSigned( Bureaucrat const & signer )
		throw ( GradeTooLowException );
	void virtual	execute( Bureaucrat const & executor ) const
		throw ( GradeTooLowException, IsNotSignedException )
		= 0;
protected:
	std::string	const	_name;
	std::string	const	_target;
	int	const			_gradeToSign;
	int	const			_gradeToExecute;
	bool				_isSigned;

	void			checkGrade( int grade ) const
		throw ( GradeTooHighException, GradeTooLowException );
	void		checkForExecution( Bureaucrat const & executor ) const
		throw ( GradeTooLowException, IsNotSignedException );
};

std::ostream &	operator<<( std::ostream & o, Form const & i ) throw();
