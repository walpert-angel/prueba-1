#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct post{
	long DNI;
	string NyA;
	long tel;
};
float calc_punt(int x, int y, int z, int w){
	float calc;
	calc=(x*2)+(y*3)+(z*4)+(w*5);
	return calc;
}
	using namespace std;
	int main(int argc, char *argv[]) {
		int xx=0;int cont=0;
		int pocicion[100];
		int aux=0;
		int j=0;
		
		ifstream archivo;
		post ayn_postul[1000][2];
		archivo.open("aspirantes.txt");
		if(archivo.fail()){
			cout<<"error";}
		else{
			
			while ( !archivo.eof() ) {
				archivo >> ayn_postul[cont][0].DNI;
				getline(archivo,ayn_postul[cont][0].NyA);
				getline(archivo,ayn_postul[cont][1].NyA);
				archivo >> ayn_postul[cont][0].tel;
				archivo.ignore();
				cont++;
				
				cout<<"DNI: "<<ayn_postul[cont-1][0].DNI<<endl;
				cout<<"Apellido y Nombre: "<<ayn_postul[cont-1][1].NyA<<endl;
				cout<<"Teléfono: "<<ayn_postul[cont-1][0].tel<<endl<<endl;
				
				
			}
		}
		
		long postulantes_puntos[1000][5];

		for(xx=0;xx<cont;xx++){
		cout<<"\nDNI del postulate N"<<xx+1<<": "<<ayn_postul[xx][0].DNI;
		cout<<"\npuntaje de aptitud fisica(AF): ";cin>>postulantes_puntos[xx][1];
		cout<<"puntaje de capacidad adaptacion(CA): ";cin>>postulantes_puntos[xx][2];
		cout<<"puntaje de capacidad operativa(CO): ";cin>>postulantes_puntos[xx][3];
		cout<<"puntaje de conocimientos especificos(CI): ";cin>>postulantes_puntos[xx][4];
		
		postulantes_puntos[xx][5]=calc_punt(postulantes_puntos[xx][1],postulantes_puntos[xx][2],postulantes_puntos[xx][3],postulantes_puntos[xx][4]);	
		pocicion[xx]=postulantes_puntos[xx][5];
		
		
		}
		for(int yy=0;yy<cont;yy++){
			for(int zz=0;zz<cont;zz++){
			if(pocicion[zz]<pocicion[zz+1]){
	
				aux = pocicion[zz];
				
				pocicion[zz] = pocicion[zz+1];
				
				pocicion[zz+1]=aux;
			}	
			}		
	}
		
		
		cout<<"    DNI   |  AF  |  CA  |  CO  |  CI  |  Puntaje Final";
		for(int xx=0;xx<cont+1;xx++){
			for(int zz=0;zz<cont;zz++){
			if(pocicion[xx]==postulantes_puntos[zz][5] && postulantes_puntos[xx][5] != postulantes_puntos[zz][5]){
			j++;	
			cout<<"\n"<<j<<" "<<postulantes_puntos[zz][5];
			cout<<"\n"<<ayn_postul[zz][0].DNI<<"   "<<postulantes_puntos[zz][1]<<"   "<<postulantes_puntos[zz][2]<<"   "<<postulantes_puntos[zz][3]<<"   "<<postulantes_puntos[zz][4]<<"   "<<postulantes_puntos[zz][5];

			}
			}
		}

		archivo.close();
		return 0;
	}
