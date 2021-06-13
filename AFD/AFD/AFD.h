#pragma once
#include <tuple>
#include<vector>
#include<iostream>
#include<string>
#include<fstream>

class AFD
{
private:
	std::vector<std::string> Stari;
    std::string Sigma;
	std::vector<char> Sigma_vector;
	std::string Stare_initiala;
	std::string Delta;
	std::vector<std::tuple<std::string, char, std::string>> Tranzitii;
	std::vector<std::string> Final;
	
public:
	void verificare(std::string cuvant);
	friend std::istream& operator>>(std::istream& citire, AFD& afd);
	friend std::ostream& operator<<(std::ostream& afisare,AFD& afd);

};

