#include<iostream>
#include<vector>
using namespace std;
struct structEstudiantes{
	int id;
	string nombre;
	string carrera;
	float promedio;
};

void menu(int &opcion){
	cout<<"1.registrar\n2.mostrar\n3.buscar\n4.actualizar\n5.eliminar\n6.estudiantes aprobados\n7.salir\n";
	cin>>opcion;
}

void registrar(vector<structEstudiantes> &vectorEstudiantes, structEstudiantes estudiante){
	cout<<"id, nombre, carrera y promedio\n";
	cin>>estudiante.id;
	cin>>estudiante.nombre;
	cin.ignore();
	getline(cin, estudiante.carrera);
	cin>>estudiante.promedio;
	vectorEstudiantes.push_back(estudiante);
}

void mostrar(vector<structEstudiantes> vectorEstudiantes){
	for(size_t i=0;i<vectorEstudiantes.size();i++){
		cout<<vectorEstudiantes[i].id<<"\n";
		cout<<vectorEstudiantes[i].nombre<<"\n";
		cout<<vectorEstudiantes[i].carrera<<"\n";
		cout<<vectorEstudiantes[i].promedio<<"\n";
	}
}

void buscar(vector<structEstudiantes> vectorEstudiantes){
	int idVolatil=0;
	bool boleanoVolatil=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<vectorEstudiantes.size();i++){
		if(idVolatil == vectorEstudiantes[i].id){
			cout<<"encontrado\n";
			cout<<vectorEstudiantes[i].id<<"\n";
			cout<<vectorEstudiantes[i].nombre<<"\n";
			cout<<vectorEstudiantes[i].carrera<<"\n";
			cout<<vectorEstudiantes[i].promedio<<"\n";
			boleanoVolatil=true;
			break;
		}
	}if(boleanoVolatil==false){
		cout<<"no existe esa id\n";
	}
	
}

void actualizar(vector<structEstudiantes> &vectorEstudiantes){
	int idVolatil=0;
	bool boleanoVolatil=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<vectorEstudiantes.size();i++){
		if(idVolatil == vectorEstudiantes[i].id){
			cout<<"encontrado\n";
			cin>>vectorEstudiantes[i].id;
			cin>>vectorEstudiantes[i].nombre;
			cin.ignore();
			getline(cin, vectorEstudiantes[i].carrera);
			cin>>vectorEstudiantes[i].promedio;
			boleanoVolatil=true;
			break;
		}
	}if(boleanoVolatil==false){
		cout<<"no existe esa id\n";
	}
	
}

void eliminar(vector<structEstudiantes> &vectorEstudiantes){
	int idVolatil=0;
	bool boleanoVolatil=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<vectorEstudiantes.size();i++){
		if(idVolatil == vectorEstudiantes[i].id){
			cout<<"encontrado\n";
			vectorEstudiantes.erase(vectorEstudiantes.begin() + i);
			boleanoVolatil=true;
			break;
		}
	}
	if(boleanoVolatil==false){
		cout<<"no existe esa id\n";
	}
}

vector<structEstudiantes> aprobados(vector<structEstudiantes> vectorEstudiantes, vector<structEstudiantes> &estudiantesAprobados){
	for(size_t i=0;i<vectorEstudiantes.size();i++){
		if(vectorEstudiantes[i].promedio>=14){
			estudiantesAprobados.push_back(vectorEstudiantes[i]);
		}
	}
	return estudiantesAprobados;
}

void impresionAprobados(vector<structEstudiantes> estudiantesAprobados){
	for(size_t i=0;i<estudiantesAprobados.size();i++){
		cout<<estudiantesAprobados[i].id<<"\n";
		cout<<estudiantesAprobados[i].nombre<<"\n";
		cout<<estudiantesAprobados[i].carrera<<"\n";
		cout<<estudiantesAprobados[i].promedio<<"\n";
	}
}

int main(){
	vector<structEstudiantes> vectorEstudiantes;
	vector<structEstudiantes> estudiantesAprobados;
	int opcion=0;
	structEstudiantes estudiante;
	menu(opcion);
	while(opcion!=7){
		switch (opcion) {
			case 1:
				registrar(vectorEstudiantes, estudiante);
				menu(opcion);
				break;
			case 2:
				mostrar(vectorEstudiantes);
				menu(opcion);
				break;
			case 3:
				buscar(vectorEstudiantes);
				menu(opcion);
				break;				
			case 4:
				actualizar(vectorEstudiantes);
				menu(opcion);
				break;				
			case 5:
				eliminar(vectorEstudiantes);
				menu(opcion);
				break;				
			case 6:
				aprobados(vectorEstudiantes, estudiantesAprobados);
				impresionAprobados(estudiantesAprobados);
				menu(opcion);
				break;				
			default:
				cout<<"intenta de nuevo\n";
				menu(opcion);
				break;
		}
	}
	cout<<"tchau";
    return 69;
}
