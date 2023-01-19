#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h> 
#include <stdio.h>
#include <math.h>
using namespace std;
double calculo_cP(double M[][4],int i,int j){/////////////CP
	static double resultado;
    if(j%2==0){resultado=(433/2)*(((M[i][3]+M[i][4])-(M[i][1]+M[i][2]))/(M[i][3]+M[i][4]+M[i][2]+M[i][4]));}
	else{	   resultado=(238/2)*(((M[i][1]+M[i][3])-(M[i][2]+M[i][4]))/(M[i][3]+M[i][4]+M[i][2]+M[i][4]));}
	return(resultado);
}
double mayor_e(double CP[][2],int i,int j){/////////////mayor
	static double resultado;
	if(resultado<CP[i][j]){
		resultado=CP[i][j];}
	return(resultado);
}
double menor_e(double CP[][2],int i,int j){/////////////menor
	static double resultado=9999;
	if(resultado>CP[i][j]){
		resultado=CP[i][j];}
	return(resultado);
}	
double calculando_la_media(double CP[][2],int todo,int j){/////////////media
	double columna[2];
	static double resultado;
	for(int i=0;i<todo;i++){			
		columna[j]=columna[j]+CP[i][j];}
	resultado= columna[j]/todo;
	return(resultado);
}
double calculando_el_estandar(double CP[][2],double Media[],int todo,int j){/////////////estandar
	float columna_estandar[2];
	static double resultado;
	for(int i=0;i<todo;i++){
		columna_estandar[j]=columna_estandar[j]+pow(CP[i][j]-Media[j],2);}
	resultado= sqrt(columna_estandar[j]/(todo-1));
	return(resultado);
}
double calculo_TCP(double CP[][2],int i){
	static double resultado;
	resultado = sqrt(pow(CP[i][1]-CP[i-1][1],2)+pow(CP[i][2]-CP[i-1][2],2));
	return(resultado);
}
double velocidad_de_Balanceo(double TCP[],int todo,int i){
	static double resultado;
	resultado = TCP[i]/(todo/64);
	return(resultado);
}	
double calculo_absoluto1(double CP[][2],int todo){
	double CPP[5000][2];
	static double resultado;	
	for(int i=0;i<todo;i++){
	if(CP[i][1]<0){(CPP[i][1])=-(CP[i][1]);}
	else{(CPP[i][1])=(CP[i][1]);}
	resultado=resultado+(CPP[i][1]);}
	return(resultado);
}
double calculo_absoluto2(double CP[][2],int todo){
	double CPP[5000][2];
	static double resultado;
	
	for(int i=0;i<todo;i++){
		if(CP[i][2]<0){(CPP[i][2])=-(CP[i][2]);}
		else{(CPP[i][2])=(CP[i][2]);}
		resultado=resultado+(CPP[i][2]);}
	return(resultado);
}		
int main() {
	int columnas=4;
	double m[5000][4];
	double CP[5000][2];
	double mayor[2];
	double menor[2]={9999,9999};
	double Media[2];
	double estandar[2];
	double TCP[5000];
	double velocidad[5000];
	double Valor_absoluto[2];
	int todo=0;	
	
	fstream arch; /////no lo hice resumido porque me causaba probleamsa a la hora de leerlo, escribirlo y volver a leerlo
	arch.open("CP.hea.txt");  ///////lectura
	if (!arch.is_open()){cout<<"El archivo no se pudo abrir";return 1;}	
	char nombres1[80];
	char nombres2[80];
	char nombres3[80];
	char nombres4[80];
	char nombres5[80];
	char nombres6[80];
	char nombres7[80];
	char nombres8[80];
	char nombres9[80];
	char nombres10[80];
	char nombres11[80];
	char nombres12[80];
	float n1,n2,n3,n4;
		
	arch.getline(nombres1,30,58);
	arch.getline(nombres2,30);
	arch.getline(nombres3,30,58);
	arch.getline(nombres4,30);
	arch.getline(nombres5,30,58);
	arch.getline(nombres6,30);
	arch.getline(nombres7,30,58);
	arch.getline(nombres8,30);
	arch.getline(nombres9,30,58);
	arch.getline(nombres10,30);
	arch.getline(nombres11,30,58);
	arch.getline(nombres12,30);
	arch.ignore();
	cout<<nombres1<<":";
	cout<<nombres2<<"\n";
	cout<<nombres3<<":";
	cout<<nombres4<<"\n";
	cout<<nombres5<<":";
	cout<<nombres6<<"\n";
	cout<<nombres7<<":";
	cout<<nombres8<<"\n";
	cout<<nombres9<<":";
	cout<<nombres10<<"\n";
	cout<<nombres11<<":";
	cout<<nombres12<<"\n";
		
		n1 = atof(nombres4);
		n2 = atof(nombres6);	
		n3 = atof(nombres8);	
		n4 = atof(nombres10);
		
		arch.close();	
		todo=n3;   //comprobar dato, a una variable cuando la usas muchas veces llega una momento que tira error
		cout<<"\n\n"<<todo<<"  //comprobacion//\n"; /////// comprobar numero de filas
		
		fstream arch_entrada; /////////// lectura de CP.prn
		arch_entrada.open("CP.prn");
		if (!arch_entrada.is_open()){cout<<"El archivo no se pudo abrir";return 2;
		}
		for(int j=0;j<columnas;j++){
			for(int i=0;i<todo;i++){
				arch_entrada>>m[i][j];
				arch_entrada.ignore();
			}
		}
		//2.a
		cout<<"\n\ncalculo cP: ////////////////////////////////////////////////////\n";//b
		for(int i=0;i<n3;i++){
			for(int j=0;j<2;j++){	
				CP[i][j]=calculo_cP(m,i,j);
				cout<<CP[i][j]<<" ";  ///activar para ver
			}
			cout<<"\n";  ///activar para ver
		}
		cout<<"\n\nmedia y estandar: //////////////////////////////////////////////\n";//c.i
		for(int j=0;j<2;j++){
			
			Media[j]=calculando_la_media(CP,n3,j);
			cout<<"columna media"<<j+1<<":"<<Media[j]<<"\n";
		}
		for(int j=0;j<2;j++){
			estandar[j]=calculando_el_estandar(CP,Media,n3,j);
			cout<<"columna estandar"<<j+1<<":"<<estandar[j]<<"\n";
		}
		cout<<"\n\nmayor y menor: /////////////////////////////////////////////////\n";//c.ii
		for(int j=0;j<2;j++){
			for(int i=0;i<n3;i++){
				mayor[j]=mayor_e(CP,i,j);
				menor[j]=menor_e(CP,i,j);	
			}
			cout<<"columna"<<j+1<<" mayor:"<<mayor[j]<<"\n";
			cout<<"columna"<<j+1<<" menor:"<<menor[j]<<"\n";
		}
		cout<<"\n\nTCP: ///////////////////////////////////////////////////////////\n";//c.iii
		for(int i=0;i<n3;i++){
			TCP[i] = calculo_TCP(CP,i);
			cout<<TCP[i]<<"\n";  ///activar para ver
		}
		cout<<"\n\nvelocidad_de_Balanceo: /////////////////////////////////////////\n";//2.b
		for(int i=0;i<todo;i++){
			velocidad[i] = velocidad_de_Balanceo(TCP,n3,i);
			cout<<velocidad[i]<<"\n";  ///activar para ver
		}
		
		cout<<"\n\nValor absoluto: ////////////////////////////////////////////////\n";
		Valor_absoluto[1]=calculo_absoluto1(CP,n3);
		Valor_absoluto[2]=calculo_absoluto2(CP,n3);
		
		cout<<Valor_absoluto[1]<<"\n";  ///activar para ver;
		cout<<Valor_absoluto[2]<<"\n";  ///activar para ver;

		//guardado de archivos//
		
		ofstream arch_salida("cordenadas de CP.txt");
		if (!arch_salida.is_open()){cout<<"El archivo no se pudo crear";return 2;}
		arch_salida<<"CPx       CPy\n";
		for(int i=0;i<todo;i++){
			for(int j=0;j<2;j++){
				arch_salida<<CP[i][j]<<"   ";  
			}
			arch_salida<<"\n"; 
		}
		arch_salida.close();
		ofstream arch_entrada1("resultados de CP.txt");
		
		if (!arch_entrada1.is_open()){cout<<"El archivo no se pudo crear";return 3;}
		
		arch_entrada1<<"media y estandar: //////////////////////////////////////////////\n";
		for(int j=0;j<2;j++){
			arch_entrada1<<"columna media"<<j+1<<":"<<Media[j]<<"\n";
		}
		for(int j=0;j<2;j++){
			arch_entrada1<<"columna estandar"<<j+1<<":"<<estandar[j]<<"\n";
		}
		arch_entrada1<<"\n\nmayor y menor: /////////////////////////////////////////////\n";
		for(int j=0;j<2;j++){	
			arch_entrada1<<"columna"<<j+1<<" mayor:"<<mayor[j]<<"\n";
			arch_entrada1<<"columna"<<j+1<<" menor:"<<menor[j]<<"\n";
		}
		arch_entrada1<<"\n\nTCP: ///////////////////////////////////////////////////////\n";
		for(int i=0;i<todo;i++){
			arch_entrada1<<TCP[i]<<"\n";  
		}
		arch_entrada1<<"\n\nvelocidad de Balanceo: /////////////////////////////////////\n";
		for(int i=0;i<todo;i++){
			arch_entrada1<<velocidad[i]<<"\n";  
		}
		arch_entrada1.close();
		arch.open("CP.hea.txt");
		if (!arch.is_open()){cout<<"El archivo no se pudo abrir";return 1;}
		if (Valor_absoluto[2]>Valor_absoluto[1]){
			arch.ignore(100); 
			arch<<"\nValor absoluto de muestreo: "<<Valor_absoluto[2]<<"\nel sentido de desplazamiento del paciente durante el estudio a partir de los parámetros calculados se tratará de un desplazamiento anteroposterior\n";
		}
		else{
			arch.ignore(100); 
			arch<<"\n\nValor absoluto de muestreo: "<<Valor_absoluto[1]<<"\nel sentido de desplazamiento del paciente durante el estudio a partir de los parámetros calculados se tratará de un desplazamiento lateral\n";
		}
		arch.close();
		getch();
		return 0;		
}
	
	

