# include "Visita.h"
#include "Salon.h"
#include "Discaunt.h"


int main()
{
	Salon aux;
	unsigned vreau;
	Client Mihnea;
	std::cout << "\n Hello pres to continue prss the following dates :  \n";
	std::cin >> Mihnea;
	std::cout << "Do you wanna to buy something ? \n 1. Da     2. Nu \n";
	std::cin >> vreau;
	if (vreau==1)
	aux.vizit(Mihnea);
}