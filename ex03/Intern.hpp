#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

class Intern {
public:
	Intern();
	Intern( const Intern & src );
	~Intern();
	Intern &	operator=( Intern const & rhs );
	Form*		makeForm( std::string const & formName,
				          std::string const & target )
		const;
private:
	Form*	makePresidentialPardonForm( std::string const & target ) const;
	Form*	makeRobotomyRequestForm( std::string const & target ) const;
	Form*	makeShrubberyCreationForm( std::string const & target ) const;
	Form*	throwException( std::string const & ) const;
	struct FormNameFunctionEntry {
		std::string 		name;
		Form* (Intern::*	makeFunction)( std::string const & ) const;
	};
	static const FormNameFunctionEntry functionsDic[];
};
