#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Sucursal.h"

using namespace std;

class ContenedorSucursales {
private:
	Sucursal** nuevasSucursales;
	int tamano;
	int cant;
public:
	ContenedorSucursales(int);
	void agregarSucursal(Sucursal*);
	void mostrarSucursales();
	~ContenedorSucursales();
};

