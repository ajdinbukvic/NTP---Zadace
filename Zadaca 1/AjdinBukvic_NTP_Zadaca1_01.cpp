/*Ispisati sve prirodne brojeve manje od N koji su jednaki 
sumi kvadrata dvostrukih faktorijela svojih cifara.*/
#include <iostream>
#include <vector>
using namespace std;
//globalne varijabla koja sluzi za smjestanje broja brojeva koji ispunjavaju uslov
int brojac = 0;
//globalna varijabla koja sluzi za smjestanje sume kvadrata
int s = 0;
//globalno definisan vektor koji sluzi za smjestanje pojedinacnih cifri broja
vector<int> cifre;
//rekurzivna funkcija koja prosljedjeni broj rastavlja na cifre i smjesta ih u vektor
int rastavi_cifre(int n){
	if(n==0) return 0;
	else {
		cifre.push_back(n%10); //izdvojena cifra smjesta se u vektor
		return rastavi_cifre(n/10);
	}
}
//rekurzivna funkcija koja racuna dvostruki faktorijel proslijedjenog broja
int dvostruki_faktorijel(int n){
	if(n==0) return 1;
	if(n%2==0){
		if(n==2) return 2;
		else return n*dvostruki_faktorijel(n-2); //slucaj kada je broj paran
	}
	else {
		if(n==1) return 1;
		else return n*dvostruki_faktorijel(n-2); //slucaj kada je broj neparan
	}
}
//funkcija koja racuna dvostruki faktorijel cifara te kvadrira svaku cifru
void kvadrat(int n){
	rastavi_cifre(n);
	for(int i=0; i<cifre.size(); i++){
		cifre[i] = dvostruki_faktorijel(cifre[i])*dvostruki_faktorijel(cifre[i]); //svaka cifra postaje kvadrat svog dvostrukog faktorijela
	}
}
//funkcija koja racuna sumu kvadrata dvostrukih faktorijela svih cifara
void suma_kvadrata(int n){
	kvadrat(n);
	for(int i=0; i<cifre.size(); i++){
		s += cifre[i]; //u globalnu varijablu se smjesta vrijednost svake izracunate cifre
	}
}
int main()
{
	/*NAPOMENA:
	najmanji broj koji zadovoljava uslov (osim 1) je 11037*/
	int n;
	cout<<"Unesi prirodan broj: ";
	cin>>n;
	cout<<"Prirodni brojevi manji od "<<n<<" jednaki sumi kvadrata dvostrukih faktorijela svojih cifara:"<<endl;
	//ispis svih brojeva koji zadovoljavaju uslov
	for(int i=1; i<n; i++){
		s = 0; //resetovanje vrijednosti varijable u svakoj iteraciji
		suma_kvadrata(i); //pozivanje funkcije za racunanje sume
		cifre.clear(); //ciscenje memorije zauzete u vektoru
		if(i==s){ 
			cout<<i<<endl; //ispis broja koji zadovoljava uslov
			brojac++; //za svaki broj povecavanje brojaca
		}
	}
	if(brojac==0) cout<<"Nema takvih brojeva u datom intervalu."<<endl; //ispis poruke ako nijedan broj ne zadovoljava uslov
	return 0;
}
