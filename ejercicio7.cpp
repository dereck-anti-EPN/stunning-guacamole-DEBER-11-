#include<iostream>
#include<vector>
using namespace std;

int horaDevuelta(string chat[], string horaArreglo[], string usurioArreglo[], string mensajeArreglo[], int &sumaRoberto,int &sumaBelen){
    
	for(int i = 0; i < 6; i++){
        horaArreglo[i] = chat[i].substr(0, 5);
    }
    for(int i=0;i<6;i++){
		if(chat[i].find("Roberto") != string::npos){
			sumaRoberto++;
			usurioArreglo[i]=chat[i].substr(7,7);
			mensajeArreglo[i]=chat[i].substr(16,-1);
		}else if(chat[i].find("Belen") != string::npos){
			sumaBelen++;
			usurioArreglo[i]=chat[i].substr(7,5);
			mensajeArreglo[i]=chat[i].substr(14,-1);
		}
	}
	for(int i=0;i<6;i++){
		cout<<horaArreglo[i]<<"\n";
		cout<<usurioArreglo[i]<<"\n";
		cout<<mensajeArreglo[i]<<"\n";
	}
	cout<<"mensajes de roberto: "<<sumaRoberto<<"\nmensajes de belen: "<<sumaBelen;
	return 0;
}

int main(){
	string chat[] = {
	"08:15//Roberto//Hola perdida, como estas?",
	"08:17//Belen//Bien, gracias. Y tu?",
	"08:20//Roberto//Aqui pensandote. Quieres salir al cine hoy?",
	"08:21//Belen//Tu novia, si te da permiso?",
	"08:22//Roberto//Cual novia?. Es una amiga nomas",
	"08:23//Roberto//mejor tu pide permiso a tu novio?"
	};
	string horaArreglo[6], usurioArreglo[6], mensajeArreglo[6];
	int sumaRoberto=0,sumaBelen=0;
	horaDevuelta(chat, horaArreglo, usurioArreglo,mensajeArreglo, sumaRoberto, sumaBelen);
    return 69;
}
