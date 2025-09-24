#include "HistorialMediciones.h"
#include <sstream>
//------------------Constructores------------------
HistorialMediciones::HistorialMediciones() : cantidad(0) {
	for (int i = 0; i < MAX_MEDICIONES; i++) {
		mediciones[i] = nullptr;
	}
}
//------------------Metodos get-------------------
int HistorialMediciones::get_CantidadMediciones() const { return cantidad; }

Medicion* HistorialMediciones::get_Medicion(int pos) const {
	if (pos >= 0 && pos < cantidad) {
		return mediciones[pos];
	}
	return nullptr;
}

//------------------Destructor--------------------
HistorialMediciones::~HistorialMediciones() {
	for (int i = 0; i < cantidad; i++) {
		delete mediciones[i];
	}
	delete[] mediciones;
}
//------------------Metodos Propios---------------
bool HistorialMediciones::agregar_Medicion(Medicion* nuevaMedicion) {
	if (cantidad < MAX_MEDICIONES) {
		mediciones[cantidad++] = nuevaMedicion;
		return true;
	}
	return false;
}
bool HistorialMediciones::eliminar_Medicion(int pos) {
	if (pos >= 0 && pos < cantidad) {
		delete mediciones[pos];
		for (int i = pos; i < cantidad - 1; i++) {
			mediciones[i] = mediciones[i + 1];
		}
		mediciones[cantidad - 1] = nullptr;
		cantidad--;
		return true;
	}
	return false;
}
string HistorialMediciones::mostrar_HistorialMediciones() {
	stringstream s;
	s << "================== Historial de Mediciones ==================" << endl;
	for (int i = 0; i < cantidad; i++) {
		if (mediciones[i] != nullptr) {
			s << mediciones[i]->reporte() << endl;
		}
	}
	s << "============================================================" << endl;
	return s.str();
}
