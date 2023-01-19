#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <stdio.h>
#include <math.h>
using namespace std;
struct post{
	string codC;
	string NomC;
	string loc;
};
int main(int argc, char *argv[]) {
	
	int cont=0;
	int contt=0;
	
	
	
	post Club[1000][2];
	string part_L[1000][1];
	int part_E[1000][1];
	
	ifstream archivo;
	archivo.open("clubes.txt");
	if(archivo.fail()){
		cout<<"error";}
	else{	
		while ( !archivo.eof() ) {
			
			archivo>>Club[cont][0].codC;
			archivo>>Club[cont][1].NomC;
			archivo>>Club[cont][2].loc;
			cont++;
		}
		
	}
	archivo.close();
	
	ifstream archivo1;
	archivo1.open("patinadores.txt");
	if(archivo1.fail()){
		cout<<"error";}
	else{	
		while ( !archivo1.eof() ) {
			
			archivo1>>part_E[contt][0];
			archivo1.ignore();
			getline(archivo1,part_L[contt][0]);
			archivo1>>part_E[contt][1];
			archivo1.ignore();
			getline(archivo1,part_L[contt][1]);
			contt++;
		}
		archivo1.close();
	}
	
	cout<<"hola";
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}

