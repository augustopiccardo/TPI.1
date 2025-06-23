#include <iostream>
#include <ctime>
#include "../headers/funciones.h"
#include <clocale>
#include "funciones.cpp"
#include "../headers/funciones.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Jugador jugador1, jugador2;
    int opcion;

    while (true)
    {

        // Mostrar el menú

        system("clear");

        cout << "===== TREY =====" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "--------------------" << endl;
        cout << "0 -  Salir" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            registrarJugadores(jugador1, jugador2);
            system("clear");
            tomarCarta(jugador1);
            tomarCarta(jugador2);
            system("clear");

            cin.get();

            while (jugador1.puntosTiempo != 0 || jugador2.puntosTiempo != 0)
            {
                if (jugador1.turno)
                {
                    turnoJugador(jugador1);
                    jugador2.turno = true;
                }
                else if (jugador2.turno)
                {
                    turnoJugador(jugador2);
                    jugador1.turno = true;
                }
                else
                {
                    cout << "FIN DEL JUEGO" << endl;
                }
            }

            cin.get();

            break;

        case 2:
            system("clear");
            cout << "Has seleccionado la Opción 2." << endl;
            system("pause");
            break;
        case 3:
            system("clear");
            cout << "Has seleccionado la Opción 3." << endl;
            system("pause");
            break;
        case 0:
            return 0;
            break;
        default:
            system("clear");
            cout << "Opción no válida. Intente de nuevo." << endl;
            cin.get();
        }
    }
}
