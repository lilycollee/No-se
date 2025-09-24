#include "ContenedorInstructores.h"

ContenedorInstructores::ContenedorInstructores(int cap) : tamano(cap), cant(0) {
    nuevoInstructor = new Instructor * [tamano];
}

void ContenedorInstructores::agregarInstructor(Instructor* inst) {
    if (cant < tamano) {
        nuevoInstructor[cant++] = inst;
    }
    else {
        cout << "Contenedor lleno\n";
    }
}

void ContenedorInstructores::mostrarInstructores() {
    for (int i = 0; i < cant; i++) {
        nuevoInstructor[i]->tostring();
    }
}

ContenedorInstructores::~ContenedorInstructores() {
    for (int i = 0; i < cant; i++) {
        delete nuevoInstructor[i];
    }
    delete[] nuevoInstructor;
}
