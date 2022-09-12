/*Napišite generièku funkciju koja prima 4 parametra od kojih prva dva omeðuju jedan blok
podataka a druga dva drugi blok podataka. Ovi parametri mogu biti bilo pokazivaèi bilo iteratori,
pri èemu su prva dva istog tipa i druga dva takoðer istog tipa, ali tipovi prva dva parametra i
druga dva parametra ne moraju biti isti. Ova funkcija treba da pronaðe da li se drugi blok nalazi
kao podblok u prvom bloku (npr. blok {3, 5, 2} nalazi se kao podblok u bloku {1, 7, 3, 5, 2, 6}).
Ukoliko se nalazi, funkcija kao rezultat vraæa pokazivaè/iterator na mjesto u prvom bloku na
kojem se drugi blok nalazi kao podblok. Ukoliko se traženi blok nalazi na više mjesta kao
podblok u prvom bloku, treba vratiti mjesto njegovog prvog pronalaska. Konaèno, ukoliko
traženi blok nije naðen kao podblok u prvom bloku, treba vratiti pokazivaè/iterator koji pokazuje
taèno iza kraja prvog bloka. Napišite i kratki isjeèak programa u kojem æete demonstrirati kako
se koristi napisana funkcija na dva fiksna niza stringova*/
#include <iostream>
using namespace std;
template <typename T1, typename T2>
void provjera(T1 p1[], T1 v1, T2 p2[], T2 v2){
	int niz[100];
	int temp = 0;
	for(int i = 0; i<v1; i++){
		for(int j = 0; j<v2; j++){
			if(p1[i] == p2[j]){
				niz[temp] = p1[i];
				temp++;
			}
		}
	}
	cout<<"Elementi drugog bloka koji se nalaze u prvom bloku su:"<<endl;
	for(int i = 0; i<temp; i++){
		cout<<niz[i]<<" ";
	}
}
template <typename T>
void unos(T *N, int v){
	for(int i = 0; i<v; i++){
		cout<<"Unesite "<<i+1<<". clan niza: ";
		cin>>*(N+i);
	}
}
int main()
{
	int n,m;
	cout<<"Unesite velicinu prvog niza: ";
	cin>>n;
	int *niz1 = new int[n];
	unos(niz1,n);
	cout<<"Unesite velicinu drugog niza: ";
	cin>>m;
	int *niz2 = new int[m];
	unos(niz2,m);
	provjera(niz1,n,niz2,m);
	delete[] niz1;
	delete[] niz2;
	return 0;
}
