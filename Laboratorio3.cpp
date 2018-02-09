#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void Ejercicio2();
void Ejercicio1();
char CalcularMediana(string,int);
string Ordenar(string);
void Ordenararreglos(string*&,int);

int main(){
	cout<<"Menu"<<endl;
	cout<<"1.Ejercicio 1"<<endl;
	cout<<"2.Ejercicio 2"<<endl;
	cout<<"3.Ejercicio 3"<<endl;
	cout<<"---------------------";
	int op;
	cin>>op;
	switch(op){
		case 1:
			Ejercicio1();
			break;
		case 2:
			break;
		case 3:
			break;
	}
	return 0;
}
string Ordenar(string cadena){
	for(int i=0;i<cadena.size();i++){
		for(int j=i;j<cadena.size();j++){
			if(j+1!=cadena.size()){
				if((int)cadena.at(i)>(int)cadena.at(j+1)&&j!=cadena.size()-1){
					char k=cadena.at(i);
					cadena[i]=cadena[j+1];
					cadena[j+1]=k;
				}
			}
		}
	}
	cout<<cadena<<endl;
	return cadena;
}
void Ejercicio1(){
	cout<<"Ingrese el arreglo para calcular la mediana"<<endl;
	string cadena;
	cin>>cadena;
	if(cadena.size()%5!=0){
		for(int i=0;i<(cadena.size()%5)-1;i++){
			cadena+="0";
		}
	}
	cadena=Ordenar(cadena);
	//cout<<cadena<<endl;
	cout<<"la mediana total es: "<<CalcularMediana(cadena,cadena.size())<<endl;		
}
char CalcularMediana(string cadena,int size){
	//cout<<cadena<<endl;
	if(size <= 5){
		//cout<<cadena<<endl;
		if(size%2==0){
			return cadena[(size/2)];
		}else{
			return cadena[((size+1)/2)-1];
		}
	}else{
		//cout<<cadena<<endl;
		string medianas="";
		for(int i=0;i<(size)/5;i++){
			//cout<<cadena.at(i)<<endl;
			string cadenaPrueba="";
			for(int j=0;j<5;j++){
				cadenaPrueba+=cadena[j+(i*5)];
			}
			medianas+=CalcularMediana(cadenaPrueba,5);
		}
		return CalcularMediana(medianas,size/5);
	}

}
void Ejercicio2(){
	cout<<"Ingrese la sucesion"<<endl;
	string sucesion;
	cin>>sucesion;
	char d1=sucesion[0];
	char d2=sucesion[1];
	char d3=sucesion[2];
	char d4=sucesion[3];	
	string* array=new string[4];
	array[0]=d1+d2+d3+d4;
	array[1]=d2+d3+d4+d1;
	array[2]=d3+d4+d1+d2;
	array[3]=d4+d1+d2+d3;
	array[4]=d2+d1+d3+d4;
	array[5]=d2+d3+d1+d4;
	array[6]=d4+d3+d2+d1;
	array[7]=d3+d4+d2+d1;
	array[8]=d3+d2+d4+d2;
	array[9]=d1+d3+d4+d2;
	array[10]=d1+d4+d3+d2;
	array[11]=d4+d2+d3+d1;
	Ordenararreglos(array,12);
	for(int i=0;i<12;i++){
		cout<<array[i]<<endl;
	}
	
}
void Ordenararreglos(string*& arreglo,int size){
	for(int i=0;i<size;i++){
		for(int j=i;i<size;i++){
			if(j!=size){
				if(atoi(arreglo[i].c_str())>atoi(arreglo[j+1].c_str())){
					string cambio=arreglo[i];
					arreglo[i]=arreglo[j+1];
					arreglo[j+1]=cambio;
				}
			}
		}

	}
}
