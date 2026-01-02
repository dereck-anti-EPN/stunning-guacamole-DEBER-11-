#include <iostream>
#include <vector>
using namespace std;

struct PocionMagica {
    string nombre;
    vector<string> ingredientes;
    int tiempoPreparacion;
    string efecto;
};

int funcionBusqueta(const vector<PocionMagica> & pociones){
	string ingredienteBuscado;
	bool encontrado = false;
    cout << "ingresa el nombre del ingrediente\n";
    getline(cin, ingredienteBuscado);
    cout<<"pociones: \n";
    for (size_t i = 0; i < pociones.size(); i++) {
        for (size_t j = 0; j < pociones[i].ingredientes.size(); j++) {
            if (pociones[i].ingredientes[j] == ingredienteBuscado) {
                cout <<pociones[i].nombre << "\n";
                encontrado = true;
                break;
            }
        }
    }
    if (!encontrado) {
        cout << "no hay nada parecido...\n";
    }	
	return 0;
}

int main() {
    vector<PocionMagica> pociones(3);
    pociones[0].nombre = "pocion de fuerza";
    pociones[0].ingredientes = {"maiz", "hierro", "agua"};
    pociones[0].tiempoPreparacion = 30;
    pociones[0].efecto = "super fuerza";
    
    pociones[1].nombre = "pocion de invisibilidad";
    pociones[1].ingredientes = {"hojas", "agua", "tela"};
    pociones[1].tiempoPreparacion = 45;
    pociones[1].efecto = "invisivilidad";
    
    pociones[2].nombre = "pocion de curacion";
    pociones[2].ingredientes = {"flores", "maiz", "miel"};
    pociones[2].tiempoPreparacion = 20;
    pociones[2].efecto = "curacion";
    funcionBusqueta(pociones);
    return 69;
}
