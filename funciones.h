#ifndef INTEGRADOR_H_INCLUDED
#define INTEGRADOR_H_INCLUDED
#include <iostream>

using namespace std;
struct Jugador
{
    string nombre;
    int carta = 0;
    int puntos = 0;
    int puntosTiempo = 0;
    int bugs = 0;
    int lanzamientos = 1;
    bool turno = true;
    int lanzamientosRondaActual = 1;
    int puntosRondaActual = 0;
    string dadoUno;
    string dadoDos;
    string dadoTres;
};
struct Jugador2
{
    string nombre;
    int carta = 0;
    int puntos = 0;
    int puntosTiempo = 0;
    int bugs = 0;
    int lanzamientos = 1;
    bool turno = true;
    int lanzamientosRondaActual = 1;
    int puntosRondaActual = 0;
};

void registrarJugadores(Jugador &jugador1, Jugador &jugador2);
void tomarCarta(Jugador &jugador);
void turnoJugador(Jugador &jugador);
void mostrarEstadoJugadores(const Jugador &j1, const Jugador &j2);
void turnoJugador(Jugador2 &jugador2);
void mostrarDados(int dado);
#endif