/*kreirajte dinamièki niz objekata tipa radnik od onoliko èlanova koliko želi korisnik;
struct radnik{
int ib;
char ime[10];
char prezime[10];
double dohodak[12];
int staz;
char spol[10];
};
• kreirati funkciju za unos obilježja za sve objekte: void unos(radnik *, int);
• kreirati funkciju za ispis obilježja jednog objekta: void ispis(radnik *);
• kreirati funkciju koja æe prebrojati koliko radnika su žene:
int prebroji_zene(radnik *, int);
• kreirati novi niz u dinamièkoj memoriji;
• kreirati funkciju u kojoj æete kopirati sve žene u novonapravljeni niz kopirati sve žene:
void kopiraj_zene(radnik *, radnik *, int);
• kreirati funkciju koja æe pronaæi i vratiti radnika s najdužim prezimenom:
radnik * najduze_ime(radnik *, int);
• kreirati funkciju koja æe vršiti pretragu radnika po imenu, te ispisati sva obilježja
radnika za koje je utvrðeno da imaju traženo ime:
void pretraga_po_imenu(radnik *, char *, int);
• kreirati funkciju koja æe izraèunati godišnje prihode za izabranog radnika:
double prihodi(radnik *, int, int); radnika se bira preko IB-a radnika, a prihodi se
raèunaju tako da sve zbroje dohoci za 12 mjeseci + 5% za svaku godinu staža;*/
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
//definicija strukture radnik s njenim elementima
struct radnik{
	int ib;
	char ime[10];
	char prezime[10];
	double dohodak[12];
	int staz;
	char spol[10];
};
//globalno definisana linija koja sluzi za odvajanje teksta prilikom ispisa
string linija = "==================================";
//funkcija koja predstavlja meni za odabir jedne od ponuðenih opcija(svaka opcija predstavlja zasebnu funkciju)
int menu(){
	system("cls");
	cout<<"----------------MENU----------------\n";
	cout<<"1. Unos radnika\n";
	cout<<"2. Ispis radnika\n";
	cout<<"3. Prebroji zene\n";
	cout<<"4. Kopiraj zene\n";
	cout<<"5. Radnik s najduzim prezimenom\n";
	cout<<"6. Pretraga radnika po imenu\n";
	cout<<"7. Prihodi za jednog radnika\n";
	cout<<"0. Izlaz\n";
	cout<<"------------------------------------\n";
	cout<<"ODABIR: ";
	int n;
	cin>>n; 
	if(cin) return n; //ako je uspjesan odabir u glavnom programu se poziva funckija
	else{
		cin.clear();
		cin.ignore(100, '\n'); //brisanje nepotrebnih znakova nakon svakog unosa
		return 0;
	}
}
//funkcija koja unosi podatke o svakom radniku pojedinacno
void unos(radnik *radnici, int n){
	cout<<"Unesite podatke o radnicima: "<<endl;
	for(int i=0;i<n;i++){ //petlja za unos n - broja radnika
		cout<<"IB: ";
		cin>>radnici[i].ib;
		cin.ignore();
		cout<<"Ime: ";
		cin.getline(radnici[i].ime, 10);
		cout<<"Prezime: ";
		cin.getline(radnici[i].prezime,10);
		for(int mjesec=0;mjesec<12;mjesec++){ //unos dohodka za svaki mjesec pojedinacno
			cout<<"Dohodak "<<mjesec+1<< ". mjesec: ";
			cin>>radnici[i].dohodak[mjesec];
		}
		cin.ignore();
		cout<<"Staz: ";
		cin>>radnici[i].staz;
		cin.ignore();
		do{ //petlja koja se ponavlja dok se ne unese spol u pravilnom obliku
			cout<<"Spol (musko / zensko): ";
			cin.getline(radnici[i].spol, 10);	
		}while(strcmp(radnici[i].spol,"zensko")!=0 && strcmp(radnici[i].spol,"musko")!=0); //provjera da li je uneseni spol "musko" ili "zensko"
		cout<<linija<<endl;
	}
}
//funkcija koja ispisuje sve podatke za jednog radnika
void ispis(radnik *r){
	cout<<"IB: "<< r->ib<<endl;
	cout<<"Ime: "<< r->ime<<endl;
	cout<<"Prezime: "<<r->prezime<<endl;
	cout<<"Staz: "<<r->staz<<endl; 
	cout<<"Spol: " <<r->spol<<endl;
	for(int i=0;i<12;i++){ //ispis dohodka za svaki mjesec pojedinacno
		cout<<"Dohodak "<<i+1<< ". mjesec: "<< r->dohodak[i]<<endl;
	}
	cout<<linija<<endl;
}
//funkcija koja broji koliko radnika su zene
int prebroji_zene(radnik *radnici,int n){
	int brojac = 0;
	for(int i=0;i<n;i++){ //petlja koja od svih radnika trazi one koji imaju spol "zensko"
		if(strcmp(radnici[i].spol,"zensko")==0){ //ako je pronadjen takav radnik na i - tom mjestu
			brojac++; //povecava se broj zenskih radnika
		}
	}
	return brojac; //vraca ukupan broj zenskih radnika
}
//funkcija koja pravi poseban niz radnika samo ako su zenskog spola
void kopiraj_zene(radnik *radnici,radnik *zene, int n){
	int brojac = 0;
	for(int i=0;i<n;i++){ //petlja koja od svih radnika trazi one koji imaju spol "zensko"
		if(strcmp(radnici[i].spol,"zensko")==0){ //ako je pronadjen takav radnik na i - tom mjestu
			zene[brojac] = radnici[i]; //podaci o radniku zenskog spola se smjestaju u novi niz
			brojac++; //povecava se indeks na koji se smjestaju radnici zenskog spola
		}
	}
}
//funckija koja trazi radnika sa najduzim prezimenom
radnik* najduze_prezime(radnik *radnici, int n){
	int prezime_duzina = 0;
	int temp = 0;
	radnik* r = NULL;
	for(int i=0;i<n;i++){ //petlja koja prolazi kroz sve radnika
		temp = strlen(radnici[i].prezime); //u privremenu varijablu se smjesta duzina prezimena radnika na i - tom mjestu 
		if(temp>prezime_duzina){ //ako je prezime vece od prethodnog
			prezime_duzina = temp; //duzina se postavlja na duzinu radnika na i - tom mjestu
			r = radnici+i; //prelazak na sljedeceg radnika 
		} 
	}
	return r; //vraca radnika koji ima najduze prezime
}
//funkcija koja sluzi za pretragu imena radnika
void pretraga_po_imenu(radnik *radnici, char* pretraga, int n){
	for(int i=0;i<n;i++){ //petlja koja prolazi kroz sve radnike
		if(strcmp(radnici[i].ime,pretraga)==0){ //ako prosljedjeno ime postoji kod nekog radnika
			ispis(radnici+i); //ispis svih podataka za radnika s trazenim imenom
		}
	}
}
//funkcija koja racuna godisnje prihode za jednog radnika
double prihodi(radnik *radnici, int n, int unos){
	double plata = 0;
	for(int i=0;i<n;i++){ //petlja koja prolazi kroz sve radnike
		if(radnici[i].ib == unos){ //provjerava da li neki radnik ima uneseni IB
			for(int j=0;j<12;j++){ //prolazi kroz svaki mjesec radnika koji ima uneseni IB
				plata += radnici[i].dohodak[j]; //smjesta mjesescni dohodak u pomocnu varijablu
			}
			plata *= (1+0.05*radnici[i].staz); //racuna godisnji dohodak na osnovu godina staza
		}
	}
	return plata; //vraca godisnji dohodak jednog radnika
}
int main(){
	int br_radnika;
	cout<<"Unesite broj radnika: ";
	cin>>br_radnika; //unos broja radnika
	radnik *radnici = new radnik[br_radnika]; //dinamicko alociranje niza tipa radnik
	int odabir; 
	while(odabir = menu()){ //prikazivanje menija nakon svakog unosa / ispisa
		switch(odabir){ //na osnovu rednog broja poziv odredjene funkcije
			case 1:{
				system("cls");
				unos(radnici,br_radnika);
				break;
			}
			case 2:{
				system("cls");
				for(int i=0;i<br_radnika;i++){
				ispis(radnici+i);
				}
				break;
			}
			case 3:{
				system("cls");
				int br_zena = prebroji_zene(radnici,br_radnika);
				cout<<"Broj zena je: "<<br_zena<<endl;
				break;
			}
			case 4:{
				system("cls");
				int br_zena = prebroji_zene(radnici,br_radnika);
				radnik *zene = new radnik[br_zena];
				kopiraj_zene(radnici,zene,br_radnika);
				cout<<"Zenski radnici kopirani u novi niz!"<<endl;
				cout<<linija<<endl;
				for(int i=0;i<br_zena;i++){
				ispis(zene+i);
				}
				delete[] zene;
				break;
			}
			case 5:{
				system("cls");
				ispis(najduze_prezime(radnici,br_radnika));
				break;
			}
			case 6:{
				system("cls");
				cin.ignore();
				char pretraga[10];
				cout<<"Unesite ime za pretragu: ";
				cin.getline(pretraga,10);
				pretraga_po_imenu(radnici,pretraga,br_radnika);
				break;
			}
			case 7:{
				system("cls");
				int pretraga;
				cout<<"Unesite IB radnika za obracun: ";
				cin>>pretraga;
				double obracun = prihodi(radnici,br_radnika,pretraga);
				cout<<"Godisnji prihod radnika iznosi: "<<obracun<<endl;
				break;
			}
		}
		cout<<"Pritisnite bilo koju tipku za nastavak..."; //ispis poruke na ekranu nakon svakog ispisa
		getch(); //alternativa za naredbu system("pause");
	}
	delete[] radnici; //brisanje dinamicki alocirane memorije na kraju programa
	return 0;
}
