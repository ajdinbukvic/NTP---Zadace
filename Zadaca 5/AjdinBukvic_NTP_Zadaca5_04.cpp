/*Definirajte strukturu �Cvor� koja sadr�i polje �ime_i_prezime� tipa �string�, zatim polje
�prosjek� tipa �double� i polje �veza� koje je tipa pokaziva� na �Cvor�. Iskoristite ovu strukturu
u programu koji �ita slijed podataka o studentima sa tastature, koji se sastoje od imena i
prezimena i prosjeka za svakog studenta, sve dok se kao podatak o imenu studenta ne unese
prazan string (tj. dok se ne pritisne samo ENTER bez ikakvog prethodnog unosa). Program treba
da uve�e te podatke u povezanu listu �vorova, ali koji nakon unosa svake od re�enica ume�e
�vor na takvo mjesto da lista u svakom trenutku bude sortirana po prosjeku u opadaju�em
redoslijedu kada se posmatra u redoslijedu kako idu veze izme�u �vorova (tj. student sa ve�im
prosjekom treba da do�e ispred studenta sa manjim prosjekom). U slu�aju da vi�e studenata ima
isti prosjek, njih treba me�usobno poredati po abecedi (preciznije, po poretku ASCII kodova).
Na kraju, program treba da ispi�e podatke o svim studentima u listi, da se uvjerimo da je lista
zaista sortirana u skladu sa tra�enim specifikacijama.*/
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct Cvor{
	string ime_prezime;
	double prosjek;
	Cvor *veza;
};
int main()
{
	Cvor *pocetak = NULL;
	while(true){
		Cvor *student = new Cvor;
		cout<<"Unesite ime i prezime studenta: ";
		getline(cin,student->ime_prezime);
		if(student->ime_prezime.empty()) break;
		cout<<"Unesite prosjek studenta: ";
		cin>>student->prosjek;
		cin.ignore();
		student->veza = 0;
		if(pocetak == 0) pocetak = student;
		else if(student->prosjek > pocetak->prosjek){
			student->veza = pocetak;
			pocetak = student;
		}
		else{
			Cvor *temp;
			for(temp = pocetak; temp->veza !=0 && temp->veza->prosjek > student->prosjek; temp = temp->veza) {}
			student->veza = temp->veza;
			temp->veza = student;
		}
	}
	cout<<"--------------Sortirani ispis-----------------"<<endl;
	cout<<setw(10)<<"Student"<<setw(10)<<"Prosjek"<<endl;
	cout<<"----------------------------------------------"<<endl;
	Cvor *temp;
	for(temp = pocetak; ; temp = temp->veza) {
		if(temp == 0) break;
		cout<<setw(10)<<temp->ime_prezime<<setw(10)<<temp->prosjek<<endl;
		delete temp;
	}
	temp = NULL;
	return 0;
}
