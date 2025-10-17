#include <iostream>
#include "Simulador2D.h"

int main() {
    // Creo un simulador de tipo float con una cuadrícula de 3x3
    Simulador2D<float> sim(3, 3);

    // Agrego algunas fuentes (valores iniciales)
    sim.agregarFuente(5.0f);
    sim.agregarFuente(10.0f);

    // Ejecuto un paso de simulación
    sim.simularPaso();

    // Redimensiono la cuadrícula a 4x4
    sim.redimensionarGrid(4, 4);

    return 0; // Fin del programa
}
