/*Napišite program koji traži od korisnika da unese niz reèenica, pri èemu se broj
reèenica prethodno unosi sa tastature. Za svaku unesenu reèenicu dinamièki
alocirajte prostor, uz voðenje evidencije o adresi svake alocirane reèenice u
dinamièkom nizu pokazivaèa na poèetke svake od reèenica. Nakon toga, treba ispisati
unesene reèenice sortirane u abecedni poredak (odnosno u poredak po ASCII
kodovima). Sortiranje obavite ruèno, bilo kojim postupkom koji Vam je poznat
(nemojte koristiti gotove funkcije za sortiranje)*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int br;
	cout<<"Unesite broj recenica: ";
	cin>>br; //unos broja recenica
	cin.ignore(); //ignorisanje preostalih karaktera
	string *recenica = new string[br]; //dinamicki alociran niz recenica tipa string
	for(int i = 0; i<br; i++){ //petlja za unos svih recenica
		cout<<"Unesite "<<i+1<<". recenicu: ";
		getline(cin,recenica[i]); //uzima svaku rijec recenice ukljucujuci i razmake
	}
	string temp; //pomocna varijabla za sortiranje recenica
	for(int i = 0; i<br; i++){ //petlja koja prolazi kroz sve recenice
		for(int j = i+1; j<br; j++){ //petlja koja prolazi kroz sve recenice s uvecanim indeksom za 1
			if(recenica[i]>recenica[j]){ //ako je recenica veca po ASCII vrijednosti od naredne
				temp = recenica[i]; //smjestanje recenice u privremenu varijablu
				recenica[i] = recenica[j]; //recenica postaje sljedeca recenica
				recenica[j] = temp; //naredna recenica postaje prvobitna recenica
			}
		}
	}
	cout<<"=================================="<<endl;
	cout<<"Sortirani ispis recenica:"<<endl;
	cout<<"=================================="<<endl;
	for(int i = 0; i<br; i++){ //petlja koja ispisuje recenice u sortiranom redoslijedu
		cout<<"Recenica "<<i+1<<". : "<<recenica[i]<<endl;
	}
	delete[] recenica; //brisanje dinamicki alocirane memorije
	return 0;
}
