#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string Name;
		Weapon* Arma;
	
	public:
	HumanB(std::string name);
	~HumanB();
	void Attack();
};

#endif


 // criar função para setar a arma do human
 // na função attack se ele tiver arma inprime a msg 
 // caso não tenha a arma ele vai imprimir que não tem arma


// They also have a member function attack() that displays (of course, without the
// angle brackets):
// <name> attacks with their <weapon type>

// HumanB doesnt takes the Weapon in its constructor
// HumanB may not always have a Weapon.
