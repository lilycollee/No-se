#include "SesionGrupal.h"

//------------------Constructores------------------

SesionGrupal::SesionGrupal() {
    codigo = 0;
    nombre = "Sin nombre";
    salon = "Sin salon";
    horario[0] = horario[1] = horario[2] = horario[3] = 0;
    cupoMax = max_clientes;
    instructor = nullptr;
    clientesInscritos = new Cliente * [max_clientes];
    for (int i = 0; i < max_clientes; i++) {
        clientesInscritos[i] = nullptr;
    }
}

SesionGrupal::SesionGrupal(Instructor* inst, string nombre, string salon, int hInicio, int mInicio, int hFin, int mFin, int cupo, int cod) {
    this->codigo = cod;
    this->nombre = nombre;
    this->salon = salon;
    horario[0] = hInicio;
    horario[1] = mInicio;
    horario[2] = hFin;
    horario[3] = mFin;
    this->cupoMax = (cupo <= max_clientes) ? cupo : max_clientes;
    this->instructor = inst;

    clientesInscritos = new Cliente * [max_clientes];
    for (int i = 0; i < max_clientes; i++) {
        clientesInscritos[i] = nullptr;
    }
}

//------------------Metodos set------------------

void SesionGrupal::set_Instructor(Instructor* inst) {
    instructor = inst;
}

void SesionGrupal::set_Salon(string salon) {
    this->salon = salon;
}

void SesionGrupal::set_HoraInicio(int h, int m) {
    horario[0] = h;
    horario[1] = m;
}

void SesionGrupal::set_HoraFinal(int h, int m) {
    horario[2] = h;
    horario[3] = m;
}

//------------------Metodos get------------------

int SesionGrupal::get_Codigo() {
    return codigo;
}

string SesionGrupal::get_Nombre() {
    return nombre;
}

string SesionGrupal::get_Salon() {
    return salon;
}

int SesionGrupal::get_CupoMax() {
    return cupoMax;
}

Instructor* SesionGrupal::get_Instructor() {
    return instructor;
}

string SesionGrupal::get_Horario() {
    stringstream ss;
    ss << horario[0] << ":" << (horario[1] < 10 ? "0" : "") << horario[1]
        << " - "
        << horario[2] << ":" << (horario[3] < 10 ? "0" : "") << horario[3];
    return ss.str();
}

//------------------Metodos propios------------------

string SesionGrupal::toString() {
    stringstream ss;
    ss << "Sesion " << codigo << " - " << nombre << "\n"
        << "Salon: " << salon << "\n"
        << "Horario: " << get_Horario() << "\n"
        << "Instructor: " << (instructor ? instructor->get_Nombre() : "N/A") << "\n"
        << "Cupo Maximo: " << cupoMax << "\n"
        << "Clientes inscritos: \n" << mostrar_ClientesInscritos();
    return ss.str();
}

bool SesionGrupal::inscribir_Cliente(Cliente& c) {
    for (int i = 0; i < cupoMax; i++) {
        if (clientesInscritos[i] == nullptr) {
            clientesInscritos[i] = &c;
            return true;
        }
    }
    return false; 
}

bool SesionGrupal::eliminar_Cliente(string idCliente) {
    for (int i = 0; i < cupoMax; i++) {
        if (clientesInscritos[i] != nullptr &&
            clientesInscritos[i]->get_Cedula() == idCliente) {
            clientesInscritos[i] = nullptr;
            return true;
        }
    }
    return false; 
}

string SesionGrupal::mostrar_ClientesInscritos() {
    stringstream ss;
    for (int i = 0; i < cupoMax; i++) {
        if (clientesInscritos[i] != nullptr) {
            ss << "- " << clientesInscritos[i]->datos_CLiente() << "\n";
        }
    }
    return ss.str();
}

//------------------Destructor------------------

SesionGrupal::~SesionGrupal() {
    delete[] clientesInscritos;
}
