/*Napi�ite funkciju �IzdvojiRijec� sa dva parametra, od kojih je prvi tipa �string�, a drugi tipa
�int�. Prvi parametar predstavlja neku re�enicu, a drugi parametar redni broj rije�i unutar te
re�enice. Funkcija treba da izdvoji tu rije� iz re�enice i da vrati kao rezultat tako izdvojenu rije�.
Na primjer, ukoliko je kao prvi parametar zadan tekst � Riba ribi grize rep � a kao drugi
parametar broj 3, funkcija treba kao rezultat da vrati string �grize�. Ovdje pod pojmom rije�
podrazumijevamo bilo koji slijed uzastopnih znakova koji nisu razmaci, a ispred kojeg se
eventualno nalazi razmak (ili ni�ta), i iza kojeg eventualno slijedi razmak (ili ni�ta). Obratite
pa�nju da rije�i mogu biti razdvojene sa vi�e uzastopnih razmaka, kao i da na po�etku i kraju
teksta mo�e, ali i ne mora biti razmaka. Ukoliko je drugi parametar manji od 1 ili ve�i od broja
rije�i u re�enici, funkcija treba baciti izuzetak. Napisanu funkciju demonstrirajte u testnom
programu u kojem se za re�enicu unesenu sa tastature i prirodan broj n ispisuje n-ta rije� te
re�enice (pozivom napisane funkcije).*/
#include <iostream>
#include <cstring>
using namespace std;
int prebroj_rijeci(string recenica){
	int brojac = 0;
	bool razmak = false;
	for(int i=0; i<recenica.size(); i++){
		if(recenica[i]== ' ') razmak = false;
		else if(!razmak){
			razmak = true;
			brojac++;
		}
	}
 	return brojac;
}
string izdvoji_rijec(string recenica, int br_rijeci){
	string rijec;
	int brojac = 1;
	int tempA,tempB = 0;
	int pocetak = 0;
	while(recenica[pocetak] == ' '){
		pocetak++;
	}
    for(int i=pocetak; i<recenica.size(); i++) {
        if(recenica[i]== ' '){
        	brojac++;
			while(recenica[i]== ' ') i++;
			if(brojac==br_rijeci){
				tempA = i;
				while(recenica[i]!= ' '){
					tempB++;
					i++; 
				}
			}
		}
	}
	rijec = recenica.substr(tempA,tempB);
 	return rijec;
}
int main()
{
	string recenica;
	int br_rijeci;
	cout<<"Unesite recenicu: ";
	getline(cin, recenica);
	int br = prebroj_rijeci(recenica);
	cout<<"Unesena recenica ima ukupno: "<<br<<" rijeci"<<endl;
	do{
		cout<<"Unesite broj rijeci koju zelite izdvojiti: ";
		cin>>br_rijeci;
	}
	while(br_rijeci < 1 || br_rijeci > br);
	string rijec = izdvoji_rijec(recenica,br_rijeci);
	cout<<"Rijec koja se nalazi na "<<br_rijeci<<". poziciji je: "<<rijec;
	return 0;
}
