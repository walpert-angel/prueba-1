#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <stdio.h>
#include <math.h>
using namespace std;
struct post{
	
	string codigo;
	long tiempo_de_vida; //en meses
	long reparaciones_acumuladas;
	long antiguedad;	//en meses
};
int main(int argc, char *argv[]) {
	

	
	post maquinaria[100][3];
	int cont=0;
	
	char hola[4]={'h','o','l','a'};
	
	string dato;
	int num;
	
	
	
	ifstream archivo;
	archivo.open("maquinaria.txt");
	if(archivo.fail()){
		cout<<"error";}	
	else{	
		while ( !archivo.eof() ) {
			
			archivo>>maquinaria[cont][0].codigo;
			archivo>>maquinaria[cont][1].tiempo_de_vida;
			archivo>>maquinaria[cont][2].reparaciones_acumuladas;
			archivo>>maquinaria[cont][3].antiguedad;	
			
			cout<<maquinaria[cont][0].codigo<<endl;
			cont++;
		}
		archivo.close();
	}
	
	
	
	
	ofstream archivo1;
	archivo1.open("maquin_act.txt");
	if(archivo1.fail()){
		cout<<"error";}	
	else{
	while(dato!="Z9"){
		
		cout<<"introdusca el codigo:";
		getline(cin,dato);
		for(int e=0;e<cont;e++)
		if(maquinaria[e][0].codigo==dato){
			cout<<"ingrese movimiento:";
			cin>>num;
			switch(num){
			case 1: maquinaria[e][2].reparaciones_acumuladas++;
			if(maquinaria[e][2].reparaciones_acumuladas==maquinaria[e][1].tiempo_de_vida){
				archivo1<<"la maquina"<<maquinaria[e][0].codigo<<" dejo de tener vida util";
			}
			else{
			archivo1<<maquinaria[e][0].codigo<<endl;
			archivo1<<maquinaria[e][1].tiempo_de_vida<<endl;
			archivo1<<maquinaria[e][2].reparaciones_acumuladas<<endl;
			archivo1<<maquinaria[e][3].antiguedad<<endl;
			}
			break;
			case 2: maquinaria[e][2].reparaciones_acumuladas=maquinaria[e][2].reparaciones_acumuladas+999;
			break;	
			}
		}
	}
	int a=0,b=0;
	for(int o=0;o<cont;o++){
		for(int f=0;f<cont;f++){
			
			a = maquinaria[f][0].codigo[0];
			b = maquinaria[f+1][0].codigo[0];
			cout<<endl<<a<<" "<<b<<endl;
			
			
			if(maquinaria[f][0].codigo > maquinaria[f+1][0].codigo){
				string aux = maquinaria[f][0].codigo;
				maquinaria[f][0].codigo=maquinaria[f+1][0].codigo;
				maquinaria[f+1][0].codigo=aux;
				cout<<"X";
			}
			
		}	
		cout<<"Y";
		
	}
	

	cout<<" El orden quedo de la siguiente forma"<<endl;
	for (int y=0;y<cont+1;y++)
	{	
		cout<<maquinaria[y][0].codigo<<endl;
		
	}
	
	
	
	dato=hola;
	cout<<dato;
	
	
	
	}
	
	

	
	
	

	
	
	
	
	
	
	
	
	
	return 0;
	

}

