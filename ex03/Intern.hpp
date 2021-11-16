#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern {
public:
	Intern();
	Intern( const Intern & src );
	~Intern();
	Intern &	operator=( Intern const & rhs );
	Form*		makeForm( std::string const & form, std::string const & target )
		const;
};
