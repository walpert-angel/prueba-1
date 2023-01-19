#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <stdio.h>
#include <math.h>
using namespace std;
void funcion2(string cate,string cate2){	
	string K= cate.substr(3,1);
	string S= cate.substr(6,1);
	if(S=="S"){
		cout<<"nombre de catedra: "<<cate2<<"      año cursada: "<<K<<endl;	
	}	
}
void funcion1(string dato1,int dato2,int dato3){
	ofstream arch;
    arch.open("fin_cursada.txt");	
	arch<<"nombre de materia: "<<dato1<<" alumnos libres: "<<dato2<<" alumnos no libres: "<<dato3<<endl;
}	
int main(int argc, char *argv[]) {
	
	int cont=0;
	int contt=0;

	string Cate[1000][3];
	string docen[1000][6];
	
	string dni;
	string codigo;
	int alumnos[4];
	
	ifstream archivo;
	archivo.open("catedras.txt");
	if(archivo.fail()){
		cout<<"error";}
	else{	
		while ( !archivo.eof() ) {
						
			getline(archivo,Cate[cont][0]);//cod
			getline(archivo,Cate[cont][1]);//cantidad
			getline(archivo,Cate[cont][2]);//nom_cate
				
			//cout<<Cate[cont][0]<<endl;
			//cout<<Cate[cont][1]<<endl;
			//cout<<Cate[cont][2]<<endl;
			
			cont++;	
		}
	}
	archivo.close();
		
	ifstream archivo1;
	archivo1.open("docentes.txt");
	if(archivo1.fail()){
		cout<<"error";}
	else{	
		while ( !archivo1.eof() ) {
						
			getline(archivo1,docen[contt][0]);//codigo de catedra
			//cout<<docen[contt][0]<<endl;
			getline(archivo1,docen[contt][1]);
			//cout<<docen[contt][1]<<endl;
			getline(archivo1,docen[contt][2]);//dni
			//cout<<docen[contt][2]<<endl;
			getline(archivo1,docen[contt][3]);
			//cout<<docen[contt][3]<<endl;
			getline(archivo1,docen[contt][4]);
			//cout<<docen[contt][4]<<endl;
			getline(archivo1,docen[contt][5]);//cargo
			//cout<<docen[contt][5]<<endl;
						
			contt++;	
		}		
	}
	archivo1.close();
	
	int y=0;
	
	while(dni!="0"){		
		cout<<"ingrese dni docente:";
		getline(cin,dni);
		cout<<"ingrese codigo de catedra:";
		getline(cin,codigo);
		for(int e=0;e<contt;e++)
			if(dni==docen[e][2] && codigo==docen[e][0]){
			for(int h=0;h<cont;h++){
				if(codigo==Cate[h][0]){y=h;				
				}
			}
			cout<<"nombre de catedra: "<<Cate[y][2]<<endl;

			if(docen[e][5]=="JTP" || docen[e][5]=="AUXILIAR"){
				cout<<"NO AUTORIZA PARA CARGA"<<endl;
			}
			if(docen[e][5]=="TITULAR" || docen[e][5]=="ADJUNTO"){
				cout<<"CANTIDAD DE ALUMNOS LIBRES: ";
				cin>>alumnos[1];
				cin.ignore();
				cout<<"CANTIDAD DE ALUMNOS REGULARES: ";
				cin>>alumnos[2];
				cin.ignore();
				cout<<"CANTIDAD DE ALUMNOS PROMOCIONADOS: ";
				cin>>alumnos[3];
				cin.ignore();	
			funcion1(Cate[y][2],alumnos[1],alumnos[2]+alumnos[3]);
			
			}
		}	
	}
	
	for(int U=0;U<cont;U++){
	funcion2(Cate[U][0],Cate[U][2]);
	}
	
	return 0;
}
