#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hrana.h"

using namespace std;

int main() {

	vector<Hrana> hrany;
	vector<int> sled;        //obsahuje sled, a zaroven aj pouzite vrcholy
	vector<int> zoradene;
	vector<int> vypis;

	//Input file stream
	ifstream subor("graf.txt");
	int v1{ 0 };
	int v2{ 0 };
	int pocetVrcholov{ 0 };
	subor >> pocetVrcholov;
	while (subor >> v1 >> v2) {
		hrany.push_back(Hrana(v1, v2));
	}

	bool stop{ true };

	int zaciatocny{ 0 };
	cout << "===========================================================" << endl;
	cout << "Zadajte zaiatocny vrchol tarryho sledu: ";
	cin >> zaciatocny;
	sled.push_back(zaciatocny);
	int opakovac = 0;
	int pocetKomponentov = 1;

	while (stop)
	{

		for (size_t i = 0; i < hrany.size(); i++)
		{
			if (zaciatocny == hrany.at(i).getHranaV1() || zaciatocny == hrany.at(i).getHranaV2())
			{
				if (hrany.at(i).getStav() != 2) {
					if (!hrany.at(i).getHranaPP()) {         //ak hrana nieje hranaPP
						if (zaciatocny != hrany.at(i).getHranaV1())
						{
							zaciatocny = hrany.at(i).getHranaV1();
						}
						else
						{
							zaciatocny = hrany.at(i).getHranaV2();
						}

						bool nachadzaSa = false;
						for (size_t j = 0; j < sled.size(); j++)    //ak sa aktualny vrchol nenachádza v slede tak nastav hranu ako hranu PP
						{

							if (zaciatocny == sled.at(j))
							{
								nachadzaSa = true;
								break;
							}
						}

						if (!nachadzaSa) {
							sled.push_back(zaciatocny);
							hrany.at(i).setHranaPP();
							hrany.at(i).setStav();   //nastavim stav na 1 èiže hrana bola prejdená raz
							break;
						}
						else
						{
							sled.push_back(zaciatocny);
							hrany.at(i).setStav();
							break;
						}
					}
					else {
						int pomocna{ 0 };
						for (size_t k = 0; k < hrany.size(); k++)
						{

							if (zaciatocny == hrany.at(k).getHranaV1() || zaciatocny == hrany.at(k).getHranaV2())
							{
								if (hrany.at(k).getStav() != 2)
									pomocna++;
							}
						}

						if (pomocna == 1) {
							if (hrany.at(i).getStav() != 2) {
								if (zaciatocny != hrany.at(i).getHranaV1())
								{
									zaciatocny = hrany.at(i).getHranaV1();
								}
								else
								{
									zaciatocny = hrany.at(i).getHranaV2();
								}

			
								pomocna = 0;
								sled.push_back(zaciatocny);
								hrany.at(i).setStav();

							}
						}
					}
				}
			}
		}
		 
		bool haha = false;
		for (size_t i = 0; i < hrany.size(); i++)
		{
			if (hrany.at(i).getStav() == 1) {
				haha = true;
				break;
			}
		}

		bool heh = false;
		if (!haha) {
			for (size_t i = 0; i < hrany.size(); i++)
			{
				if (hrany.at(i).getStav() == 0) {
					zaciatocny = hrany.at(i).getHranaV1();
					pocetKomponentov++;
					sled.push_back(zaciatocny);
					heh = true;
					haha = false;
					if (pocetKomponentov == 2)
					{
						vypis = sled;
					}
					break;
					
				}
				
			}
			if (!heh) { stop = false; }
			
			
		}
		
	}

	bool pompom = false;
	for (size_t x = 0; x < sled.size(); x++)
	{
		for (int h : zoradene)
		{
			if (sled.at(x) == h)
			{
				pompom = true;
			}
		}

		if (!pompom)
			zoradene.push_back(sled.at(x));
	}

	if (pocetKomponentov != 1) {

		cout << "===========================================================" << endl;
		cout << "Tarryho sled: ";
		for (size_t i = 0; i < vypis.size()-1; i++)
		{
			cout << vypis.at(i) << " ";
		}
	}
	else 
	{
		cout << "===========================================================" << endl;
		cout << "Tarryho sled: ";
		for (size_t i = 0; i < sled.size(); i++)
		{
			cout << sled.at(i) << " ";
		}
	}

	cout << endl;

	if (zoradene.size() != pocetVrcholov)
	{
		cout << "===========================================================" << endl;
		cout << "Graf je nesuvisly.";
	}
	else
	{
		cout << "===========================================================" << endl;
		cout << "Graf je suvisly.";
	}
	cout << endl;
	cout << "===========================================================" << endl;
	cout << "Pocet komponentov je: "<<pocetKomponentov<<endl;
	cout << "===========================================================" << endl;

		return 0;
	}