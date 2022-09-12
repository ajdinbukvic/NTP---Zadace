/*Napisati funkciju koja zamjenjuje vrijednosti dvije promjenljive tipa char. Ime funkcije treba
da bude kel_swap. Funkicja kao parametre prima pokazivaèe na promjenljive èije vrijednosti
zamjenjuje. Funkcija treba da ima oblik:
void kel_swap(char *a, char *b);*/
#include <iostream>
using namespace std;
//funkcija za zamjenu koja prima pokazivace na unesene znakove
void kel_swap(char *a, char *b){
	char temp = *a; //pomocna varijabla u koju se smjesta pokazivac na prvi znak
	*a = *b; //u pokazivac na prvi znak se smjesta drugi znak
	*b = temp; //u pokazivac na drugi znak se smjesta vrijednost iz pomocne varijable
}
int main()
{
	char prva;
	char druga;
	cout<<"Unesite prvi znak: "; //unos prvog i drugog znaka
	cin>>prva;
	cout<<"Unesite drugi znak: ";
	cin>>druga;
	cout<<"-----------------------------"<<endl; //ispis unesenih znakova prije izmjene
	cout<<"Prije izmjene:"<<endl;
	cout<<"Prvi znak: "<<prva<<endl;
	cout<<"Drugi znak: "<<druga<<endl;
	kel_swap(&prva,&druga); //poziv funkcije koja prima reference od prvog i drugog znaka
	cout<<"-----------------------------"<<endl; //ispis unesenih znakova nakon pozivanja funckije kel_swap
	cout<<"Poslije izmjene:"<<endl;
	cout<<"Prvi znak: "<<prva<<endl;
	cout<<"Drugi znak: "<<druga<<endl;
	return 0;
}

