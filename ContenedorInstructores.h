#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Instructor.h"
using namespace std;

class ContenedorInstructores {
private:
    Instructor** nuevoInstructor;
    int tamano;
    int cant;
public:
    ContenedorInstructores(int) {};
    void agregarInstructor(Instructor*) {};
    void mostrarInstructores() {};
    ~ContenedorInstructores() {};
};

