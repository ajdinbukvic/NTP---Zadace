/*Napisati program u kome se èitaju podaci o uèenicima iz postojeæe datoteke uèenici.txt i kreira niz
struktura tipa uèenik (ime, prezime, razred (1-4), uspjeh, prosjeèna ocjena), a zatim štampa:
- ukupan broj uèenika u datoteci,
- broj uèenika 4. razreda,
- imena uèenika koji imaju odlièan uspjeh,
- ime uèenika koji ima najbolju prosjeènu ocjenu,
- imena uèenika sortiranih po razredima.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
struct ucenik{
	char ime[20];
	char prezime[20];
	int razred;
	int uspjeh;
	float prosjecna_ocjena;
};
int main()
{
	int br_ucenika = 0;
	int br_cetiri = 0;
	int br = 0;
	int max_ocjena = INT_MIN;
	ucenik *niz = new ucenik[10];
	ucenik *sortirano = new ucenik[20];
	ucenik *najbolja_ocjena = new ucenik;
	ifstream ulaz("ucenici.txt");
	if(ulaz.is_open()){
		ucenik u;
		while(ulaz >> u.ime >> u.prezime >> u.razred >> u.uspjeh >> u.prosjecna_ocjena){
			sortirano[br_ucenika] = u;
			br_ucenika++;
			if(u.razred == 4){
				br_cetiri++;
			}
			if(u.uspjeh == 5){
				niz[br] = u;
				br++;
			}
			if(u.prosjecna_ocjena > max_ocjena){
				max_ocjena = u.prosjecna_ocjena;
				*najbolja_ocjena = u;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	cout<<"Broj ucenika: "<<br_ucenika<<endl;
	cout<<"Broj ucenika 4. razreda: "<<br_cetiri<<endl;
	cout<<"Imena ucenika koji imaju odlican uspjeh:"<<endl;
	for(int i = 0; i<br; i++){
		cout<<niz[i].ime<<endl;
	}
	cout<<"Ime ucenika koji ima najbolju prosjecnu ocjenu: "<<najbolja_ocjena->ime<<endl;
	ucenik *temp = new ucenik;
	for(int i = 0; i<br_ucenika-1; i++){
		for(int j = 0; j<br_ucenika-1; j++){
			if(sortirano[j].razred > sortirano[j+1].razred){
				*temp = sortirano[j];
				sortirano[j] = sortirano[j+1];
				sortirano[j+1] = *temp;
			}
		}
	}
	cout<<"Imena ucenika sortiranih po razredima: "<<endl;
	cout<<setw(10)<<"Ime"<<setw(15)<<right<<"Prezime"<<setw(10)<<"Razred"<<setw(10)<<"Uspjeh"<<setw(10)<<"Prosjek"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	for(int i = 0; i<br_ucenika; i++){
		cout<<setw(10)<<sortirano[i].ime<<setw(15)<<right<<sortirano[i].prezime<<setw(10)<<sortirano[i].razred<<setw(10)<<sortirano[i].uspjeh<<setw(10)<<setprecision(2)<<fixed<<sortirano[i].prosjecna_ocjena<<endl;
	}
	delete temp;
	delete najbolja_ocjena;
	delete[] niz;
	delete[] sortirano;
	return 0;
}
