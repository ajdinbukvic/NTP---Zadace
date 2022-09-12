/*Napisati funkciju koja obræe proizvoljan string (kel_okreni) koji joj se prenese kao parametar.
Obavezno je korišštenje funkcija iz prethodna dva zadatka. Testirati je u programu. Funkcija
treba da ima oblik:
void kel_okreni(char *okst);*/
#include <iostream>
using namespace std;
//funkcija za zamjenu koja prima pokazivace na unesene znakove
void kel_swap(char *a, char *b){
	char temp = *a; //pomocna varijabla u koju se smjesta pokazivac na prvi znak
	*a = *b; //u pokazivac na prvi znak se smjesta drugi znak
	*b = temp; //u pokazivac na drugi znak se smjesta vrijednost iz pomocne varijable
}
//funckija koja prima pokazivac na uneseni string
unsigned kel_strlen(char *str){
	int duzina = 0; //postavljanje duzine na 0 kako bi se za svaki znak mogla povecavati za 1
	while(*str != '\0'){ //petlja koja se ponavlja sve dok postoji jos unesenih znakova
		duzina++; //povecavanje broja duzine
		str++; //povecavanje pokazivaca na string
	}
	return duzina; //funkcija na kraju vraca ukupan broj znakova
}
//funkcija koja prima pokazivac na uneseni string
void kel_okreni(char *okst){
	int duzina = kel_strlen(okst); //varijabla duzina prima vrijednost koju dobije od funkcije kel_strlen
	char *pocetak, *kraj; //definisanje 2 nove varijable koje ce pokazivati na pocetak i kraj stringa
	pocetak = okst; //inicijalizacija varijable na pocetak stringa
	kraj = okst; //inicijalizacija varijable na pocetak stringa
	for(int i = 0; i < duzina - 1; i++){ //petlja koja sluzi da se pokazivac kraj pozicionira na zadnji znak u stringu
		kraj++; //povecanje pokazivaca
	}
	for(int j = 0; j < duzina / 2; j++){ //petlja koja provjerava se znakove manje od polovine duzine unesenog stringa
		kel_swap(pocetak,kraj); //poziv funkcije za zamjenu znakova
		pocetak++; //povecavanje pokazivaca za pocetak
		kraj--; //smanjivanje pokazivaca za kraj
	}	
}
int main()
{
	char str[100];
	cout<<"Unesite string: ";
	cin.getline(str, 100);
	kel_okreni(str); //omogucava se unos vise rijeci, odnosno racuna se i razmak izmedju rijeci
	cout<<"Uneseni string u obnutom redoslijedu: "<<str; //ispis unesenog stringa naopako
	return 0;
}
