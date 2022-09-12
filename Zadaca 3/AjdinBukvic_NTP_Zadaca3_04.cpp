/*Napisati funkciju koja kao argument uzima znakovno polje jmbg (jedinstveni maticni broj gradjanina) 
a kao izlaz vraca strukturnu varijablu koja predstavlja datum rodjenja doticne osobe. 
Nakon poziva funkcije fdatum() ispisuje datum rodjeja osobe sa doticnim jedinstvenim maticnim brojem.*/
#include <iostream>
using namespace std;
struct datum{
	int dan;
	int mjesec;
	int godina;
};
datum fdatum(char* jmbg){
	datum d;
	int i; 
	d.dan=0; d.mjesec=0; d.godina=1000;
	for(i=0;i<10;i++) if(*jmbg==49+i) d.dan=10*(1+i);
	for(i=0;i<10;i++) if(*(jmbg+1)==49+i) d.dan+=(1+i);
	for(i=0;i<10;i++) if(*(jmbg+2)==49+i) d.mjesec=10*(1+i);
	for(i=0;i<10;i++) if(*(jmbg+3)==49+i) d.mjesec+=(1+i);
	for(i=0;i<10;i++) if(*(jmbg+4)==49+i) d.godina+=100*(1+i);
	for(i=0;i<10;i++) if(*(jmbg+5)==49+i) d.godina+=10*(1+i);
	for(i=0;i<10;i++) if(*(jmbg+6)==49+i) d.godina+=(1+i);
	if(d.godina>=1000 && d.godina<=1100) d.godina+=1000;
	return d;
}
int main()
{
	char jmbg[13];
	cout<<"Unesite Vas JMBG: ";
	cin>>jmbg;
	datum d = fdatum(jmbg);
	cout<<"Datum rodjenja: "<<d.dan<<"."<<d.mjesec<<"."<<d.godina;
	return 0;
}
