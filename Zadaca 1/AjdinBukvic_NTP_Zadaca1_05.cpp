/*Napisati rekurzivnu funkciju koja nalazi sumu niza realnih brojeva 1 / n(n+1)(n+2),
pri èemu se sumiranje vrši do prvog èlana koji je manji od uèitane vrednosti x=10e-3.*/
#include <iostream>
using namespace std;
//globalno definisana konstanta koja predstavlja ucitanu vrijednost
const float e = 1./1000;
//globalno definisana varijabla koja predstavlja sumu
float s = 0;
//funkcija koja za proslijedjeni broj racuna vrijednost trazene formule
float formula(float n){
	return 1. / (n*(n+1)*(n+2));
}
//rekurzivna funkcija koja za proslijedjeni broj vraca sumu svih brojeva koji ispunjavaju uslov
float suma_brojeva(float n){
	if(formula(n)<e) return s; //ako vrijednost formule postane manja od ucitane vrijednosti vraca se izracunata suma
	else {
		s += formula(n); //povecavanje sume na osnovu vrijednosti izracunate formule za n
		return s+suma_brojeva(n+1); //poziv funkcije sve za n+1 sve dok vrijednost formule ne bude manja od ucitane vrijednosti
	}
}
int main()
{
	/*NAPOMENA:
	najveci broj za koji formula ispunjava uslov da je suma veca od ucitane vrijednosti je 9*/
	float n;
	cout<<"Unesite broj: ";
	cin>>n;
	//ako je suma brojeva veca od ucitane vrijednosti ispisuje sumu
	if(suma_brojeva(n)>e) cout<<"Suma niza realnih brojeva koja je manja od ucitane vrijednosti je: "<<suma_brojeva(n);
	//ako je suma manja ispisuje odgovarajucu poruku
	else cout<<"Suma je manja od ucitane vrijednosti.";
	return 0;
}

