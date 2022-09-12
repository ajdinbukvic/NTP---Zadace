/*Potrebno je napraviti program koji æe ispisati sve moguæe naèine na koje se 
prirodan broj N (1 <= N <= 20) može rastaviti kao suma od K (1 <= K <= N) sabiraka 
koji su takoðer prirodni brojevi. Na primjer, moguæe rastave prirodnog broja 
N = 5 na K = 3 sabirka glase 3+1+1, 2+2+1, 2+1+2, 1+3+1, 1+2+2 i 1+1+3.*/
#include <iostream>
using namespace std;
int k; //globalo definisana varijabla u koju se smjesta uneseni broj sabiraka
int ukupno = 0; //globalno definisana varijabla koja racuna broj mogucih kombinacija ispisa
//funkcija koja ispisuje sve moguce kombinacije rastavljanja broja n na k sabiraka
void ispis(int *sabirci, int brojac){
	if(brojac==k){ //provjerava se da li je broj sabiraka jednak trazenom broju sabiraka
		for(int i=0; i<brojac-1; i++){
			cout<<sabirci[i]<<" + "; //ispis svakog pojedinacnog sabirka
		}
		cout<<sabirci[brojac-1]; //ispis zadnjeg sabirka bez znaka "+" na kraju radi ljepseg ispisa
		cout<<endl;
		ukupno++; //povecavanje brojaca koji racuna broj mogucih kombinacija
	}
} 
//rekurzivna funckija koja racuna da li su dobijeni sabirci jednaki unesenom broju
void rastavi(int n, int brojac, int *sabirci){
	for(int i=1; i<=n; i++){
		if(i==n){
			sabirci[brojac] = i;
			ispis(sabirci,brojac+1); //poziv funckije za ispis sabiraka
		}
		else{
			sabirci[brojac] = i;
			rastavi(n-i,brojac+1,sabirci); //poziv rekurzivne funkcije za naredni slucaj
		}	
	}
}
int main()
{
	int n;
	int sabirci[100];
	//petlja koja obezbjeduje da uneseni broj bude u intervalu [1,20]
	do {
		cout<<"Unesi sumu: ";
		cin>>n;
	}
	while(n<1 || n>20);
	//petlja koja obezbjeduje da uneseni broj bude u intervalu [1,20]
	do {
		cout<<"Unesi broj sabiraka: ";
		cin>>k;	
	}
	while(k<1 || k>n);
	//poziv rekurzivne funkcije koja rastavlja broj n na k sabiraka
	rastavi(n,0,sabirci);
	//ispis ukupnog broja mogucih kombinacija
	cout<<"Ukupno kombinacija: "<<ukupno<<endl;
	return 0;
}

