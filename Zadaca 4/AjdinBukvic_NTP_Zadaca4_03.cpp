/*Napisati funkciju koja odreðuje dužinu stringa. Ime funkcije treba da bude kel_strlen. Funkcija
treba da ima oblik:
unsigned kel_strlen(char *str);*/
#include <iostream>
using namespace std;
//funckija koja prima pokazivac na uneseni string
unsigned kel_strlen(char *str){
	int duzina = 0; //postavljanje duzine na 0 kako bi se za svaki znak mogla povecavati za 1
	while(*str != '\0'){ //petlja koja se ponavlja sve dok postoji jos unesenih znakova
		duzina++; //povecavanje broja duzine
		str++; //povecavanje pokazivaca na string
	}
	return duzina; //funkcija na kraju vraca ukupan broj znakova
}
int main()
{
	char str[100];
	cout<<"Unesite string: ";
	cin.getline(str, 100); //omogucava se unos vise rijeci, odnosno racuna se i razmak izmedju rijeci
	cout<<"Duzina unesenog stringa je: "<<kel_strlen(str); //poziv funkcije kel_strlen i ispis broja znakova unesenog stringa
	return 0;
}

