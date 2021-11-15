#pragma once
#include "Form.hpp"

class RobotomyRequestForm: public Form {
public:
	RobotomyRequestForm( std::string const & target )
		throw ( Form::GradeTooHighException, Form::GradeTooLowException );
	RobotomyRequestForm( RobotomyRequestForm const & src )
			throw ( GradeTooHighException, GradeTooLowException );

	void	executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException );
};
