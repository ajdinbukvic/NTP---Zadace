/*Laa-Laa i Po igraju igru. Laa-Laa zamisli broj X, a Po mora naæi najveæi neparni broj Y koji dijeli X. 
Kako je Laa-Laa ipak nešto starija, ona malo bolje poznaje svijet brojki pa zamišlja prevelike brojeve, 
ali zato Po ima dobre starije prijatelje koji æe mu pomoæi!!!
Ulazni podaci
Putem tastature unosi se jedan prirodan broj X s maksimalno 9 cifara.
Izlazni podaci
Na zaslon je potrebno ispisati broj Y, odnosno najveæi neparni djelitelj broja X.*/
#include <iostream>
using namespace std;
//rekurzivna funkcija koja trazi najveci neparni djeljitelj unesenog broja
int najveci_neparni_djeljitelj(int x, int max){
	if(max%2!=0 && x%max==0) return max; //ako je proslijedjeni broj neparan i djeljiv s brojem onda vraca trazeni broj
	else {
		max--; //smanjuje se broj koji se biti ispitan u narednom slucaju
		return najveci_neparni_djeljitelj(x,max); //poziv rekurzivne funkcije za naredni slucaj
	}
}
int main()
{
	int x;
	//petlja koja obezbjeduje da uneseni broj bude u intervalu [1,999999999]
	do {
		cout<<"Unesite prirodan broj: ";
		cin>>x;
	}
	while(x<1 || x>999999999);
	//varijabla u koju se smjesta polovina unesenog broja x
	int max = x/2;
	//ispis najveceg neparnog djeljitelja za uneseni broj x
	cout<<"Najveci neparni djeljitelj broja "<<x<<" je: "<<najveci_neparni_djeljitelj(x,max);
	return 0;
}
