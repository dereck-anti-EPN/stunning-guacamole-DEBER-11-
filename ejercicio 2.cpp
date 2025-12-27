#include<iostream>
using namespace std;

int dulzura(int tabletaChocolate[4][6]){
	int sumaPromedio=0;
	for(int i=0;i<4;i++){//fila
		cout<<"fila #"<<i+1<<"\n";
		for(int j=0;j<6;j++){//columna
			cout<<"columna #"<<j+1<<"\n";
			cin>>tabletaChocolate[i][j];
			if(tabletaChocolate[i][j]>9 or tabletaChocolate[i][j]<1){
				cout<<"incorrecto, la dulzura sera 1\n";
				tabletaChocolate[i][j]=1;
			}
			sumaPromedio+=tabletaChocolate[i][j];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<6;j++){
			cout<<tabletaChocolate[i][j];
		}
		cout<<"\n";
	}
	return sumaPromedio;
}

int main(){
	int tabletaChocolate[4][6];
	int promedio=dulzura(tabletaChocolate)/24;
	cout<<"promedio de dulzura: "<<promedio;
	return 69;
}
