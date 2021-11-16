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
	{ "none", NULL }
};

Form*		Intern::makeForm( std::string const & formName,
			                  std::string const & target ) const
{
	size_t i = 0;

	while (i < sizeof(functionsDic) / sizeof(functionsDic[0]) - 1
	       && formName != functionsDic[i].name)
		i++;
	return ( this->*functionsDic[i].function )( target );
}
PresidentialPardonForm*	Intern::makePresidentialPardonForm( std::string const & )
	const
{
	return NULL;
}
