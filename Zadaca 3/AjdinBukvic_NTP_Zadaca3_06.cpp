/*Napraviti program za evidenciju studenata na Politehnièkom fakultetu. Potrebna su
dva niza struktura od kojih æe jedan sadržavati podatke o studentima (max 100 elemenata), 
a drugi podatke o ocjenama studenata (max 1000 elemenata). Izgled struktura je:
struct student{
char ime[20];
char prezime [30];
int index;
};
struct ocjena{
int indeks;
int br_predmeta;
int ocjena;
};
U programu treba omoguæiti:
1. Unos studenta (sprjeèiti unos duplog indeksa)
2. Ispis svih studenata
3. Ispis jednog studenta i svih predmeta i ocjena koje je taj student dobio na osnovu
unesenog broja indeksa, te prosjek studenta
4. Ispis svih studenata koji iz nekog predmeta imaju ocjenu veæu od neke zadane ocjene.
Korisnik unosi putem tastature predmet i željenu minimalnu ocjenu.*/
#include <iostream>
#include <string.h>
using namespace std;
#define max_studenata 100
#define max_ocjena 1000
int br_studenata = 0;
struct student{
	char ime[20];
	char prezime [30];
	int index;
};
struct ocjena{
	int indeks;
	char naziv_predmeta[30]; //int br_predmeta;
	int ocjena;
};
void info(){
	cout<<"0 - IZLAZ"<<endl;
	cout<<"1 - Unos studenta"<<endl;
	cout<<"2 - Ispis svih studenata"<<endl;
	cout<<"3 - Ispis jednog studenta na osnovu broja indeksa"<<endl;
	cout<<"4 - Ispis svih studenata na osnovu predmeta i ocjene"<<endl;
}
bool provjera_index(student studenti[], int br_studenata, int postojeci_index){
	for(int i=0; i<br_studenata; i++){
		if(studenti[i].index==postojeci_index) return true;
	}
	return false;
}
void unos_studenta(student studenti[], ocjena ocjene[], int &br_studenata){
	cout<<"Ime: ";
	cin>>studenti[br_studenata].ime;
	cout<<"Prezime: ";
	cin>>studenti[br_studenata].prezime;
	do{
		cout<<"Index: ";
		cin>>studenti[br_studenata].index;
		if(provjera_index(studenti,br_studenata,studenti[br_studenata].index)) cout<<"Unijeli ste vec postojeci broj indeksa!"<<endl;
	}
	while(provjera_index(studenti,br_studenata,studenti[br_studenata].index));
	ocjene[br_studenata].indeks = studenti[br_studenata].index;
	cin.ignore();
	cout<<"Naziv predmeta: ";
	cin.getline(ocjene[br_studenata].naziv_predmeta, 30);
	do{
		cout<<"Ocjena: ";
		cin>>ocjene[br_studenata].ocjena;
		if(ocjene[br_studenata].ocjena < 5 || ocjene[br_studenata].ocjena > 10) cout<<"Ocjena mora biti u intervalu 5-10!"<<endl;
	}
	while(ocjene[br_studenata].ocjena < 5 || ocjene[br_studenata].ocjena > 10);
	br_studenata++;
}
void ispis_svih_studenata(student studenti[], int br_studenata){
	if(br_studenata==0) cout<<"Nema unesenih studenata!"<<endl;
	else{
		cout<<"Podaci o studentima: "<<endl;
		cout<<"----------------------------------"<<endl;
		for(int i=0; i<br_studenata; i++){
			cout<<"Ime: "<<studenti[i].ime<<endl;
			cout<<"Prezime: "<<studenti[i].prezime<<endl;
			cout<<"Index: "<<studenti[i].index<<endl;
			cout<<"----------------------------------"<<endl;
		}
	}
}
bool provjera_indeksa(ocjena ocjene[], int br_studenata, int novi_unos){
	for(int i=0; i<br_studenata; i++){
		if(ocjene[i].indeks==novi_unos) return true;
	}
	return false;
}
int provjera_unos(ocjena ocjene[], int br_studenata, int novi_unos){
	for(int i=0; i<br_studenata; i++){
		if(ocjene[i].indeks==novi_unos) return i;
	}
}
void unos_indeksa(ocjena ocjene[], int br_studenata){
	int unos;
	do{
		cout<<"Unesite broj indeksa: ";
		cin>>unos;
		if(!provjera_indeksa(ocjene,br_studenata,unos)) cout<<"Unijeli ste nepostojeci broj indeksa!"<<endl;
	}
	while(!provjera_indeksa(ocjene,br_studenata,unos));
	int temp = provjera_unos(ocjene,br_studenata,unos);
	cout<<"Naziv predmeta: "<<ocjene[temp].naziv_predmeta<<endl;
	cout<<"Ocjena: "<<ocjene[temp].ocjena<<endl;
}
bool provjera_predmeta(ocjena ocjene[], int br_studenata, char unos_predmet[30]){
	for(int i=0; i<br_studenata; i++){
		if(strcmp(ocjene[i].naziv_predmeta,unos_predmet) == 0) return true;
	}
	return false;
}
void unos_predmeta_ocjene(ocjena ocjene[], int br_studenata){
	char unos_predmet[30]; 
	int unos_ocjena;
	cin.ignore();
	cout<<"Unesite naziv predmeta: ";
	cin.getline(unos_predmet, 30);
	do{
		cout<<"Unesite minimalnu ocjenu: ";
		cin>>unos_ocjena;
		if(unos_ocjena < 5 || unos_ocjena > 10) cout<<"Ocjena mora biti u intervalu 5-10!"<<endl;
	}
	while(unos_ocjena < 5 || unos_ocjena > 10);
	if(!provjera_predmeta(ocjene,br_studenata,unos_predmet)) cout<<"Unijeli ste nepostojeci naziv predmeta!"<<endl;
	else{
		cout<<"Studenti koji iz unesenog predmeta imaju vecu ocjenu: "<<endl;
		for(int i=0; i<br_studenata; i++){
			if(strcmp(ocjene[i].naziv_predmeta,unos_predmet) == 0)
				if(ocjene[i].ocjena > unos_ocjena)
					cout<<"Indeks: "<<ocjene[i].indeks<<endl;
		}
	}
}
int main()
{
	int opcija;
	student studenti[max_studenata];
	ocjena ocjene[max_ocjena];
	do{
		cout<<"Unesite opciju koju zelite: "<<endl;
		info();
		cin>>opcija;
		system("cls");
		if(opcija==1){
			unos_studenta(studenti,ocjene,br_studenata);
			system("pause");
			system("cls");
		}
		if(opcija==2){
			ispis_svih_studenata(studenti,br_studenata);
			system("pause");
			system("cls");
		}
		if(opcija==3){
			unos_indeksa(ocjene,br_studenata);
			system("pause");
			system("cls");
		}
		if(opcija==4){
			unos_predmeta_ocjene(ocjene,br_studenata);
			system("pause");
			system("cls");
		}
	}
	while(opcija != 0);
	return 0;
}
