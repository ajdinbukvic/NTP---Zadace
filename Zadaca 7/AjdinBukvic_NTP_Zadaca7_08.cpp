/*U datoteci ulaz.txt nalazi se broj elemenata niza. Proèitati taj broj, alocirati niz te dužine i unjeti
vrijednosti elemenata tog niza. Izraèunati prosjeènu vrijednost, proširiti niz za jedno mjesto i ubaciti
prosjek u niz. U novu datoteku Izlaz.txt upisati sortiran dati niz.*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int broj;
	ifstream ulaz("ulaz.txt");
	if(ulaz.is_open()){
		int br;
		while(ulaz >> br){
			broj = br;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	ulaz.close();
	//---------------------------------------------------------------
	int br_elemenata = broj + 1;
	float *niz = new float[br_elemenata];
	float suma = 0;
	float prosjek;
	cout<<"Alociranje niza duzine od: "<<br_elemenata-1<<" elemenata..."<<endl;
	cout<<"Unesite elemente niza: "<<endl;
		for(int i = 0; i<br_elemenata-1; i++){
			cout<<i+1<<". clan: ";
			cin>>niz[i];
			suma += niz[i];
		}
		int temp;
		for(int j = 0; j<br_elemenata-2; j++){
			for(int k = 0; k<br_elemenata-2; k++){
				if(niz[k] > niz[k+1]){
					temp = niz[k];
					niz[k] = niz[k+1];
					niz[k+1] = temp;
				}
			}
		}
		prosjek = suma / (br_elemenata-1);
		niz[br_elemenata-1] = prosjek;
	//---------------------------------------------------------------
	ofstream izlaz("Izlaz.txt");
	if(izlaz.is_open()){
		for(int i = 0; i<br_elemenata; i++){
			izlaz << niz[i] << endl;
		}
	}
	else{
		cout<<"Greska kod otvaranja datoteke!"<<endl;
		return 0;
	}
	izlaz.close();
	//---------------------------------------------------------------
	cout<<"Informacije..."<<endl;
	cout<<"Sortirani niz je spremljen u datoteku Izlaz..."<<endl;
	cout<<"Zadnji red u datoteci predstavlja prosjecnu vrijednost niza..."<<endl;
	delete[] niz;
	return 0;
}
