#include "Instructor.h"

//------------------Constructores------------------
Instructor::Instructor() {
	nombre = "Desconocido";
	cedula = "_";
	telefono = 0;
	email = "-";
	fechaNacimiento[0] = 0, fechaNacimiento[1] = 0, fechaNacimiento[2] = 0;
	sexo = '-';
	cantEspe = 0;
}

Instructor::Instructor(string nombre_, string cedula_, int telefono_, string email_, int diaN, int mesN, int annioN, char sexo_) {
	nombre = nombre_;
	cedula = cedula_;
	telefono = telefono_;
	email = email_;
	fechaNacimiento[0] = diaN, fechaNacimiento[1] = mesN, fechaNacimiento[2] = annioN;
	sexo = sexo_;
	cantEspe = 0;
}

//------------------Metodos get------------------
string Instructor::get_Nombre() { return nombre; };

string Instructor::get_Cedula() { return cedula; }

int Instructor::get_Telefono() { return telefono; }

string Instructor::get_Email() { return email; }

string Instructor::get_FechaNacimiento() {
	stringstream ss;
	ss << fechaNacimiento[0] << " / " << fechaNacimiento[1] << " / " << fechaNacimiento[2] << endl;
	return ss.str();
}

string Instructor::get_Especialidades() {
	stringstream ss;
	for (int i = 0; i < cantEspe; i++) {
		if (especialidad[i] != "") {
			ss << i + 1 << ". \t" << especialidad[i] << endl;
		}
	}
	return ss.str();
}

//------------------Metodos set------------------
void Instructor::set_Nombre(string nombre_) { nombre = nombre_; }

void Instructor::set_Cedula(string cedula_) { cedula = cedula_; }

void Instructor::set_Telefono(int telefono_) { telefono = telefono_; }

void Instructor::set_Email(string email_) { email = email_; }

void Instructor::set_FechaNacimiento(int d, int m, int a) { fechaNacimiento[0] = d, fechaNacimiento[1] = m, fechaNacimiento[2] = a; }


//------------------Destructor------------------
Instructor::~Instructor() {}

//------------------Metodos propios------------------
string Instructor::tostring() {
	stringstream s;
	s << "---------------- Datos Personales ----------------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "Cedula: " << cedula << endl;
	s << "Numero de telefono: " << telefono << endl;
	s << "Email: " << email << endl;
	s << "Fecha nacimiento: " << fechaNacimiento << endl;
	s << "Especialidades: " << endl;
	for (int i = 0; i < cantEspe; i++)
		s << "\t" << especialidad[i] << endl;
	return s.str();
}

bool Instructor::agregar_Especialidad(string espe) {
	if (cantEspe < 8) {
		for (int i = 0; i < cantEspe; i++) {
			if (especialidad[i] == espe)
				return false;
		}
		especialidad[cantEspe++];
		return true;
	}
	return false;
}
void Instructor::hacer_Medicion(Medicion& nuevo) { //Cliente* cli,
	for (int i = 0; i < MAX_REPORTES; i++) {
		if (reportes[i] == nullptr) {
			reportes[i] = &nuevo;
			break;
		}
	}
}
