#include "Sucursal.h"

//------------------Constructores------------------
Sucursal::Sucursal() : nombre("Sin definir"), provincia("Sin definir"), canton("Sin definir"), telefono("Sin definir"), email("Sin definir"), codigo(0) {
	cantInstructores = 0;
	cantClientes = 0;
	cantSesiones = 0;
	for (int i = 0; i < maxInstructores; i++) {
		instructores[i] = nullptr;
	}
	for (int j = 0; j < maxClientes; j++) {
		clientes[j] = nullptr;
	}
	for (int k = 0; k < maxSesiones; k++) {
		sesiones[k] = nullptr;
	}
}
Sucursal Sucursal::crearSucursal(string nombre_, string provincia_, string canton_, string telefono_, string email_, int codigo_) {
	nombre = nombre_;
	provincia = provincia_;
	canton = canton_;
	telefono = telefono_;
	email = email_;
	codigo = codigo_;
}

//------------------Metodos get------------------
string Sucursal::get_Nombre() { return nombre; }
string Sucursal::get_Provincia() { return provincia; }
string Sucursal::get_Canton() { return canton; }
string Sucursal::get_Telefono() { return telefono; }
string Sucursal::get_Email() { return email; }
int Sucursal::get_Codigo() { return codigo; }

//------------------Metodos set------------------
void Sucursal::set_Nombre(string n) { nombre = n; }
void Sucursal::set_Provincia(string p) { provincia = p; }
void Sucursal::set_Canton(string c) { canton = c; }
void Sucursal::set_Telefono(string t) { telefono = t; }
void Sucursal::set_Email(string e) { email = e; }
void Sucursal::set_Codigo(int cod) { codigo = cod; }

//------------------Metodos propios------------------
void Sucursal::agregarInstructor(Instructor* inst) {
	if (cantInstructores < maxInstructores) {
		instructores[cantInstructores++] = inst;
	}
	else {
		cout << "No se pueden agregar mas instructores a la sucursal\n";
	}
}
void Sucursal::agregarCliente(Cliente* cli) {
	if (cantClientes < maxClientes) {
		clientes[cantClientes++] = cli;
	}
	else {
		cout << "No se pueden agregar mas clientes a la sucursal\n";
	}
}
void Sucursal::agregarSesion(SesionGrupal* ses) {
	if (cantSesiones < maxSesiones) {
		sesiones[cantSesiones++] = ses;
	}
	else {
		cout << "No se pueden agregar mas sesiones a la sucursal\n";
	}
}
string Sucursal::tostring() {
	stringstream ss;
	ss << "-------- Datos de la Sucursal --------" << endl << endl;
	ss << "Nombre: " << nombre << endl;
	ss << "Provincia: " << provincia << endl;
	ss << "Canton: " << canton << endl;
	ss << "Telefono: " << telefono << endl;
	ss << "Email: " << email << endl;
	ss << "Codigo: " << codigo << endl;
	return ss.str();
}
//------------------Destructor------------------
Sucursal::~Sucursal() {
	for (int i = 0; i < cantInstructores; i++) {
		delete instructores[i];
	}
	delete[] instructores;
	for (int j = 0; j < cantClientes; j++) {
		delete clientes[j];
	}
	delete[] clientes;
	for (int k = 0; k < cantSesiones; k++) {
		delete sesiones[k];
	}
	delete[] sesiones;
}
