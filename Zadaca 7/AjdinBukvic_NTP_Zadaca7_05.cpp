/*Napisati program u kome se èitaju podaci o klijentima iz postojeæe datoteke klijenti.txt i kreira niz
struktura tipa klijent (ime, prezime, mjesto, telefonski broj i posljednji racun), a zatim štampa:
- ukupan broj klijenata,
- prosjecan raèun za posljednji mjesec,
- broj klijenata iz Zenice,
- ime i broj klijenata sa najvecim raèunom,
- spisak klijenata sortiranih po prezimenu.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
struct klijent{
	char ime[20];
	char prezime[20];
	char mjesto[20];
	char tel_broj[20];
	float racun;
};
int main()
{
	int br_klijenata = 0;
	float ukupan_racun = 0;
	int br_zenica = 0;
	int max_racun = INT_MIN;
	klijent *najveci_racun = new klijent;
	klijent *sortirano = new klijent[20];
	ifstream ulaz("klijenti.txt");
	if(ulaz.is_open()){
		klijent k;
		while(ulaz >> k.ime >> k.prezime >> k.mjesto >> k.tel_broj >> k.racun){
			sortirano[br_klijenata] = k;
			br_klijenata++;
			ukupan_racun += k.racun;
			if(strcmp(k.mjesto, "Zenica") == 0){
				br_zenica++;
			}
			if(k.racun > max_racun){
				max_racun = k.racun;
				*najveci_racun = k;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	cout<<"Broj klijenata: "<<br_klijenata<<endl;
	cout<<"Prosjecan racun za posljednji mjesec: "<<ukupan_racun / br_klijenata<<endl;
	cout<<"Broj klijenata iz Zenice: "<<br_zenica<<endl;
	cout<<"Ime i broj klijenta s najvecim racunom: "<<najveci_racun->ime<<" | "<<najveci_racun->tel_broj<<endl;
	klijent *temp = new klijent;
	for(int i = 0; i<br_klijenata-1; i++){
		for(int j = 0; j<br_klijenata-1; j++){
			if(strcmp(sortirano[j].prezime, sortirano[j+1].prezime) > 0){
				*temp = sortirano[j];
				sortirano[j] = sortirano[j+1];
				sortirano[j+1] = *temp;
			}
		}
	}
	cout<<"Spisak klijenata sortiranih po prezimenima:"<<endl;
	cout<<setw(10)<<"Ime"<<setw(10)<<right<<"Prezime"<<setw(10)<<"Mjesto"<<setw(15)<<"Broj"<<setw(10)<<"Racun"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i = 0; i<br_klijenata; i++){
		cout<<setw(10)<<sortirano[i].ime<<setw(10)<<right<<sortirano[i].prezime<<setw(10)<<sortirano[i].mjesto<<setw(15)<<sortirano[i].tel_broj<<setw(10)<<sortirano[i].racun<<endl;
	}
	delete temp;
	delete najveci_racun;
	delete[] sortirano;
	return 0;
}
