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
Form*		Intern::makeForm( std::string const &,
			                  std::string const & target ) const
{
	return new PresidentialPardonForm( target );
}
