#include "Cliente.h"
#include "Instructor.h"
#include "Medicion.h"

//------------------Constructores------------------
Medicion::Medicion() : peso(0.0), estatura(0.0), porcentajeGrasa(0.0), porcentajeMusculo(0.0), edadMetabolica(0), cintura(0.0), cadera(0.0), pecho(0.0), muslo(0.0) {
	clienteUno = nullptr;
	instructor = nullptr;
	fecha[0] = fecha[1] = fecha[2] = 0;
}

//------------------Metodos get------------------
string Medicion::get_Fecha() {
	stringstream ss;
	ss << fecha[0] << " / " << fecha[1] << " / " << fecha[2];
	return ss.str();
}

float Medicion::get_Peso() { return peso; }

float Medicion::get_Estatura() { return estatura; }

float Medicion::get_PorcentajeGrasa() { return porcentajeGrasa; }

float Medicion::get_PorcentajeMusculo() { return porcentajeMusculo; }

int Medicion::get_EdadMetabolica() { return edadMetabolica; }

float Medicion::get_Cintura() { return cintura; }

float Medicion::get_Cadera() { return cadera; }

float Medicion::get_Pecho() { return pecho; }

float Medicion::get_Muslo() { return muslo; }

//------------------Metodos set------------------
void Medicion::set_Peso(float peso_) { peso = peso_; }

void Medicion::set_Estatura(float estatura_) { estatura = estatura_; }

void Medicion::set_PorcentajeGrasa(float porcentajeGrasa_) { porcentajeGrasa = porcentajeGrasa_; }

void Medicion::set_PorcentajeMusculo(float porcentajeMusculo_) { porcentajeMusculo = porcentajeMusculo_; }

void Medicion::set_EdadMetabolica(float edadMetabolica_) { edadMetabolica = edadMetabolica_; }

void Medicion::set_Cintura(float cintura_) { cintura = cintura_; }

void Medicion::set_Cadera(float cadera_) { cadera = cadera_; }

void Medicion::set_Pecho(float pecho_) { pecho = pecho_; }

void Medicion::set_Muslo(float muslo_) { muslo = muslo_; }

void Medicion::set_Cliente(Cliente &c) { *clienteUno = c; }

void Medicion::set_Instructor(Instructor &i) { *instructor = i; }

//------------------Destructor------------------
Medicion::~Medicion() {}

//------------------Metodos propios------------------

float Medicion::calcularIMC() {
	if (estatura == 0) return 0;
	return peso / (estatura * estatura);
}

string Medicion::clasifIMC() {
	float imc = calcularIMC();
	string clasificacionIMC;
	if (imc <= 16.00)
		clasificacionIMC = "Delgadez severa";

	else if (imc >= 16.01 && imc <= 16.99)
		clasificacionIMC = "Delgadez moderada";

	else if (imc >= 17.00 && imc <= 18.49)
		clasificacionIMC = "Delgadez leve";

	else if (imc >= 18.5 && imc <= 24.99)
		clasificacionIMC = "Normal";

	else if (imc >= 25.00 && imc <= 29.99)
		clasificacionIMC = "Pre-Obesidad";

	else if (imc >= 30.00 && imc <= 34.99)
		clasificacionIMC = "Obesidad leve";

	else if (imc >= 35.00 && imc <= 39.99)
		clasificacionIMC = "Obesidad media";

	else if (imc >= 40.00)
		clasificacionIMC = "Obesidad morbida";

	return clasificacionIMC;
}

float Medicion::calcularGramosProt() {
	float cantidadDeProteina = 0;
	if (clienteUno->get_Sexo() == 'F' || clienteUno->get_Sexo() == 'f') {
		cantidadDeProteina = peso * 1.7;
	}
	else if (clienteUno->get_Sexo() == 'M' || clienteUno->get_Sexo() == 'm') {
		cantidadDeProteina = peso * 1.9;
	}
	return cantidadDeProteina;
}

float Medicion::vasosAgua() {
	float cantidadVasosAgua = peso / 7;
	return cantidadVasosAgua;
}

string Medicion::reporte() {
	stringstream s;
	s << "-------------------------------------------------------------------------------" << endl;
	s << "Cliente: " << clienteUno->get_Nombre() << endl;
	s << "Id: " << clienteUno->get_Cedula() << endl;
	s << "Fecha de medicion: " << get_Fecha() << endl;
	s << "El peso del cliente es de: " << peso << endl;
	s << "La estatura del cliente es de: " << estatura << endl;
	s << "El porcentaje de grasa del cliente es de: " << porcentajeGrasa << "%" << endl;
	s << "El porcentaje de musculo del cliente es de: " << porcentajeMusculo << "%" << endl;
	s << "La edad metabolica del cliente es de: " << edadMetabolica << endl;
	s << "La medida de la cintura del cliente es de: " << cintura << endl;
	s << "La medida de la cadera del cliente es de: " << cadera << endl;
	s << "La medida del pecho del cliente es de: " << pecho << endl;
	s << "La medida de los muslos del cliente es de: " << muslo << endl;
	s << "Segun el IMC, el cliente se encuentra en estado de: " << clasifIMC() << endl;
	s << "Es recomendable que la ingesta de proteinas del cliente sea de: " << calcularGramosProt() << "g." << endl;
	s << "Es recomendable que el consumo de vasos de agua del cliente sea de: " << vasosAgua() << endl;
	s << "-------------------------------------------------------------------------------" << endl;
	return s.str();

}

