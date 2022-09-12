/*Napisati program u kome se èitaju podaci o apartmana jedne turistièke agencije iz postojeæe datoteke
apartmani.txt i kreira niz struktura tipa apartman ( naziv, mjesto, broj kreveta, cjena), a zatim štampa:
- ukupan broj apartmana u datoteci,
- prosjeèna cjena apartmana u toj agenciji,
- broj apartmana u mjestu Paralia,
- naziv apartmana za 2 osobe sa najmanjom cjenom,
- spisak apartmana sortiranih po cjeni.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
struct apartman{
	char naziv[20];
	char mjesto[20];
	int br_kreveta;
	float cijena;
};
int main()
{
	int br_apartmana = 0;
	float ukupna_cijena = 0;
	int paralia = 0;
	int min_cijena = INT_MAX;
	apartman *najmanja_cijena = new apartman;
	apartman *sortirano = new apartman[20];
	ifstream ulaz("apartmani.txt");
	if(ulaz.is_open()){
		apartman a;
		while(ulaz >> a.naziv >> a.mjesto >> a.br_kreveta >> a.cijena){
			sortirano[br_apartmana] = a;
			br_apartmana++;
			ukupna_cijena += a.cijena;
			if(strcmp(a.mjesto, "Paralia") == 0){
				paralia++;
			}
			if(a.br_kreveta == 2 && a.cijena < min_cijena){
				min_cijena = a.cijena;
				*najmanja_cijena = a;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();	
	//---------------------------------------------------------------
	cout<<"Broj apartmana: "<<br_apartmana<<endl;
	cout<<"Prosjecna cijena apartmana: "<<ukupna_cijena / br_apartmana<<endl;
	cout<<"Broj apartmana u mjestu Paralia: "<<paralia<<endl;
	cout<<"Naziv apartmana s 2 kreveta i najmanjom cijenom: "<<najmanja_cijena->naziv<<endl;
	apartman *temp = new apartman;
	for(int i = 0; i<br_apartmana-1; i++){
		for(int j = 0; j<br_apartmana-1; j++){
			if(sortirano[j].cijena > sortirano[j+1].cijena){
				*temp = sortirano[j];
				sortirano[j] = sortirano[j+1];
				sortirano[j+1] = *temp;
			}
		}
	}
	cout<<"Apartmani sortirani po cijeni:"<<endl;
	cout<<setw(10)<<"Naziv"<<setw(15)<<right<<"Mjesto"<<setw(20)<<"Broj kreveta"<<setw(10)<<"Cijena"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i = 0; i<br_apartmana; i++){
		cout<<setw(10)<<sortirano[i].naziv<<setw(15)<<right<<sortirano[i].mjesto<<setw(15)<<sortirano[i].br_kreveta<<setw(15)<<sortirano[i].cijena<<endl;
	}
	delete najmanja_cijena;
	delete temp;
	delete[] sortirano;
	return 0;
}
