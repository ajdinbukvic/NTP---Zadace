/*Kreiranje tekstualne datoteke „Podaci.txt“ u radnom direktorijumu i upis jednog reda koji sadrži: ime,
pol, godište i prosjek. Omoguciti dodavanje novih podataka u datoteku. Odrediti broj ženskih osoba i
osoba sa prosjekom veæim od 4.50 u datoteci Podaci.txt.*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct osoba{
	char ime[20];
	char spol[10];
	int godiste;
	float prosjek;
};
int main()
{
	int br_zena = 0;
	int br_prosjek = 0;
	cout<<"Unos u datoteku:"<<endl;
	ofstream izlaz("Podaci.txt", ios::app);
	if(izlaz.is_open()){
		osoba o;
		while(true){
		cout<<"Unesite ime: ";
		cin.getline(o.ime,20);
		do{ 
			cout<<"Unesite spol (musko / zensko): ";
			cin.getline(o.spol, 10);	
		}
		while(strcmp(o.spol,"zensko")!=0 && strcmp(o.spol,"musko")!=0);
		cout<<"Unesite godiste: ";
		cin>>o.godiste;
		cout<<"Unesite prosjek: ";
		cin>>o.prosjek;
		cin.ignore();
		izlaz << o.ime << " " << o.spol << " " << o.godiste << " " << o.prosjek << endl;
		char nastavak;
		cout<<"Da li zelite unijeti jos osoba? D / N: ";
		cin>>nastavak;
		if(nastavak == 'D' || nastavak == 'd'){
			cin.ignore();
			continue;
		}
		else break;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	izlaz.close();
	//---------------------------------------------------------------
	ifstream ulaz("Podaci.txt");
	if(ulaz.is_open()){
		osoba o;
		while(ulaz >> o.ime >> o.spol >> o.godiste >> o.prosjek){
			if(strcmp(o.spol, "zensko") == 0){
				br_zena++;
			}
			if(o.prosjek > 4.5){
				br_prosjek++;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"Podaci iz datoteke:"<<endl;
	cout<<"Broj zenskih osoba: "<<br_zena<<endl;
	cout<<"Broj osoba s prosjekom vecim od 4.5: "<<br_prosjek<<endl;
	return 0;
}
