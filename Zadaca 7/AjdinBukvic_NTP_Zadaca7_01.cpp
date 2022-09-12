/*Napisati program u kome se èitaju podaci o proizvodima u jednoj prodavnici auto-djelova iz postojeæe
datoteke proizvodi.txt i kreira niz struktura tipa proizvod ( naziv, proizvoðaè, cjena, kolièina),a zatim
štampa:
- ukupan broj proizvoda u datoteci,
- ukupna vrijednost svih proizvoda u prodavnici,
- spisak proizvoda èija je kolièina 0,
- broj proizvoda koje proizvodi FIAT,
- spisak proizvoda sortiranih po cjeni.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
struct proizvod{
	char naziv[20];
	char proizvodjac[20];
	float cijena;
	int kolicina;
};
int main()
{
	int br_proizvoda = 0;
	float ukupna_cijena = 0;
	int fiat = 0;
	int br = 0;
	proizvod *niz = new proizvod[10];
	proizvod *sortirano = new proizvod[20];
	ifstream ulaz("proizvodi.txt");
	if(ulaz.is_open()){
		proizvod p;
		while(ulaz >> p.naziv >> p.proizvodjac >> p.cijena >> p.kolicina){
			sortirano[br_proizvoda] = p;
			br_proizvoda++;
			ukupna_cijena += p.cijena;
			if(strcmp(p.proizvodjac, "FIAT") == 0){
				fiat++;
			}
			if(p.kolicina == 0){
				niz[br] = p;
				br++;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	cout<<"Broj proizvoda: "<<br_proizvoda<<endl;
	cout<<"Ukupna vrijednost proizvoda: "<<ukupna_cijena<<endl;
	cout<<"Broj proizvoda koje proizvodi FIAT: "<<fiat<<endl;
	cout<<"Proizvodi kod kojih je kolicina 0:"<<endl;
	for(int i = 0; i<br; i++){
		cout<<niz[i].naziv<<" "<<niz[i].proizvodjac<<" "<<niz[i].cijena<<" "<<niz[i].kolicina<<endl;
	}
	proizvod *temp = new proizvod;
	for(int i = 0; i<br_proizvoda-1; i++){
		for(int j = 0; j<br_proizvoda-1; j++){
			if(sortirano[j].cijena > sortirano[j+1].cijena){
				*temp = sortirano[j];
				sortirano[j] = sortirano[j+1];
				sortirano[j+1] = *temp;
			}
		}
	}
	cout<<"Proizvodi sortirani po cijeni: "<<endl;
	cout<<setw(10)<<"Naziv"<<setw(15)<<right<<"Proizvodjac"<<setw(15)<<"Cijena"<<setw(15)<<"Kolicina"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i = 0; i<br_proizvoda; i++){
		cout<<setw(10)<<sortirano[i].naziv<<setw(15)<<right<<sortirano[i].proizvodjac<<setw(15)<<sortirano[i].cijena<<setw(10)<<sortirano[i].kolicina<<endl;
	}
	delete[] niz;
	delete[] sortirano;
	delete temp;
	return 0;
}
