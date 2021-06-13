#include<iostream>
#include"AFD.h"
#include<fstream>
int main()
{

	AFD afd;
	std::ifstream f("Text.txt");
	f >> afd;
	std::cout << afd;
	std::cout << std::endl;

	std::string decizie;
	
	std::cout << "Vreti sa cititi un cuvant?";
	std::cin >> decizie;
	while (decizie == "da")
		{
			
			
			std::string cuvant;
			std::cout << "Cititi un cuvant" << std::endl;
			std::cin >> cuvant;
			afd.verificare(cuvant);
			std::cout << std::endl;
			std::cout << "Vreti sa cititi un cuvant?";
			std::cin >> decizie;
		}


	return 0;
}