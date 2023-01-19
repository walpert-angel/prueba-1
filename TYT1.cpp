#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {

	char cod[15];
	char estado[10];
	char linea[100];
	char dia[2];
	char mes[2];
	char ano[4];	
	
	string dni[10355];
	
	
	
	int mayor=0,menor=0;
	int dia_mayor=0,dia_menor=0;
	int dato=9999;
	
	int q=0;
	int dia_X=0;
	int mes_Y=0;
	int fechaA[31][12];
	int fechaR[31][12];
	
	int inf;
	
	
	for (int J=0;J<31;J++){
		for (int U=0;U<13;U++){
			fechaA[J][U]=0;
			fechaR[J][U]=0;
		}
	}

	ifstream archivo;
	archivo.open("tramites.txt");
	if(archivo.fail()){
		cout<<"error";}	
	else{	
		while (q<10355){
			
			archivo.getline(linea,sizeof(linea));
            char* puntero;
				
			puntero = strtok(linea,"/");
			strcpy(dia,puntero);
			dia_X= stoi(dia);
			
			puntero = strtok(NULL,"/");
			strcpy(mes,puntero);
			mes_Y= stoi(mes);
			
			puntero = strtok(NULL," ");
			strcpy(ano,puntero);
			
			puntero = strtok(NULL," ");
			strcpy(cod,puntero);
			dni[q]= cod;
			
			
			
			puntero = strtok(NULL," ");
			strcpy(estado,puntero);
			if(strcmp(estado,"A")==0){
				fechaA[dia_X][mes_Y]++;
			}
			if(strcmp(estado,"R")==0){
				fechaR[dia_X][mes_Y]++;
			}
			q++;
			//cout<<dia_X<<endl;cout<<mes_Y<<endl;cout<<ano<<endl;cout<<cod<<endl;cout<<fechaA[dia_X][mes_Y]<<endl;cout<<fechaR[dia_X][mes_Y]<<endl;//prueba
		
		}//////while
		archivo.close();

		
	for(int Y=0;Y<=12;Y++){
	for(int X=0;X<=30;X++){
	
	if(fechaA[X][Y]>=mayor){
		mayor=fechaA[X][Y];
		dia_mayor=X;
				
		}
	
	
	
	
	menor=menor+fechaR[X][Y];
		

	
	
	
	}
	switch(Y){
	case 0: cout<<"ene dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 1: cout<<"feb dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 2: cout<<"mar dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 3: cout<<"abr dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 4: cout<<"may dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 5: cout<<"jun dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 6: cout<<"jul dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 7: cout<<"ago dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 8: cout<<"sep dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 9: cout<<"oct dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 10: cout<<"nov dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;
	case 11: cout<<"dic dia:"<<dia_mayor<<" con "<<mayor<<" Aprovados"<<endl;
	break;	
	}
	mayor=0;
	
	if(dato>menor){
		dato=menor;
		dia_menor=Y;
	}
	
	
	
	}
	cout<<"el mes:"<<dia_menor+1<<" se rechasaron "<<dato<<" y ese fue el mes en el que se rechasaron menos pasaportes"<<endl;


	
	
	
	cout<<"selecciones el dia:";
	cin>>inf;
	cout<<endl<<"el dia:"<<inf<<endl;
	for(int Y=0;Y<12;Y++){
		
		if(fechaA[inf][Y]<9999&&fechaA[inf][Y]>0  ){
		cout<<"en el mes:"<<Y+1<<" se aprovaron:"<<fechaA[inf][Y]<<endl;}
	}
	
	int contador=0,contador1=0,dataso=0;
	
	
	ofstream archivo1;
	archivo1.open("repetidos.txt");
	if(archivo1.fail()){
		cout<<"error";}	
	else{
	for(int h=0;h<10355;h++){
		for(int u=0;u<10355;u++){
			
			if(dni[h]==dni[u]){
				contador++;	
			}
		}		
		if(contador>1){archivo1<<dni[h]<<" se registro:"<<contador<<endl;}
		contador=0;
	}
	}
}
	return 0;	
}
