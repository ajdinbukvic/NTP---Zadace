/*Napisati program u kome se èitaju podaci o radnicima iz postojeæe datoteke radnici.txt i kreira niz
struktura tipa radnik (ime, prezime, broj godina radnog staža, stepen struène spreme i plata), a zatim
štampa:
- ukupan broj radnika u datoteci,
- prosjeèna plata radnika,
- broj radnika koji imaju više od 5 godina radnog staža,
- imena radnika sa najvišim stepenom struène spreme,
- spisak radnika sortiranih po imenima.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
struct radnik{
	char ime[20];
	char prezime[20];
	int staz;
	char stepen[20];
	float plata;
};
int main()
{
	int br_radnika = 0;
	int br_staz = 0;
	int br = 0;
	float ukupna_plata = 0;
	radnik *stepen = new radnik[10];
	radnik *sortirano = new radnik[20];
	ifstream ulaz("radnici.txt");
	if(ulaz.is_open()){
		radnik r;
		while(ulaz >> r.ime >> r.prezime >> r.staz >> r.stepen >> r.plata){
			sortirano[br_radnika] = r;
			br_radnika++;
			ukupna_plata += r.plata;
			if(strcmp(r.stepen, "Najvisi") == 0){
				stepen[br] = r;
				br++;
			}
			if(r.staz > 5){
				br_staz++;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();	
	//---------------------------------------------------------------
	cout<<"Broj radnika: "<<br_radnika<<endl;
	cout<<"Prosjecna plata radnika: "<<ukupna_plata / br_radnika<<endl;
	cout<<"Broj radnika koji imaju vise od 5 godina radnog staza: "<<br_staz<<endl;
	cout<<"Imena radnika s najvisim stepenom strucne spreme:"<<endl;
	for(int i = 0; i<br; i++){
		cout<<stepen[i].ime<<endl;
	}
	radnik *temp = new radnik;
	for(int i = 0; i<br_radnika-1; i++){
		for(int j = 0; j<br_radnika-1; j++){
			if(strcmp(sortirano[j].ime, sortirano[j+1].ime) > 0){
				*temp = sortirano[j];
				sortirano[j] = sortirano[j+1];
				sortirano[j+1] = *temp;
			}
		}
	}
	cout<<"Spisak radnika sortiranih po imenima:"<<endl;
	cout<<setw(10)<<"Ime"<<setw(15)<<right<<"Prezime"<<setw(10)<<"Staz"<<setw(10)<<"Stepen"<<setw(10)<<"Plata"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i = 0; i<br_radnika; i++){
		cout<<setw(10)<<sortirano[i].ime<<setw(15)<<right<<sortirano[i].prezime<<setw(10)<<sortirano[i].staz<<setw(10)<<sortirano[i].stepen<<setw(10)<<sortirano[i].plata<<endl;
	}
	delete temp;
	delete[] stepen;
	delete[] sortirano;
	return 0;
}
