/*Hanojske kule. Prema staroj indijskoj legendi, posle stvaranja sveta je Bog Brama 
(Brahma) postavio tri dijamantska stuba i na prvi postavio 64 zlatna prstena razlièitih preènika tako 
da svaki naredni bude manji od prethodnog. Sveštenici hrama moraju da prebacuju te prstenove sa 
prvog na treæi stub koristeæi pri tome drugi, all samo jedan po jedan i to tako da se veæi prsten ne 
može naæi iznad manjeg. Kad svi prstenovi budu prebaèeni na treæi stub nastupiæe kraj sveta.*/
#include <iostream>
using namespace std;
//globalna varijabla koja broji ukupan broj potrebnih koraka za n prstenova
int broj_koraka = 0;
//rekurzivna funkcija koja za n prstenova ispisuje redoslijed pomjeranja
void Hanoj(int broj_prstenova, int prvi, int drugi, int treci){
	if(broj_prstenova>0){
		Hanoj(broj_prstenova-1, prvi, treci, drugi); //poziv rekurzivne funkcije
		cout<<"Pocetni stub: "<<prvi<<" | Novi stub: "<<treci<<endl; //ispis koraka
		Hanoj(broj_prstenova-1, drugi, treci, prvi); //poziv rekurzivne funkcije
		broj_koraka++; //povecavanje broja koraka svakim pomjeranjem
	}
}
int main()
{
	int broj_prstenova, prvi=1, drugi=2, treci=3;
	cout<<"Unesite broj prstenova: ";
	cin>>broj_prstenova;
	//ispis koraka pozivanjem funkcije
	cout<<"Rjesenje za "<<broj_prstenova<<" prstenova: "<<endl;
	Hanoj(broj_prstenova,prvi,drugi,treci);
	//ispis broja koraka za n prstenova
	cout<<"Ukupan broj koraka za "<<broj_prstenova<<" prstenova: "<<broj_koraka;
	return 0;
}

