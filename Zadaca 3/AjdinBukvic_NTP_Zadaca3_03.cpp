/*Napišite program kojim se s tastature unose imena, sve dok se ne upiše "kraj“. 
Kada se završi unos treba izvršiti ispis imena obrnutim redoslijedom u odnosu na 
red unošenja s tastature, odnosno prvo treba ispisati ime koje je posljednje uneseno.*/
#include <iostream>
#include <string.h>
using namespace std;
struct imena{
	char ime[30];
};
int main()
{
	imena unos[100];
	int i = 0;
	cout<<"Unosite imena (kraj za prekid):"<<endl;
	do{
		cin>>unos[i].ime;
		i++;
	}
	while(strcmp(unos[i-1].ime, "kraj"));
	cout<<"Ispis imena obrnutim redoslijedom: "<<endl;
	for(int j=i-2; j>=0; j--){
		cout<<unos[j].ime<<endl;
	}
	return 0;
}

