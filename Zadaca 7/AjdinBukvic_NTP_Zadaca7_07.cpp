/*U datotekama grupa1.txt, grupa2.txt i grupa3.txt prati se rad uèenika na vježbama iz programiranja. U
svakom redu datoteka je ime uèenika, prosjeèna ocjena vježbi i broj vježbi koje je uèenik propustio.
Proèitati sve podatke i u datoteku izvjestaj.txt upisati sortirane uèenike, njihove zakljuène ocjene i
komentar da li je uèenik zadovoljio minimum rada na vježbama (manje od 5 propuštenih vježbi).*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;
struct ucenik{
	char ime[20];
	float prosjecna_ocjena;
	int br_propustenih;
	char komentar[20];
};
int main()
{
	int br_ucenika = 0;
	ucenik *ucenici = new ucenik[30];
	ifstream ulaz1("grupa1.txt");
	if(ulaz1.is_open()){
		char ime[20];
		float prosjecna_ocjena;
		int br_propustenih;
		while(ulaz1 >> ime >> prosjecna_ocjena >> br_propustenih){
			strcpy(ucenici[br_ucenika].ime,ime);
			ucenici[br_ucenika].prosjecna_ocjena = prosjecna_ocjena;
			ucenici[br_ucenika].br_propustenih = br_propustenih;
			br_ucenika++;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz1.close();
	//---------------------------------------------------------------
	ifstream ulaz2("grupa2.txt");
	if(ulaz2.is_open()){
		char ime[20];
		float prosjecna_ocjena;
		int br_propustenih;
		while(ulaz2 >> ime >> prosjecna_ocjena >> br_propustenih){
			strcpy(ucenici[br_ucenika].ime,ime);
			ucenici[br_ucenika].prosjecna_ocjena = prosjecna_ocjena;
			ucenici[br_ucenika].br_propustenih = br_propustenih;
			br_ucenika++;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz2.close();
	//---------------------------------------------------------------
	ifstream ulaz3("grupa3.txt");
	if(ulaz3.is_open()){
		char ime[20];
		float prosjecna_ocjena;
		int br_propustenih;
		while(ulaz3 >> ime >> prosjecna_ocjena >> br_propustenih){
			strcpy(ucenici[br_ucenika].ime,ime);
			ucenici[br_ucenika].prosjecna_ocjena = prosjecna_ocjena;
			ucenici[br_ucenika].br_propustenih = br_propustenih;
			br_ucenika++;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz3.close();
	//---------------------------------------------------------------
	ucenik *temp = new ucenik;
	for(int i = 0; i<br_ucenika-1; i++){
		for(int j = 0; j<br_ucenika-1; j++){
			if(ucenici[j].prosjecna_ocjena < ucenici[j+1].prosjecna_ocjena){
				*temp = ucenici[j];
				ucenici[j] = ucenici[j+1];
				ucenici[j+1] = *temp;
			}
		}
	}
	for(int k = 0; k<br_ucenika; k++){
		if(ucenici[k].br_propustenih < 5) strcpy(ucenici[k].komentar,"Zadovoljava");
		else strcpy(ucenici[k].komentar,"Ne zadovoljava");
	}
	//---------------------------------------------------------------	
	ofstream izlaz("izvjestaj.txt");
	if(izlaz.is_open()){
		for(int i = 0; i<br_ucenika; i++){
			izlaz << ucenici[i].ime << " " << ucenici[i].prosjecna_ocjena << " " << ucenici[i].br_propustenih << " " << ucenici[i].komentar << endl;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	izlaz.close();
	//---------------------------------------------------------------
	Sleep(1000);
	cout<<"Informacije..."<<endl;
	Sleep(1000);
	cout<<"Pribavljanje podataka iz datoteke Grupa 1..."<<endl;
	Sleep(1000);
	cout<<"Pribavljanje podataka iz datoteke Grupa 2..."<<endl;
	Sleep(1000);
	cout<<"Pribavljanje podataka iz datoteke Grupa 3..."<<endl;
	Sleep(1000);
	cout<<"Kreiranje izvjestaja o stanju ucenika..."<<endl;
	Sleep(1000);
	cout<<"Sortirani podaci o ucenicima spremljeni u datoteku Izvjestaj..."<<endl;
	Sleep(1000);
	delete temp;
	delete[] ucenici;
	return 0;
}
