#include "ContenedorSucursales.h"

ContenedorSucursales::ContenedorSucursales(int cap) : tamano(30), cant(0) {
	nuevasSucursales = new Sucursal * [tamano];
}
void ContenedorSucursales::agregarSucursal(Sucursal* suc) {
	if (cant < tamano) {
		nuevasSucursales[cant++] = suc;
	}
	else {
		cout << "Contenedor lleno\n";
	}
}
void ContenedorSucursales::mostrarSucursales() {
	for (int i = 0; i < cant; i++) {
		cout << nuevasSucursales[i]->tostring() << endl;
	}
}
ContenedorSucursales::~ContenedorSucursales() {
	for (int i = 0; i < cant; i++) {
		delete nuevasSucursales[i];
	}
	delete[] nuevasSucursales;
}