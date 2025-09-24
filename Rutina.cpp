#include "Ejercicio.h"
#include "Instructor.h"
#include "Rutina.h"

//------------------Constructor--------------------
Rutina::Rutina() {
	instructor = nullptr;
	cant = 0;
	fecha[0] = 00;
	fecha[1] = 00;
	fecha[2] = 0000;
	for (int i = 0; i < MAX_EJERCICIOS; i++) {
		eje[i] = nullptr;
	}
}

//------------------Metodos get--------------------
string Rutina::get_Fecha() {
	stringstream ss;
	ss << fecha[0] << " / " << fecha[1] << " / " << fecha[2];
	return ss.str();
}

Ejercicio* Rutina::get_Ejercicio(string nom) {
	for (int i = 0; i < cant; i++) {
		if (eje[i] != nullptr && eje[i]->get_Nombre() == nom)
			return eje[i];
	}
	return nullptr;
}

Instructor* Rutina::get_Instructor() { return instructor; }

int Rutina::get_CantidadEjercicios() const { return cant; }

//------------------Metodos set--------------------
// para cambiar el ejercicio, eliminar y agregar es mejor
void Rutina::set_Fecha(int d, int m, int a) {
	fecha[0] = d;
	fecha[1] = m;
	fecha[2] = a;
}

void Rutina::set_ejercicio(string nomEliminar, Ejercicio* nuevoEje) {
	for (int i = 0; i < cant; i++) {
		if (eje[i]->get_Nombre() == nomEliminar) {
			eje[i] = nuevoEje;
			break;
		}
	}
}

void Rutina::set_instructor(Instructor* ins) { instructor = ins; }


//------------------Destructor------------------
Rutina::~Rutina() {
	for (int i = 0; i < cant; i++) {
		delete eje[i];
	}
	delete[]eje;

	//no elimina al instructor
}

//------------------Metodos propios------------------
bool Rutina::agregar_Ejercicio(Ejercicio* nuevo) {
	if (cant < MAX_EJERCICIOS) {
		eje[cant] = nuevo;
		cant++;
		return true;
	}
	return false;
}

bool Rutina::eliminar_Ejercicio(string nom) {
	for (int i = 0; i < cant; i++) {
		if (eje[i]->get_Nombre() == nom) {
			delete eje[i]; //libera memoria

			for (int j = i; j < cant - 1; j++) { //acomoda el arreglo
				eje[j] = eje[j + 1];
			}
			cant--;
			return true;
		}
	}
	return false;
}

string Rutina::Mostrar_Rutina() {
	stringstream ss;
	ss << "------------------ Rutina ------------------" << endl;
	ss << "Fecha: " << get_Fecha() << endl;
	if (instructor != nullptr)
		ss << "Instructor: " << instructor->get_Nombre() << endl;
	else
		ss << "Instructor: No asignado" << endl; 
	ss << "Ejercicios:" << endl;
	for (int i = 0; i < cant; i++) {
		ss << "\t" << i + 1 << ". " << eje[i]->mostrarEjercicio() << endl;
	}
	return ss.str();
}

