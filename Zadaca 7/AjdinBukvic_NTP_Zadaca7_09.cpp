/*Neopravdani izostanci u�enika �uvaju se u datoteci Izostanci.txt. Pro�itati ih i napraviti niz. Pomo�u
funkcija izra�unati: ukupan broj izostanaka u odjeljenju, prosje�an broj izostanaka, koliki je najve�i broj i
koliko ima u�enika bez neopravdanih izostanaka.*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void izracunaj_izostanke(int brojac){
	int ukupno = 0;
	float prosjek;
	int max = INT_MIN;
	int bez_neopravdanih = 0;
	ifstream ulaz("Izostanci.txt");
	if(ulaz.is_open()){
		int broj;
		while(ulaz >> broj){
			ukupno += broj;
			if(broj > max){
				max = broj;
			}
			if(broj == 0){
				bez_neopravdanih++;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	//---------------------------------------------------------------
	prosjek = float(ukupno) / brojac;
	cout<<"Broj ucenika: "<<brojac<<endl;
	cout<<"Ukupan broj izostanaka: "<<ukupno<<endl;
	cout<<"Prosjecan broj izostanaka: "<<prosjek<<endl;
	cout<<"Najveci broj izostanaka: "<<max<<endl;
	cout<<"Ucenici bez neopravdanih izostanaka: "<<bez_neopravdanih<<endl;	
}
int main()
{
	int brojac = 0;
	string linija;
	ifstream ulaz("Izostanci.txt");
	if(ulaz.is_open()){
		while(getline(ulaz, linija)){
			brojac++;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	cout<<"Podaci iz datoteke Izostanci..."<<endl;
	izracunaj_izostanke(brojac);
	return 0;
}
