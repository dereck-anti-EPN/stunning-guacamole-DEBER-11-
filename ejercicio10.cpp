#include<iostream>
#include<vector>
using namespace std;

struct Jugador{
	int id;
	string nombre;
	string posicion;
	int edad;
};

struct Equipo{
	int id;
	string nombre;
	string entrenador;
	vector<Jugador> jugadores;
};

void menu(int &opcion){
	cout<<"1.registrar equipo\n2.agregar jugador\n3.listar equipos\n4.buscar equipo\n5.eliminar jugador\n6.filtrar por entrenador\n7.eliminar equipo\n8.salir\n";
	cin>>opcion;
}

void registrarEquipo(vector<Equipo> &equipos){
	Equipo e;
	cout<<"id: ";
	cin>>e.id;
	cin.ignore();
	cout<<"nombre: ";
	getline(cin,e.nombre);
	cout<<"entrenador: ";
	getline(cin,e.entrenador);
	equipos.push_back(e);
}

void agregarJugador(vector<Equipo> &equipos){
	int idEquipo;
	cout<<"id equipo: ";
	cin>>idEquipo;
	for(size_t i=0;i<equipos.size();i++){
		if(equipos[i].id==idEquipo){
			Jugador j;
			cout<<"id jugador: ";
			cin>>j.id;
			cin.ignore();
			cout<<"nombre: ";
			getline(cin,j.nombre);
			cout<<"posicion: ";
			getline(cin,j.posicion);
			cout<<"edad: ";
			cin>>j.edad;
			equipos[i].jugadores.push_back(j);
			break;
		}
	}
}

void listar(const vector<Equipo> &equipos){
	for(size_t i=0;i<equipos.size();i++){
		cout<<equipos[i].id<<"\n";
		cout<<equipos[i].nombre<<"\n";
		cout<<equipos[i].entrenador<<"\n";
		for(size_t j=0;j<equipos[i].jugadores.size();j++){
			cout<<equipos[i].jugadores[j].id<<"\n";
			cout<<equipos[i].jugadores[j].nombre<<"\n";
			cout<<equipos[i].jugadores[j].posicion<<"\n";
			cout<<equipos[i].jugadores[j].edad<<"\n";
		}
	}
}

void buscarEquipo(const vector<Equipo> &equipos){
	int idVolatil;
	bool encontrado=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<equipos.size();i++){
		if(equipos[i].id==idVolatil){
			cout<<equipos[i].id<<"\n";
			cout<<equipos[i].nombre<<"\n";
			cout<<equipos[i].entrenador<<"\n";
			for(size_t j=0;j<equipos[i].jugadores.size();j++){
				cout<<equipos[i].jugadores[j].id<<"\n";
				cout<<equipos[i].jugadores[j].nombre<<"\n";
				cout<<equipos[i].jugadores[j].posicion<<"\n";
				cout<<equipos[i].jugadores[j].edad<<"\n";
			}
			encontrado=true;
			break;
		}
	}
	if(encontrado==false){
		cout<<"no existe ese equipo\n";
	}
}

void eliminarJugador(vector<Equipo> &equipos){
	int idJugador;
	cout<<"id jugador: ";
	cin>>idJugador;
	for(size_t i=0;i<equipos.size();i++){
		for(size_t j=0;j<equipos[i].jugadores.size();j++){
			if(equipos[i].jugadores[j].id==idJugador){
				equipos[i].jugadores.erase(equipos[i].jugadores.begin()+j);
				return;
			}
		}
	}
	cout<<"no existe ese jugador\n";
}

void filtrarEntrenador(const vector<Equipo> &equipos){
	string entrenadorVolatil;
	cin.ignore();
	cout<<"entrenador: ";
	getline(cin,entrenadorVolatil);
	for(size_t i=0;i<equipos.size();i++){
		if(equipos[i].entrenador==entrenadorVolatil){
			cout<<equipos[i].id<<"\n";
			cout<<equipos[i].nombre<<"\n";
		}
	}
}

void eliminarEquipo(vector<Equipo> &equipos){
	int idVolatil;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<equipos.size();i++){
		if(equipos[i].id==idVolatil){
			equipos.erase(equipos.begin()+i);
			return;
		}
	}
	cout<<"no existe ese equipo\n";
}

int main(){
	vector<Equipo> equipos;
	int opcion=0;
	menu(opcion);
	while(opcion!=8){
		switch(opcion){
			case 1:
				registrarEquipo(equipos);
				menu(opcion);
				break;
			case 2:
				agregarJugador(equipos);
				menu(opcion);
				break;
			case 3:
				listar(equipos);
				menu(opcion);
				break;
			case 4:
				buscarEquipo(equipos);
				menu(opcion);
				break;
			case 5:
				eliminarJugador(equipos);
				menu(opcion);
				break;
			case 6:
				filtrarEntrenador(equipos);
				menu(opcion);
				break;
			case 7:
				eliminarEquipo(equipos);
				menu(opcion);
				break;
			default:
				menu(opcion);
				break;
		}
	}
	cout<<"tchau";
	return 69;
}
