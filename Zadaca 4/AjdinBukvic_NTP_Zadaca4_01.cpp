/*Napraviti funkciju sa sljedeæim prototipom:
int ispravna(char *adresa)
Funkcija vraæa vrijednost 1 ako primljeni string predstavlja ispravnu email adresu iz Bosne i
Hercegovine, a u suprotnom vraæa 0. Radi jednostavnosti, primijenite sljedeæe testove:
• u stringu se nalazi taèno jedan znak @
• posljednja tri karaktera stringa su ".ba"
Ukoliko jedan od testova nije zadovoljen, funkcija vraæa 0.*/
#include <iostream>
using namespace std;
//funkcija koja provjerava unesenu email adresu
bool ispravna(char *adresa){ //prosljedjen pokazivac na unesenu adresu
	bool postoji = false; //varijabla koja sluzi za provjeru da li postoji znak @
	char *p; //pokazivac
	p=adresa; //inicijalizacija pokazivaca na unesenu adresu
	while (*p!='\0'){ //petlja koja provjerava sve znakove adrese
 		if(*p=='@') postoji = true; //ako je pronadjen znak @ varijabla postaje true
		p++; //povecavanje brojaca za pokazivac
	}
 	if(postoji==true && *(p-3)=='.' && *(p-2)=='b' && *(p-1)=='a') return true; //ako su ispunjeni svi uvjeti vraca true
 	else return false; //ako samo jedan od uvjeta nije ispunjen vraca false
}
int main()
{
	char adresa[100];
	cout<<"Unesite email adresu: ";
	cin>>adresa;
	if(ispravna(adresa)) cout<<"Unesena email adresa je ispravna!"; //provjerava se da li je unesena email adresa ispravna, ako jeste ispisuje poruku da je ispravna
	else cout<<"Unesena email adresa nije ispravna!"; //u slucaju da email adresa nije ispravna ispisuje poruku da nije ispravna
	return 0;
}
