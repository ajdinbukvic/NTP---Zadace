/*Napisati funkciju koja raèuna prosjeènu vrednost niza cjelih brojeva i broj elemenata jednakih 5. Glavna
funkcija koristi datoteku Ocjene.txt u kojoj se èuva broj uèenika u odeljenju (u prvom redu) i u svakom
sljedeæem: ime uèenika, prezime, strani jezik koji uèi (engleski/njemaèki) i ocjena. Štampati prosjecne
ocjene iz engleskog i njemaèkog i broj petica iz oba jezika.*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct ucenik{
	char ime[20];
	char prezime[20];
	char jezik[20];
	int ocjena;
};
void izracunaj_prosjek_petice(){
	int br_ucenika = 0;
	int petice_eng = 0;
	int petice_njem = 0;
	int ocjene_eng = 0;
	int ocjene_njem = 0;
	int eng = 0;
	int njem = 0;
	float prosjek_eng;
	float prosjek_njem;
	ifstream ulaz("Ocjene.txt");
	if(ulaz.is_open()){
		string linija;
		ucenik u;
		getline(ulaz, linija);
		br_ucenika = stoi(linija);
		while(ulaz >> u.ime >> u.prezime >> u.jezik >> u.ocjena){
			if(strcmp(u.jezik, "Engleski") == 0){
				ocjene_eng += u.ocjena;
				eng++;
			}
			if(strcmp(u.jezik, "Engleski") == 0 && u.ocjena == 5){
				petice_eng++;
			}
			if(strcmp(u.jezik, "Njemacki") == 0){
				ocjene_njem += u.ocjena;
				njem++;
			}
			if(strcmp(u.jezik, "Njemacki") == 0 && u.ocjena == 5){
				petice_njem++;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	//---------------------------------------------------------------
	prosjek_eng = float(ocjene_eng) / eng;
	prosjek_njem = float(ocjene_njem) / njem;
	cout<<"Ukupno ucenika: "<<br_ucenika<<endl;
	cout<<"Broj ucenika koji uce engleski: "<<eng<<endl;
	cout<<"Broj ucenika koji uce njemacki: "<<njem<<endl;
	cout<<"Prosjecna ocjena iz engleskog: "<<prosjek_eng<<endl;
	cout<<"Prosjecna ocjena iz njemackog: "<<prosjek_njem<<endl;
	cout<<"Ukupno petica iz engleskog: "<<petice_eng<<endl;
	cout<<"Ukupno petica iz njemackog: "<<petice_njem<<endl;	
}
int main()
{
	cout<<"Podaci iz datoteke Ocjene..."<<endl;
	izracunaj_prosjek_petice();
	return 0;
}
