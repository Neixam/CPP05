#include <fstream>
#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree("                                                         .\n"
											   "                                              .         ;  \n"
											   "                 .              .              ;%     ;;   \n"
											   "                   ,           ,                :;%  %;   \n"
											   "                    :         ;                   :;%;'     .,   \n"
											   "           ,.        %;     %;            ;        %;'    ,;\n"
											   "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
											   "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
											   "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
											   "                `%;.     ;%;     %;'         `;%%;.%;'\n"
											   "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
											   "                    `:%;.  :;bd%;          %;@%;'\n"
											   "                      `@%:.  :;%.         ;@@%;'   \n"
											   "                        `@%.  `;@%.      ;@@%;         \n"
											   "                          `@%%. `@%%    ;@@%;        \n"
											   "                            ;@%. :@%%  %@@%;       \n"
											   "                              %@bd%%%bd%%:;     \n"
											   "                                #@%%%%%:;;\n"
											   "                                %@@%%%::;\n"
											   "                                %@@@%(o);  . '         \n"
											   "                                %@@@o%;:(.,'         \n"
											   "                            `.. %@@@o%::;         \n"
											   "                               `)@@@o%::;         \n"
											   "                                %@@(o)::;        \n"
											   "                               .%@@@@%::;         \n"
											   "                               ;%@@@@%::;.          \n"
											   "                              ;%@@@@%%:;;;. \n"
											   "                          ...;%@@@@@%%:;;;;,..    Gilo97");

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm()
		: Form("undefined", 145, 137), _target("undefined")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oth)
		: Form(oth), _target(oth._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oth)
{
	if (this == &oth)
		return *this;
	_target = oth._target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target)
		:	Form(name, 145, 137), _target(target)
{}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	tryToExec(executor.getGrade());
	std::ofstream out((_target + "_shrubbery").c_str());

	if (!out)
	{
		std::cerr << " can't open " << _target << "_shrubbery" << std::endl;
		return;
	}
	out << _tree << std::endl;
	out.close();
}