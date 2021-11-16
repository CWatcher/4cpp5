#include "Intern.hpp"

Intern::Intern()
{}
Intern::Intern( const Intern & )
{}
Intern::~Intern()
{}

Intern &	Intern::operator=( Intern const & )
{	return *this;
}

Intern::FormNameFunctionEntry const Intern::functionsDic[] = {
	{ "PresidentialPardon", &Intern::makePresidentialPardonForm },
	{ "RobotomyRequest"   , &Intern::makeRobotomyRequestForm    },
	{ "ShrubberyCreation" , &Intern::makeShrubberyCreationForm  },
	{ "none"              , &Intern::throwException             }
};

Form*		Intern::makeForm( std::string const & formName,
			                  std::string const & target ) const
{
	size_t i = 0;

	while (i < sizeof(functionsDic) / sizeof(functionsDic[0]) - 1
	       && formName != functionsDic[i].name)
		i++;
	return ( this->*functionsDic[i].makeFunction )( target );
}

Form*	Intern::makePresidentialPardonForm( std::string const & target ) const
{	return new PresidentialPardonForm( target );
}
Form*	Intern::makeRobotomyRequestForm( std::string const & target ) const
{	return new RobotomyRequestForm( target );
}
Form*	Intern::makeShrubberyCreationForm( std::string const & target ) const
{	return new ShrubberyCreationForm( target );
}
Form*	Intern::throwException( std::string const & ) const
{	 throw std::out_of_range( "Form not found" );
}
