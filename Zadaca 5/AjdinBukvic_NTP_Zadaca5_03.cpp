/*Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure. Potrebno je
�uvati informacije o nazivu robe, broju skladi�ta, koli�ini robe u skladi�tu, minimalnoj koli�inu
(ako je koli�ina robe jednaka ili manja od minimalne koli�ine, to zna�i da treba pozvati
dobavlja�a da se obezbijede efikasne zalihe robe), jedini�noj cijeni robe, i imenu dobavlja�a.
Zatim napi�ite program koji sa tastature �ita podatke o robama u skladi�tu, a nakon toga �tampa
izvje�taj koji za svaki artikal prikazuje njegov naziv, broj skladi�ta, koli�inu u skladi�tu, te ime
dobavlja�a za one artikle �ija je koli�ina u skladi�tu manja od dozvoljene koli�ine.*/
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
