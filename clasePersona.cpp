#include <iostream>
#include <string>
using namespace std;

class Persona {
	string nombre;
public:
	
	Persona() : nombre("") {}
	Persona(string n) : nombre(n) {}
	string get_nombre(){ return nombre;}
	void set_nombre(string n){ nombre=n;}
};
const int TAM=10;
class GestorPersonas {
private:
	
	Persona personas[TAM]; // Tamaño fijo para simplificar el ejemplo
	int tamanoActual;
	
public:
	GestorPersonas() : tamanoActual(0) {}
	
	void agregarPersona(const Persona& p) {
		if(tamanoActual < 10) {
			personas[tamanoActual++] = p;
		} else {
			cout << "Arreglo lleno." << endl;
		}
	}
	
	void imprimirPersonas() {
		for(int i = 0; i < tamanoActual; ++i) {
			cout << personas[i].get_nombre() << endl;
		}
	}
	
	int buscarPersona(const string& nombre) {
		for(int i = 0; i < tamanoActual; ++i) {
			if(personas[i].get_nombre() == nombre) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	GestorPersonas gestor;
	Persona p;
	p.set_nombre("Juan");
	gestor.agregarPersona(p);
	p.set_nombre("Ana");
	
	gestor.agregarPersona(p);
	gestor.imprimirPersonas();
	
	string nombreABuscar = "Ana";
	int indice = gestor.buscarPersona(nombreABuscar);
	if(indice != -1) {
		cout << "Persona encontrada en el índice " << indice << endl;
	} else {
		cout << "Persona no encontrada." << endl;
	}
	
	return 0;
}
