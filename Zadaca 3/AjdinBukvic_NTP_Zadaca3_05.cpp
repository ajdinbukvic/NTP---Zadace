/*Napisati funkcije:
- brojpoz(), koja raèuna broj pozitivnih èlanova niza,
- proizvod(), koja raèuna proizvod svih èlanova niza,
- zbirparnih(), koja raèuna zbir svih parnih èlanova,
- brojnula(), koja raèuna broj èlanova jednakih nuli,
- brojneg(), koja raèuna broj negativnih èlanova,
- prosek(), koja raèuna srednju vrijednost niza.
U glavnoj funkciji se unosi prirodan broj n<100, zatim niz od n cijelih brojeva i štampaju
rezultati funkcije.*/
#include <iostream>
using namespace std;
int brojpoz(int *niz, int n){
	int brojac = 0;
	for(int i=0; i<n; i++){
		if(niz[i]>0) brojac++;
	}
	return brojac;
}
int proizvod(int *niz, int n){
	int pr = 1;
	for(int i=0; i<n; i++){
		pr *= niz[i];
	}
	return pr;
}
int zbirparnih(int *niz, int n){
	int zbir = 0;
	for(int i=0; i<n; i++){
		if(niz[i]%2==0) zbir += niz[i];
	}
	return zbir;
}
int brojnula(int *niz, int n){
	int brojac = 0;
	for(int i=0; i<n; i++){
		if(niz[i]==0) brojac++;
	}
	return brojac;
}
int brojneg(int *niz, int n){
	int brojac = 0;
	for(int i=0; i<n; i++){
		if(niz[i]<0) brojac++;
	}
	return brojac;
}
float prosjek(int *niz, int n){
	float suma = 0;
	for(int i=0; i<n; i++){
		suma += niz[i];
	}
	return suma/n;
}
int main()
{
	int n;
	do{
		cout<<"Unesite prirodan broj manji od 100: ";
		cin>>n;
	}
	while(n<1 || n>99);
	int niz[n];
	cout<<"Unesite "<<n<<" clanova niza:"<<endl;
	for(int i=0; i<n; i++){
		cin>>niz[i];
	}
	int br_poz = brojpoz(niz,n);
	cout<<"Broj pozitivnih brojeva: "<<br_poz<<endl;
	int pr = proizvod(niz,n);
	cout<<"Proizvod brojeva: "<<pr<<endl;
	int zbir_p = zbirparnih(niz,n);
	cout<<"Zbir parnih brojeva: "<<zbir_p<<endl;
	int br_nula = brojnula(niz,n);
	cout<<"Broj nula: "<<br_nula<<endl;
	int br_neg = brojneg(niz,n);
	cout<<"Broj negativnih brojeva: "<<br_neg<<endl;
	float sredina = prosjek(niz,n);
	cout<<"Prosjek: "<<sredina<<endl;
	return 0;
}
