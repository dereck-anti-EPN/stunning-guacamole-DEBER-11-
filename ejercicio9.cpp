#include<iostream>
#include<vector>
using namespace std;

struct Pelicula{
	int id;
	string titulo;
	string director;
	bool enCartelera;
};

void menu(int &opcion){
	cout<<"1.registrar\n2.mostrar\n3.buscar\n4.cambiar estado\n5.eliminar\n6.filtrar por estado\n7.salir\n";
	cin>>opcion;
}

void registrar(vector<Pelicula> &peliculas){
	Pelicula p;
	cout<<"id: ";
	cin>>p.id;
	cin.ignore();
	cout<<"titulo: ";
	getline(cin,p.titulo);
	cout<<"director: ";
	getline(cin,p.director);
	cout<<"en cartelera (1 si / 0 no): ";
	cin>>p.enCartelera;
	peliculas.push_back(p);
}

void mostrar(const vector<Pelicula> &peliculas){
	for(size_t i=0;i<peliculas.size();i++){
		cout<<peliculas[i].id<<"\n";
		cout<<peliculas[i].titulo<<"\n";
		cout<<peliculas[i].director<<"\n";
		if(peliculas[i].enCartelera==true){
			cout<<"en cartelera\n";
		}else{
			cout<<"fuera de cartelera\n";
		}
	}
}

void buscar(const vector<Pelicula> &peliculas){
	int idVolatil;
	bool encontrado=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<peliculas.size();i++){
		if(idVolatil==peliculas[i].id){
			cout<<peliculas[i].id<<"\n";
			cout<<peliculas[i].titulo<<"\n";
			cout<<peliculas[i].director<<"\n";
			if(peliculas[i].enCartelera==true){
				cout<<"en cartelera\n";
			}else{
				cout<<"fuera de cartelera\n";
			}
			encontrado=true;
			break;
		}
	}
	if(encontrado==false){
		cout<<"no existe esa id\n";
	}
}

void cambiarEstado(vector<Pelicula> &peliculas){
	int idVolatil;
	bool encontrado=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<peliculas.size();i++){
		if(idVolatil==peliculas[i].id){
			peliculas[i].enCartelera=!peliculas[i].enCartelera;
			encontrado=true;
			break;
		}
	}
	if(encontrado==false){
		cout<<"no existe esa id\n";
	}
}

void eliminar(vector<Pelicula> &peliculas){
	int idVolatil;
	bool encontrado=false;
	cout<<"id: ";
	cin>>idVolatil;
	for(size_t i=0;i<peliculas.size();i++){
		if(idVolatil==peliculas[i].id){
			peliculas.erase(peliculas.begin()+i);
			encontrado=true;
			break;
		}
	}
	if(encontrado==false){
		cout<<"no existe esa id\n";
	}
}

void filtrar(const vector<Pelicula> &peliculas){
	bool estado;
	cout<<"estado (1 cartelera / 0 fuera): ";
	cin>>estado;
	for(size_t i=0;i<peliculas.size();i++){
		if(peliculas[i].enCartelera==estado){
			cout<<peliculas[i].id<<"\n";
			cout<<peliculas[i].titulo<<"\n";
			cout<<peliculas[i].director<<"\n";
		}
	}
}

int main(){
	vector<Pelicula> peliculas;
	int opcion=0;
	menu(opcion);
	while(opcion!=7){
		switch(opcion){
			case 1:
				registrar(peliculas);
				menu(opcion);
				break;
			case 2:
				mostrar(peliculas);
				menu(opcion);
				break;
			case 3:
				buscar(peliculas);
				menu(opcion);
				break;
			case 4:
				cambiarEstado(peliculas);
				menu(opcion);
				break;
			case 5:
				eliminar(peliculas);
				menu(opcion);
				break;
			case 6:
				filtrar(peliculas);
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
