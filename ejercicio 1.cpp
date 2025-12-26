#include<iostream>
using namespace std;
struct vehiculo{
	string marca;
	string modelo;
	int anio;
};

void crear(vehiculo arregloVehiculos[]){
	for(int i=0;i<5;i++){
		cout<<"ingrese los datos del vehiculo\n";
		cout<<"marca: ";
		cin>>arregloVehiculos[i].marca;
		cout<<"modelo: ";
		cin>>arregloVehiculos[i].modelo;
		cout<<"anio: ";
		cin>>arregloVehiculos[i].anio;			
	}
}

void mostrar(vehiculo arregloVehiculos[]){
	for(int i=0;i<5;i++){
		cout<<"vehiculo #"<<i+1<<"\n";
		cout<<arregloVehiculos[i].marca<<"\n";
		cout<<arregloVehiculos[i].modelo<<"\n";
		cout<<arregloVehiculos[i].anio<<"\n";
	}
}

int main(){
	vehiculo arregloVehiculos[5];
	crear(arregloVehiculos);
	mostrar(arregloVehiculos);
}
