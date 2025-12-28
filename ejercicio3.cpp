#include<iostream>
using namespace std;

void destruccion(char barcoMatriz[6][6]){
	int volatilFila=0, volatilColumna=0;
	cout<<"fila y columna\n";
	cin>>volatilFila;
	cin>>volatilColumna;
	while(volatilFila > 5 or volatilFila<0 or volatilColumna>5 or volatilColumna<0){
		cout<<"ta mal\n";
		cin>>volatilFila;
		cin>>volatilColumna;		
	}
	if(barcoMatriz[volatilFila][volatilColumna]=='b'){
		cout<<"le atinaste";
	}else{
		cout<<"no le atinaste";
	}
}

int main(){
	char barcoMatriz[6][6]{
		{'-','b','b','b','-','-'},
		{'-','-','-','-','-','-'},
		{'-','-','-','-','-','-'},
		{'-','-','-','-','-','-'},
		{'-','-','-','-','-','-'},
		{'-','-','-','-','-','-'}
	};
	destruccion(barcoMatriz);
	return 69;
}
