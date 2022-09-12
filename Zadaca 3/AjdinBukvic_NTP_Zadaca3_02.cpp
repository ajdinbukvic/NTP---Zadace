/*Upisati ime i prezime uèenika te broj opravdanih i neopravdanih sati. 
Ispisati ime, prezime, broj opravdanih i neopravdanih sati te ukupan broj izostanaka!*/
#include <iostream>
using namespace std;
struct ucenik{
	char ime[30];
	char prezime[30];
	int br_opravdanih;
	int br_neopravdanih;
	int ukupno_izostanaka;
};
int main()
{
	int n;
	cout<<"Unesite broj ucenika: ";
	cin>>n;
	ucenik ucenici[n];
	int ukupno_opravdanih = 0;
	int ukupno_neopravdanih = 0;
	int ukupno_svih_izostanaka = 0;
	cout<<"---------------------------------------"<<endl;
	cout<<"Unesite podatke o ucenicima: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"Ime: ";
		cin>>ucenici[i].ime;
		cout<<"Prezime: ";
		cin>>ucenici[i].prezime;
		cout<<"Broj opravdanih: ";
		cin>>ucenici[i].br_opravdanih;
		cout<<"Broj neopravdanih: ";
		cin>>ucenici[i].br_neopravdanih;
		ucenici[i].ukupno_izostanaka = ucenici[i].br_opravdanih + ucenici[i].br_neopravdanih;
		ukupno_opravdanih += ucenici[i].br_opravdanih;
		ukupno_neopravdanih += ucenici[i].br_neopravdanih;
		ukupno_svih_izostanaka += ucenici[i].ukupno_izostanaka;
	}
	cout<<"---------------------------------------"<<endl;
	cout<<"Ispis ucenika: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"Ime: "<<ucenici[i].ime<<endl;
		cout<<"Prezime: "<<ucenici[i].prezime<<endl;
		cout<<"Broj opravdanih: "<<ucenici[i].br_opravdanih<<endl;
		cout<<"Broj neopravdanih: "<<ucenici[i].br_neopravdanih<<endl;
		cout<<"Ukupno izostanaka: "<<ucenici[i].ukupno_izostanaka<<endl;
	}
	cout<<"---------------------------------------"<<endl;
	cout<<"Ispis ukupnog broja izostanaka: "<<endl;
	cout<<"Ukupno opravdanih: "<<ukupno_opravdanih<<endl;
	cout<<"Ukupno neopravdanih: "<<ukupno_neopravdanih<<endl;
	cout<<"Ukupno svih izostanaka: "<<ukupno_svih_izostanaka<<endl;
	return 0;
}

