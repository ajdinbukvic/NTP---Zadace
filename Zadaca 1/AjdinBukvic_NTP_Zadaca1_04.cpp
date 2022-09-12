/*Za paran broj N proveriti hipotezu Goldbaha korišæenjem rekurzije. 
Prema toj hipotezi, svaki paran broj veæi od 2 može se predstaviti zbirom dva prosta broja. */
#include <iostream>
#include <cmath>
using namespace std;
//rekurzivna funkcija koja ispituje da li je broj prost
bool prost(int n, int m){
	if(m==1) return true; //ako je uslov ispunjen vraca true
	else if(n%m==0) return false; //ako uslov nije ispunjen vraca false
	else return prost(n, m-1); //novi poziv funkcije ako uslov nije ispunjen
}
//rekurzivna funkcija koja vraca prost broj
int hipoteza(int n){
	if(prost(n,sqrt(n))) return n;
	else return prost(hipoteza(n+1),sqrt(hipoteza(n+1))); //novi poziv funkcije sve dok za n+1 sve dok broj ne bude prost
}
int main()
{
	int n;
	//petlja koja osigurava da uneseni broj bude paran
	do{
		cout<<"Unesite paran broj veci od 2: ";
		cin>>n;
	}
	while(n%2!=0);
	cout<<"Paran broj "<<n<<" se moze napisati kao zbir prostih brojeva: "<<endl;
	//ispis svih zbirova prostih brojeva koji ispunjavaju uslov
	for(int i=2; i<=n/2; i++){
		if(prost(i,sqrt(i))){ //ako je proslijedjeni broj i prost i ako njegov n-i clan u zbiru daju uneseni broj
			if(hipoteza(i)+hipoteza(n-i)==n) cout<<hipoteza(i)<<" + "<<hipoteza(n-i)<<endl; //ispis prostih brojeva koji su sabirci parnog broja
		}
	}
	return 0;
}
