/*Data je datoteka ispiti.txt èiji redovi imaju sljedeæu strukturu:
brindexa predmet ocjena
Kreirajte ovu datoteku koristeæi Notepad i napunite je nekim testnim podacima. predmeti su zadani
imenom predmeta.
Zatim napravite program koji na ulazu traži broj predmeta, te ispisuje prosjeènu ocjenu i prolaznost
(procenat studenata koji su položili tj. dobili ocjenu 6 ili više). Takoðer treba program ispisat ukupan broj
predmeta koje je student odslušao, broj položenih, te prosjeènu ocjenu.*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;
struct student{
	int index;
	char predmet[30];
	int ocjena;
};
//--------------------FUNKCIJE-----------------------
int menu();
void pretraga_predmet();
void pretraga_student();
//---------------------------------------------------
int main()
{
	int odabir; 
	while(odabir = menu()){ 
		switch(odabir){ 
			case 1:{
				system("cls");
				pretraga_predmet();
				break;
			}
			case 2:{
				system("cls");
				pretraga_student();
				break;
			}
			case 3:{
				return 0;
			}
		}
		cout<<"Pritisnite bilo koju tipku za nastavak...";
		getch(); 
	}
	return 0;
}
//---------------------------------------------------
int menu(){
	system("cls");
	cout<<"----------------MENU----------------\n";
	cout<<"1. Statistika za predmet\n";
	cout<<"2. Statistika za studenta\n";
	cout<<"3. Izlaz\n";
	cout<<"------------------------------------\n";
	cout<<"ODABIR: ";
	int n;
	cin>>n; 
	if(cin) return n; 
	else{
		cin.clear();
		cin.ignore(100, '\n');
		return 0;
	}
}
void pretraga_predmet(){
	cin.ignore();
	char naziv[30];
	int prolaznost = 0;
	int br_studenata = 0;
	int ocjene = 0;
	float prosjek;
	bool postoji = false;
	ifstream ulaz("ispiti.txt");
	if(ulaz.is_open()){
		student s;
		cout<<"Unesite naziv predmeta: ";
		cin.getline(naziv,30);
		while(ulaz >> s.index >> s.predmet >> s.ocjena){
			if(strcmp(s.predmet,naziv) == 0){
				if(s.ocjena > 5){
					prolaznost++;
				}
				ocjene += s.ocjena;
				br_studenata++;
				postoji = true;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	//---------------------------------------------------------------
	if(postoji){
		prosjek = float(ocjene) / br_studenata;
		cout<<"Broj studenata koji su izasli na ispit: "<<br_studenata<<endl;
		cout<<"Broj studenata koji su polozili predmet: "<<prolaznost<<endl;
		cout<<"Procenat studenata koji su polozili: "<<(prolaznost*100.)/br_studenata<<endl;
		cout<<"Prosjecna ocjena: "<<prosjek<<endl;
	}
	else cout<<"Ne postoji student sa tim indeksom!"<<endl;
}
void pretraga_student(){
	int br_indexa;
	int odslusao = 0;
	int polozio = 0;
	int ocjene = 0;
	float prosjek;
	bool postoji = false;
	ifstream ulaz("ispiti.txt");
	if(ulaz.is_open()){
		student s;
		cout<<"Unesite broj indeksa: ";
		cin>>br_indexa;
		while(ulaz >> s.index >> s.predmet >> s.ocjena){
			if(s.index == br_indexa){
				if(s.ocjena > 5){
					polozio++;
				}
				ocjene += s.ocjena;
				odslusao++;
				postoji = true;
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	//---------------------------------------------------------------
	if(postoji){
		prosjek = float(ocjene) / odslusao;
		cout<<"Broj predmeta koje je student odslusao: "<<odslusao<<endl;
		cout<<"Broj predmeta koje je student polozio: "<<polozio<<endl;
		cout<<"Prosjecna ocjena: "<<prosjek<<endl;
	}
	else cout<<"Ne postoji student sa tim indeksom!"<<endl;
}
