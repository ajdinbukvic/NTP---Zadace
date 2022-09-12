/*Napisati funkciju koja odreðuje srednju vrijednost niza realnih brojeva tipa double. Vraæeni
rezultat treba da je tipa double. Broj elemenata niza prenosi se kao parametar funkcije. Svaki
element niza treba zamjeniti razlikom u odnosu na srednju vrijednost. Testirati funkciju u
odgovarajuæem programu gde korisnik može da unese odreðen broj elemenata preko
terminala. Postoji ogranièenje od maksimalno 20 brojeva, s tim što korisnik može izabrati da
unese manje. Funkcija treba da ima oblik:
double srv_niza(double num[], int n);*/
#include <iostream>
using namespace std;
//funckija za unos niza
void unos(double num[], int n){
	cout<<"Unesite elemente niza: "<<endl;
	for(int i = 0; i < n; i++){ //petlja koja ide do n clanova koliko je korisnik unio
		cout<<"["<<i+1<<"] clan: "; //unosi svaki clan uvecan za 1 radi ljepseg pregleda korisniku
		cin>>num[i];
	}
}
//funkcija koja racuna srednju vrijednost prosljedjenog niza
double srv_niza(double num[], int n){
	double suma = 0; //varijabla suma u koju ce se smjestati zbir svih clanova niza
	for(int i = 0; i < n; i++){ //petlja koja ide do n clanova koliko je korisnik unio
		suma += num[i]; //povecavanje vrijednosti varijable suma za svaki i-ti clan niza
	}
	return suma / n; //funckija vraca sumu podijeljenu s ukupnim brojem clanova niza
}
//funkcija koji prima pokazivac na niz
void zamjeni(double *num, int n, double sredina){
	for(int i = 0; i < n; i++){ //petlja koja ide do n clanova koliko je korisnik unio
		*(num+i) -= sredina; //od svakog i-tog clana niza se oduzima srednja vrijednost niza
	}
}
//funkcija za ispis niza
void ispis(double num[], int n){
	cout<<"Clanovi niza nakon oduzimanja od sredine: "<<endl;
	for(int i = 0; i < n; i++){ //petlja koja ide do n clanova koliko je korisnik unio
		cout<<"["<<i+1<<"] clan: "<<num[i]<<endl; //ispisuje svaki clan uvecan za 1 radi ljepseg pregleda korisniku
	}
}
int main()
{
	int n;
	cout<<"Unesite koliko zelite brojeva: ";
	cin>>n;
	double niz[n]; //kreiranje novog niza sa n clanova koliko je korisnik unio
	unos(niz,n); //poziv funkcije za unos niza
	double sredina = srv_niza(niz,n); //varijabla u koju se smjesta rezultat funckije za racunanje sredine
	cout<<"Srednja vrijednost unesenog niza je: "<<sredina<<endl; //ipis sredine niza
	zamjeni(niz,n,sredina); //poziv funckije za oduzimanje svakog clana niza sa sredinom
	ispis(niz,n); //ispis clanova niza nakon oduzimanja
	return 0;
}

