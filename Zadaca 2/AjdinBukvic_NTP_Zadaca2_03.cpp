/*Postoji šest permutacija bez ponavljanja brojeva 1, 2 i 3. To su 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2 i 3,2,1. 
Napisat program koji ispisuje sve permutacije bez ponavljanja brojeva 1,2,3,4 i 5 (ima ih 120).*/
#include <iostream>
#include <vector>
using namespace std;
int brojac = 0; //globalno definisana varijabla koja racuna broj svih mogucih permutacija
//funckija koja ispisuje sve permutacije od 1,2,3,4,5
void ispis(const vector<int> &permutacija) {
	for(int i=0; i<permutacija.size(); i++){
		cout << permutacija[i] << " ";
	}
	cout << endl;
	brojac++; //povecavanje brojaca koji racuna broj svih mogucih permutacija
}
//rekurzivna funkcija koja trazi sve permutacije od brojeva 1,2,3,4,5
void zamjena(vector<int> &permutacija, int n) {
	if(n == 1) ispis(permutacija); //kada se uslov ispuni ispisuje sve permutacije
 	else {
 		for(int i = 1; i <= n; i++) {
 			swap(permutacija[n-i], permutacija[n-1]); //zamjena mjesta za n-i slucaj
 			zamjena(permutacija, n-1); //poziv rekurzivne funkcije za n-i slucaj
 			swap(permutacija[n-i], permutacija[n-1]); //zamjena mjesta za n-i slucaj
 		}
 	}
}
//funckija koja smjesta permutacije u vektor
void permutacije(int n) {
	vector<int> permutacija(n); //smjesta broj permutacija u vektor
 	for(int i = 1; i <= n; i++){
 		permutacija[i-1] = i;
 	}
 	zamjena(permutacija, n); //poziv rekurzivne funkcije za n permutacija
}
int main()
{
	cout<<"Sve permutacije brojeva 1,2,3,4,5 bez ponavljanja: "<<endl;
	//poziv funckije za permutacije 1,2,3,4,5
	permutacije(5);
	//ispis ukupnog broja permutacija od 1,2,3,4,5
	cout<<"Ukupno ima: "<<brojac<<" permutacija."<<endl;
	return 0;
}
