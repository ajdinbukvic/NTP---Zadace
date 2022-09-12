/*Napravite program koji raèuna period izmeðu dva datuma. Pri unosu testirajte
ispravnost unesenog datuma. U realizaciji programa koristite funkcije.
Napomena: Prilikom provjere ispravnosti datuma pazite na prestupne godine. U
prestupnoj godini februar ima 29 dana, a inaèe 28. Prestupna je godina koja je djeljiva
sa 4 (npr. 2004, 2008, 1996...) osim onih koje su djeljive sa 100 (npr. 1900, 2100...),
ali su godine djeljive sa 400 ipak prestupne (npr. 2000).
Primjer:
Unesite prvi datum (d,m,g): 31,13,2006 Neispravan datum! Unesite prvi datum
(d,m,g): 31,12,2006 Unesite drugi datum (d,m,g): 2,1,2007 Izmedju datuma je
proteklo 2 dana*/
#include <iostream>
#include <cmath>
using namespace std;
//struktura datum koja se sastoji od dana, mjeseca i godine
struct Datum{
	int d;
	int m;
	int g;
};
//funkcija koja provjerava da li je prosljednjena godina prestupna ili nije
bool prestupna(int godina){
	if(godina%4==0 && godina%100!=0 || godina%400==0) return true;
	else return false;
}
//funkcija koja provjerava da li je proslijedjeni datum ispravan ili nije
bool provjera_datuma(Datum *datum){
	int dani_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //niz u kojem su smjesteni dani za svaki mjesec
	bool ispravan = true; //pomocna varijabla koja ispituje tacnost datuma
	if(datum->d < 1 || datum->m < 1 || datum->m > 12 || datum->g < 1) ispravan = false; //provjera osnovnih uvjeta za d,m,g
	if(datum->d > dani_u_mjesecu[datum->m-1]) ispravan = false; //provjera da li je dan veci od broja dana u tom mjesecu
	if(datum->m == 2){ //poseban slucaj kada je u pitanju drugi mjesec
		if(datum->d == 29 && prestupna(datum->g)) ispravan = true; //ako je broj dana 29 i godina prestupna
	}
	return ispravan; //vraca true ili false vrijednost u ovisnosti od tacnosti datuma
}
//funkcija koja racuna broj proteklih dana izmedju dva unesena datuma
int proteklo_dana(Datum *d1, Datum *d2){
	int br_dana_d1 = 0; //pomocna varijabla u koju se smjesta broj dana prvog datuma
	int br_dana_d2 = 0; //pomocna varijabla u koju se smjesta broj dana drugog datuma
	int razlika; //razlika u danima izmedju prvog i drugog datuma
	int dani_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //niz u kojem su smjesteni dani za svaki mjesec
	//===============RACUNANJE BROJA DANA ZA PRVI DATUM========================
	for(int i=1; i<d1->g; i++){
		if(prestupna(i)) br_dana_d1 += 366;
		else br_dana_d1 += 365;
	}
	for(int i=1; i<d1->m; i++){
		br_dana_d1 += dani_u_mjesecu[i-1];
	}
	br_dana_d1 += d1->d;
	//===============RACUNANJE BROJA DANA ZA DRUGI DATUM=======================
	for(int i=1; i<d2->g; i++){
		if(prestupna(i)) br_dana_d2 += 366;
		else br_dana_d2 += 365;
	}
	for(int i=1; i<d2->m; i++){
		br_dana_d2 += dani_u_mjesecu[i-1];
	}
	br_dana_d2 += d2->d;
	//oduzimanje broja dana prvog datuma od drugog (moze i obrnuto jer se koristi abs funckija)
	razlika = abs(br_dana_d1 - br_dana_d2);
	return razlika; //vraca protekli broj dana
}
int main()
{
	Datum *d1 = new Datum; //dinamicki alociran prvi datum tipa Datum
	Datum *d2 = new Datum; //dinamicki alociran drugi datum tipa Datum
	do{ //unos datuma sve dok se ne unese ispravan datum
		cout<<"Unesite prvi datum (D M G): ";
		cin>>d1->d>>d1->m>>d1->g;
		if(!provjera_datuma(d1)) cout<<"Neispravan datum!"<<endl; //provjerava se ispravnost datuma na osnovu date funkcije
	} 
	while(!provjera_datuma(d1));
	do{ //unos datuma sve dok se ne unese ispravan datum
		cout<<"Unesite drugi datum (D M G): ";
		cin>>d2->d>>d2->m>>d2->g;
		if(!provjera_datuma(d2)) cout<<"Neispravan datum!"<<endl; //provjerava se ispravnost datuma na osnovu date funkcije
	}
	while(!provjera_datuma(d2));
	int br_dana = proteklo_dana(d1,d2); //varijabla u koju se smjesta rezultat funkcije koja racuna protekli broj dana 
	cout<<"Izmedju dva datuma je proteklo: "<<br_dana<<" dana."<<endl; //ispis razlike izmedju dva datuma
	delete d1; //brisanje dinamicki alocirane memorije za prvi datum
	delete d2; //brisanje dinamicki alocirane memorije za drugi datum
	return 0;
}
