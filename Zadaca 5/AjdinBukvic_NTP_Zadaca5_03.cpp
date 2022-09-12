/*Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure. Potrebno je
èuvati informacije o nazivu robe, broju skladišta, kolièini robe u skladištu, minimalnoj kolièinu
(ako je kolièina robe jednaka ili manja od minimalne kolièine, to znaèi da treba pozvati
dobavljaèa da se obezbijede efikasne zalihe robe), jediniènoj cijeni robe, i imenu dobavljaèa.
Zatim napišite program koji sa tastature èita podatke o robama u skladištu, a nakon toga štampa
izvještaj koji za svaki artikal prikazuje njegov naziv, broj skladišta, kolièinu u skladištu, te ime
dobavljaèa za one artikle èija je kolièina u skladištu manja od dozvoljene kolièine.*/
#include <iostream>
using namespace std;
struct Skladiste{
	char naziv[30];
	int br_skladista;
	int kolicina;
	int min_kolicina;
	float cijena;
	char dobavljac[30];
};
int main()
{
	int n;
	cout<<"Koliko robe zelite unijeti: ";
	cin>>n;
	Skladiste *roba = new Skladiste[n];
	cout<<"Unesite podatka za robu:"<<endl;
	cout<<"--------------------------------------"<<endl;
	cin.ignore();
	int i = 0;
	while(true){
		cout<<"Unesite naziv: ";
		cin.getline(roba[i].naziv,30);
		cout<<"Unesite broj skladista: ";
		cin>>roba[i].br_skladista;
		cout<<"Unesite kolicinu robe: ";
		cin>>roba[i].kolicina;
		cout<<"Unesite minimalnu kolicinu robe: ";
		cin>>roba[i].min_kolicina;
		cout<<"Unesite cijenu robe: ";
		cin>>roba[i].cijena;
		cin.ignore();
		cout<<"Unesite naziv dobavljaca: ";
		cin.getline(roba[i].dobavljac,30);
		i++;
		char nastavak;
		cout<<"Da li zelite unijeti jos robe? D / N"<<endl;
		cin>>nastavak;
		if(nastavak == 'D' || nastavak == 'd'){
			cin.ignore();
			continue;
		}
		else break;
	}
	cout<<"----------Izvjestaj o robi:-----------"<<endl;
	for(int j=0; j<i; j++){
		if(roba[j].kolicina <= roba[j].min_kolicina){
			cout<<"Naziv: "<<roba[j].naziv<<endl;
			cout<<"Broj skladista: "<<roba[j].br_skladista<<endl;
			cout<<"Kolicina: "<<roba[j].kolicina<<endl;
			cout<<"Dobavljac: "<<roba[j].dobavljac<<endl;
			cout<<"--------------------------------------"<<endl;
		}
	}
	delete[] roba;
	roba = NULL;
	return 0;
}
