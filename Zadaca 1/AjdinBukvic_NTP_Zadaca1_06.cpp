/*Napisati rekurzivnu funkciju koja od broja N odredjuje broj ispisan u obrnutnom poretku.
Ispitati da li je uneti broj N palindrom (pise se isto i s leva i s desna). Npr. 12321, 3456543.*/
#include <iostream>
using namespace std;
//globalno definisana varijabla koja sluzi za smjestanje ostatka broja
int m = 0;
//rekurzivna funkcija koja uneseni broj ispisuje broj napisan u obrnutom redoslijedu
int obrnuti_broj(int n, int m){
	int cifra;
	if(n==0) return m; //zavrsetak funkcije kada se broj ne moze vise dijeliti sa 10
	else {
		cifra = n%10; //u varijablu se smjesta ostatak pri djeljenju broja sa 10
		m = m*10 + cifra; //u varijablu se smjesta nova vrijednost broja
		return obrnuti_broj(n/10,m); //poziv funkcije sve dok se sve cifre broja ne okrenu
	}
}
//rekurzivna funkcija koja ispituje da li je uneseni broj palindrom
int palindrom(int n, int m){
	if(n==0) return m; //zavrsetak funkcije kada se broj ne moze vise dijeliti sa 10
	else {
		m = m*10 + (n % 10); //u varijablu se smjesta nova vrijednost broja
		return palindrom(n/10,m); //poziv funkcije sve dok je broj razlicit od 0						
	}
}
int main()
{
	int n;
	cout<<"Unesite broj: ";
	cin>>n;
	//ispis unesenog broja u obrnutom redoslijedu
	cout<<"Broj ispisan obrnutim redoslijedom: "<<obrnuti_broj(n,m)<<endl;
	//smjestanje palindroma unesenog broja u varijablu
	int provjera = palindrom(n,m);
	//ako su cifre jednake ispisuje poruku
	if(provjera==n) cout<<"Uneseni broj je palindrom.";
	//ako su cifre razlicite ispisuje poruku
	else cout<<"Uneseni broj nije palindrom.";
	return 0;
}
