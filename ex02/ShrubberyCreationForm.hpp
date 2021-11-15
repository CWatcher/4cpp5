#pragma once
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
public:
	ShrubberyCreationForm( std::string const & target )
		throw ( Form::GradeTooHighException, Form::GradeTooLowException );
	ShrubberyCreationForm( ShrubberyCreationForm const & src )
			throw ( GradeTooHighException, GradeTooLowException );

	void	executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException );
};
