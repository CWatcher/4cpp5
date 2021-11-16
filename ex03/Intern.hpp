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
	Form*		makeForm( std::string const & formName, std::string const & target )
		const;
	struct FormNameFunctionEntry {
		std::string 		name;
		Form* (Intern::*	function)( std::string const & ) const;
	};
private:
	PresidentialPardonForm*	makePresidentialPardonForm( std::string const & target )
		const;
	static const FormNameFunctionEntry functionsDic[];
};
