#pragma once
#include "Form.hpp"

class PresidentialPardonForm: public Form {
public:
	PresidentialPardonForm( std::string const & target )
		throw ( Form::GradeTooHighException, Form::GradeTooLowException );
	PresidentialPardonForm( PresidentialPardonForm const & src )
			throw ( GradeTooHighException, GradeTooLowException );

	void	executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException );
};
