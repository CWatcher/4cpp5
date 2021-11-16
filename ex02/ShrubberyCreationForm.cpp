#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target )
	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( "ShrubberyCreation", target, 145, 137 )
{}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
 	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( src )
{}

void	ShrubberyCreationForm::executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException )
{
	std::string const static tree = "\
		 #  \n\
		#|# \n\
		 V  \n\
		 I";

	std::ofstream 	f( ( _target + "_shrubbery" ).c_str() );
	for ( int i = 0; i < 3; i++ )
		f << tree << std::endl << std::endl;
}
