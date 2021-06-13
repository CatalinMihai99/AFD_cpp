#include "AFD.h"

std::istream& operator>>(std::istream& citire, AFD& afd)
{
	int nr_stari;
	citire >> nr_stari;
	for (int index = 0; index < nr_stari; index++)
	{
		std::string stare_aux;
		citire >> stare_aux;
		afd.Stari.push_back(stare_aux);
	}


	citire.get();
	getline(citire, afd.Sigma);
	for (int index = 0; index < afd.Sigma.size(); index += 2)
	{
		afd.Sigma_vector.push_back(afd.Sigma[index]);
	}
	citire >> afd.Delta;
	citire >> afd.Stare_initiala;
	int nr_stari_finale;
	citire >> nr_stari_finale;
	for (int index = 0; index < nr_stari_finale; index++)
	{
		std::string finala_aux;
		citire >> finala_aux;
		afd.Final.push_back(finala_aux);
	}
	int nr_tranzitii;
	citire >> nr_tranzitii;
	for (int index = 0; index < nr_tranzitii; index++)
	{
		std::string elem1;
		char elem2;
		std::string elem3;
		citire >> elem1 >> elem2 >> elem3;
		afd.Tranzitii.push_back({ elem1,elem2,elem3 });
	}
	return citire;
}

std::ostream& operator<<(std::ostream& afisare, AFD& afd)
{
	afisare << "STARI :" << "     ";
	for (int index = 0; index < afd.Stari.size(); index++)
	{
		afisare << afd.Stari[index] << " ";
	}
	afisare << std::endl;
	afisare << "SIGMA:   ";
	for (int index = 0; index < afd.Sigma_vector.size(); index++)
	{
		afisare << afd.Sigma_vector[index] << " ";
	}
	afisare << std::endl;
	afisare << "Stare initiala: " << afd.Stare_initiala << std::endl;
	afisare << "DELTA: " << afd.Delta << std::endl;
	afisare << "STARI FINALE: ";
	for (int index = 0; index < afd.Final.size(); index++)
		afisare << afd.Final[index];
	afisare << std::endl;
	afisare << "TRANZITII: " << std::endl;
	for (const auto& index : afd.Tranzitii)
	{
		afisare << std::get<0>(index) << " ";
		afisare << std::get<1>(index) << " ";
		afisare << std::get<2>(index) << std::endl;

	}
	return afisare;
}

void AFD::verificare(std::string cuvant)
{
	std::string stare_curenta = Stare_initiala;
	for (int index = 0; index < cuvant.size(); index++)
	{
		if (stare_curenta == Delta)
		{
			std::cout << "Blocaj";
			return;
		}

		for (const auto& index2 : Tranzitii)
		{
			std::string tuple1 = std::get<0>(index2);
			char tuple2 = std::get<1>(index2);
			std::string tuple3 = std::get<2>(index2);
			if (tuple1 == stare_curenta && tuple2 == cuvant[index])
			{
				stare_curenta = tuple3;
				break;
			}
		}
	}
	for (int index = 0; index < Final.size(); index++)
	{
		if (stare_curenta == Final[index])
		{
			std::cout << "DA";
			return;
		}
	}
	if (stare_curenta == Delta)
	{
		std::cout << "Blocaj";
		return;
	}
	std::cout << "NU";
}
