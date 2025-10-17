#ifndef SIMULADOR2D_H
#define SIMULADOR2D_H

#include <iostream>

// Plantilla para crear un simulador genérico en 2D
template <typename T>
class Simulador2D {
private:
    // Puntero doble para crear la matriz (cuadrícula)
    T **_grid;
    int _filas;
    int _columnas;

    // Vector dinámico para las fuentes
    T *_fuentes;
    int _numFuentes;
    int _capacidadFuentes;

    // Arreglo estático con constantes del simulador
    float _constantes[3]; // [0]=Difusión, [1]=DeltaX, [2]=DeltaT

public:
    // Constructor: inicializa la cuadrícula y las variables
    Simulador2D(int f, int c) {
        _filas = f;
        _columnas = c;

        // Creo la matriz dinámica
        _grid = new T *[_filas];
        for (int i = 0; i < _filas; i++) {
            _grid[i] = new T[_columnas];
            for (int j = 0; j < _columnas; j++) {
                _grid[i][j] = 0; // Relleno con ceros
            }
        }

        // Inicializo el vector de fuentes
        _capacidadFuentes = 2;
        _numFuentes = 0;
        _fuentes = new T[_capacidadFuentes];

        // Constantes por defecto
        _constantes[0] = 0.1f; // Difusión
        _constantes[1] = 1.0f; // DeltaX
        _constantes[2] = 0.1f; // DeltaT
    }

    // Destructor: libera la memoria usada
    ~Simulador2D() {
        for (int i = 0; i < _filas; i++) {
            delete[] _grid[i];
        }
        delete[] _grid;
        delete[] _fuentes;
    }

    // Permite cambiar el tamaño de la cuadrícula
    void redimensionarGrid(int nuevaF, int nuevaC) {
        // Libero la cuadrícula vieja
        for (int i = 0; i < _filas; i++) {
            delete[] _grid[i];
        }
        delete[] _grid;

        // Creo una nueva cuadrícula
        _filas = nuevaF;
        _columnas = nuevaC;
        _grid = new T *[_filas];
        for (int i = 0; i < _filas; i++) {
            _grid[i] = new T[_columnas];
            for (int j = 0; j < _columnas; j++) {
                _grid[i][j] = 0; // Reinicio los valores
            }
        }

        std::cout << "La cuadrícula fue redimensionada a " 
                  << _filas << "x" << _columnas << "\n";
    }

    // Agrega una nueva fuente al vector
    void agregarFuente(T valor) {
        // Si se llena, duplico el espacio
        if (_numFuentes == _capacidadFuentes) {
            _capacidadFuentes *= 2;
            T *nuevaLista = new T[_capacidadFuentes];
            for (int i = 0; i < _numFuentes; i++) {
                nuevaLista[i] = _fuentes[i];
            }
            delete[] _fuentes;
            _fuentes = nuevaLista;
        }

        _fuentes[_numFuentes++] = valor;
        std::cout << "Fuente agregada: " << valor << "\n";
    }

    // Simula un paso del sistema (solo imprime por ahora)
    void simularPaso() {
        std::cout << "Simulando un paso con " << _numFuentes 
                  << " fuentes...\n";
        // Aquí iría el algoritmo real (por ejemplo, difusión)
    }
};

#endif
