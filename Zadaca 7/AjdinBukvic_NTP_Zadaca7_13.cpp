/*Zadatak zahtijeva pisanje programa koji �e de�ifrovati poruke koje su �ifrirane kako je opisano u
narednom primjeru. Dat je �ifrirani tekst: saoreecessinntfi. Potrebno je primjetiti da se sastoji od �esnaest
slova. Tekst je mogu�e postaviti u matricu veli�ine 4�4 �ime se dobije:
s a o r
e e c e
s s i n
n t f i
Tekst �e se de�ifrovati ukoliko se znakovi poredaju na osnovu kolona odozgo prema dolje, tj. prvo znakovi iz
prve kolone, potom znakovi iz druge kolone itd. Na osnovu navedenog, tra�ena rije� u primjeru je:
sesnaestocifreni. Program otvara fajl pod nazivom �test.txt�. U fajlu se nalaze �ifrirani tekstovi jedan ispod
drugog. Program treba ispisati de�ifrovane tekstove svaki u zasebnoj liniji. Ukoliko broj znakova ulaznog teksta
nije kvadrat nekog broja program ispisuje rije� GRESKA.
1. saoreecessinntfi - sesnaestocifreni
2. pmrrj ie2 - primjer 2
3. dobar tekst - GRESKA
4. borj - broj
5. Bjsr aoOm - Broj Osam*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	string linija;
	string rijec;
	int k;
	cout<<"Desifrovane rijeci iz datoteke su:"<<endl;
	ifstream ulaz("test.txt");
	if(ulaz.is_open()){
		while(getline(ulaz, linija)){
			k = sqrt(linija.size());
			rijec.clear();
			if(linija.size() == k * k){
				for(int i = 0; i<k; i++){
					for(int j = 0; j<k; j++){
						rijec += linija[j*k+i];
					}
				}
				cout<<rijec<<endl;
			}
			else cout<<"GRESKA"<<endl;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	return 0;
}
