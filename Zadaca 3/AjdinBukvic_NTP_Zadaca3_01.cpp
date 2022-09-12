/*Unijeti broj studenata, te podatke o studentima: ime, prezime, godina, prosjek. 
Ispisati studenta sa najveæim prosjekom.*/
#include <iostream>
using namespace std;
struct student{
	char ime[30];
	char prezime[30];
	int godina;
	float prosjek;
};
int main()
{
	int n;
	cout<<"Unesi broj studenata: ";
	cin>>n;
	student studenti[n];
	cout<<"Unesite podatke o studentima: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"Ime: ";
		cin>>studenti[i].ime;
		cout<<"Prezime: ";
		cin>>studenti[i].prezime;
		cout<<"Godina: ";
		cin>>studenti[i].godina;
		cout<<"Prosjek: ";
		cin>>studenti[i].prosjek;
	}
	int max = 0;
	float max_prosjek = 0;
	for (int i=0; i<n; i++){
		if (studenti[i].prosjek > max_prosjek) {
			max_prosjek = studenti[i].prosjek;
			max = i;
		}
	}
	cout<<"Ispis studenta sa najvecim prosjekom: "<<endl;
	cout<<"Ime: "<<studenti[max].ime<<endl;
	cout<<"Prezime: "<<studenti[max].prezime<<endl;
	cout<<"Godina: "<<studenti[max].godina<<endl;
	cout<<"Prosjek: "<<studenti[max].prosjek<<endl;
	return 0;
}
