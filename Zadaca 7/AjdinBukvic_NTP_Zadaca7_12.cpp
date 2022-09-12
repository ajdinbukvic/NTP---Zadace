/*Data je tekstualna datoteka pismo.txt. Napisati funkcije za:
a) ispis datoteke na standardni izlaz zadržavajuci strukturu po redovima;
b) prepis datoteke u novu mijenjajuci mala i velika slova;
c) ispisati datoteku u obrnutom redosljedu na izlaz (prva postaje zadnja, druga postaje pretposljednja rijec...)
d) ispitati da li je neka rijeè palindrom (isto znaèenje kada se èita i u obrnutom smjeru)*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <algorithm>
#include <cctype>
using namespace std;
//--------------------FUNKCIJE-----------------------
int menu();
void ispis_na_ekran();
void prepis_datoteke();
void ispis_obrnuto();
void ispitati_palindrom();
//---------------------------------------------------
int main()
{
	int odabir; 
	while(odabir = menu()){ 
		switch(odabir){ 
			case 1:{
				system("cls");
				ispis_na_ekran();
				break;
			}
			case 2:{
				system("cls");
				prepis_datoteke();
				break;
			}
			case 3:{
				system("cls");
				ispis_obrnuto();
				break;
			}
			case 4:{
				system("cls");
				ispitati_palindrom();
				break;
			}
			case 5:{
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
	cout<<"-------------------MENU-------------------\n";
	cout<<"1. Ispis datoteke na ekran\n";
	cout<<"2. Prepis datoteke u novu\n";
	cout<<"3. Ispis datoteke u obrnutom redoslijedu\n";
	cout<<"4. Ispitati da li je neka rijec palindrom\n";
	cout<<"5. Izlaz\n";
	cout<<"------------------------------------------\n";
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
void ispis_na_ekran(){
	string linija;
	ifstream ulaz("pismo.txt");
	if(ulaz.is_open()){
		while(getline(ulaz, linija)){
			cout<<linija<<endl;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
}
void prepis_datoteke(){
	string linija;
	ifstream ulaz("pismo.txt");
	if(ulaz.is_open()){
		ofstream izlaz("pismonovo.txt");
		if(izlaz.is_open()){
			while(getline(ulaz, linija)){
				for(int i=0; i<linija.size(); i++){
					if(linija[i] >= 65 && linija[i] <= 90) linija[i] += 32;
					else if(linija[i] >= 97 && linija[i] <= 122) linija[i] -= 32;
				}
				izlaz << linija << endl;
			}
		}
		else{
			cout<<"Greska kod otvaranja datoteke!"<<endl;
			return;
		}
		izlaz.close();
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	cout<<"Sadrzaj datoteke pismo.txt je prepisan u datoteku pismonovo.txt !!!"<<endl;
	cout<<"Zamjena slova: mala u velika, a velika u mala !!!"<<endl;
}
void ispis_obrnuto(){
	string niz[10];
	string linija;
	int br = 0; 
	ifstream ulaz("pismo.txt");
	if(ulaz.is_open()){
		while(getline(ulaz, linija)){
			niz[br] = linija;
			br++;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	for(int i = br-1; i>=0; i--){
		cout<<niz[i]<<endl;
	}
}
void ispitati_palindrom(){
	string rijec;
	string linija;
	string temp;
	string niz[5];
	int br = 0;
	ifstream ulaz("pismo.txt");
	if(ulaz.is_open()){
		while(getline(ulaz, linija)){
			for(int i=0; i<linija.size(); i++){
				if(isspace(linija[i])){
					temp = rijec;
					reverse(rijec.begin(),rijec.end());
					if(rijec.compare(temp) == 0){
						niz[br] = temp;
						br++;
					}
					rijec.clear();
				} 
				else{
					rijec += linija[i];
				}
			}
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return;
	}
	ulaz.close();
	cout<<"Rijeci koje su palindromi iz datoteke:"<<endl;
	for(int i = 0; i<br; i++){
		cout<<niz[i]<<endl;
	}
}
