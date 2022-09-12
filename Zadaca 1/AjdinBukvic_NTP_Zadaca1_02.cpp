/*Ispitati da li je uneti broj N prost koristeæi rekurzivnu funkciju prost. 
Odrediti najbliži prost broj datom prirodnom broju koristeæi rekurziju.*/
#include <iostream>
#include <cmath>
using namespace std;
//rekurzivna funkcija koja ispituje da li je broj prost
bool prost(int n, int m){
	if(m==1) return true; //ako je uslov ispunjen vraca true
	else if(n%m==0) return false; //ako uslov nije ispunjen vraca false
	else return prost(n, m-1); //novi poziv funkcije ako uslov nije ispunjen
}
//rekurzivna funkcija koja za proslijedjeni broj vraca njemu najblizi manji prost broj
int najblizi_manji(int n){
	if(prost(n,sqrt(n))) return n;
	else return najblizi_manji(n-1); 
}
//rekurzivna funkcija koja za proslijedjeni broj vraca njemu najblizi veci prost broj
int najblizi_veci(int n){
	if(prost(n,sqrt(n))) return n;
	else return najblizi_veci(n+1); 
}
//funkcija koja ispituje da li je manji ili veci broj blizi proslijedjenom broju
int najblizi(int n){
	if(najblizi_veci(n)-n < n-najblizi_manji(n)) return najblizi_veci(n);
	else if(najblizi_veci(n) > n-najblizi_manji(n)) return najblizi_manji(n);
}
int main()
{
	int n;
	cout<<"Unesite prirodan broj: ";
	cin>>n;
	//ako je uneseni broj prost ispisuje poruku
	if(prost(n,sqrt(n))) cout<<"Broj je prost."<<endl;
	//ako broj nije prost ispisuje poruku i ispisuje njemu najblizi prost broj
	else {
		cout<<"Broj nije prost."<<endl;
		cout<<"Najblizi prost broj unesenom broju "<<n<<" je: "<<najblizi(n);
	}
	return 0;
}
