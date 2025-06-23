#include "../headers/funciones.h"

void registrarJugadores(Jugador &jugador1, Jugador &jugador2)
{
    std::string respuesta;
    do
    {
        system("clear");
        cout << "TREY\n--------------------------------------------------------\n";
        cout << "Antes de comenzar deben registrar sus nombres:\n";
        cout << "Ingrese el nombre del jugador numero 1: ";
        cin >> jugador1.nombre;
        cout << "Ingrese el nombre del jugador numero 2: ";
        cin >> jugador2.nombre;
        cout << " ¿Confirmar nombres? (S/N): ";
        cin >> respuesta;
        cout << endl;
    } while (respuesta == "N" || respuesta == "n");
}

void tomarCarta(Jugador &jugador)
{
    int carta = rand() % 15 + 50;
    int valor;

    if (carta < 56)
    {
        valor = 7;
    }
    else if (carta < 61)
    {

        valor = 8;
    }
    else
    {

        valor = 9;
    }

    jugador.carta = carta;
    jugador.puntosTiempo = valor;

    cout << "El jugador " << jugador.nombre << " ha tomado la carta: " << jugador.carta << endl;
    cout << "Los puntos de tiempo que le han tocado son: " << jugador.puntosTiempo << endl;

    cin.get();
}

void mostrarDados(int dado)
{

    switch (dado)
    {
    case 1:
        std::cout << "+-------+\n"
                     "|       |\n"
                     "|   X   |\n"
                     "|       |\n"
                     "+-------+\n";
        break;

    case 2:
        std::cout << "+-------+\n"
                     "| X     |\n"
                     "|       |\n"
                     "|     X |\n"
                     "+-------+\n";
        break;

    case 3:
        std::cout << "+-------+\n"
                     "| X     |\n"
                     "|   X   |\n"
                     "|     X |\n"
                     "+-------+\n";
        break;

    case 4:
        std::cout << "+-------+\n"
                     "| X   X |\n"
                     "|       |\n"
                     "| X   X |\n"
                     "+-------+\n";
        break;

    case 5:
        std::cout << "+-------+\n"
                     "| X   X |\n"
                     "|   X   |\n"
                     "| X   X |\n"
                     "+-------+\n";
        break;

    case 6:
        std::cout << "+-------+\n"
                     "| X   X |\n"
                     "| X   X |\n"
                     "| X   X |\n"
                     "+-------+\n";
        break;
    }
}
void turnoJugador(Jugador &jugador)
{
    bool continuar = true;
    char respuesta;
    int cantidadDados;
    int dado[3], suma;

    jugador.lanzamientosRondaActual = 1;

    while (jugador.puntosTiempo > 0 && continuar && jugador.turno == true)
    {
        int ronda = 1;
        int contBugs = 0;
        int contFix = 0;

        if (jugador.puntosTiempo > 2 && continuar)
        {

            do
            {
                system("clear");

                cout << "TREY" << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << "Turno de " << jugador.nombre << "                  " << jugador.puntosTiempo << " PT" << endl;
                cout << " ¿Con cuantos dados desea lanzar?";
                cout << endl;
                cout << "2 dados - Costo 1 PT" << endl;
                cout << "3 dados - Costo 2 PT" << endl;

                cin >> cantidadDados;

                cout << "-----------------------------------------------------------" << endl;
                if (cantidadDados == 2)
                {
                    jugador.puntosTiempo--;
                    break;
                }
                else if (cantidadDados == 3)
                {
                    jugador.puntosTiempo -= 2;
                    break;
                }
                else
                {
                    cout << "Opcion invalida. Pulse enter para ingresar nuevamente" << endl;
                    cin.get();
                    cin.get();
                }

            } while (cantidadDados != 2 || cantidadDados != 3);
        }
        else
        {
            cantidadDados = 2;
            jugador.puntosTiempo--;
        }

        system("clear");
        cout << "TREY" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << jugador.nombre << endl;
        cout << "PT: " << jugador.puntosTiempo << "/" << "BUGS: " << jugador.bugs << endl;
        cout << endl;
        cout << "TURNO DE " << jugador.nombre << endl;
        cout << "+---------------------------------+\n";
        cout << "| RONDA #" << ronda << "------------------------|" << endl;
        cout << "| PUNTOS DE LA RONDA: " << jugador.puntosRondaActual << "----------|" << endl;
        cout << "| LANZAMIENTOS: #" << jugador.lanzamientos << "----------------|" << endl;
        cout << "+---------------------------------+\n";
        cout << endl;
        cout << "LANZAMIENTO # " << jugador.lanzamientosRondaActual << endl;

        // Lanzamiento de dados
        dado[0] = rand() % 6 + 1;
        dado[1] = rand() % 6 + 1;
        dado[2] = rand() % 6 + 1;

        // Acumulador de Bugs y Fixes
        if (cantidadDados == 2)
        {
            mostrarDados(dado[0]);
            mostrarDados(dado[1]);
            suma = dado[0] + dado[1];
            jugador.puntosRondaActual += suma;
            for (int x = 0; x < 2; x++)
            {
                if (dado[x] == 1)
                {
                    contBugs++;
                }
                else if (dado[x] == 3)
                {
                    contFix++;
                    contBugs--;
                }
            }
        }
        else

        // Asignacion de dados
        {
            mostrarDados(dado[0]);
            mostrarDados(dado[1]);
            mostrarDados(dado[2]);

            suma = dado[0] + dado[1] + dado[2];
            jugador.puntosRondaActual = suma;
            for (int x = 0; x < 3; x++)
            {
                if (dado[x] == 1)
                {
                    contBugs++;
                }
                else if (dado[x] == 3)
                {
                    contFix++;
                }
            }
        }

        // Verificiación de Bugs

        if (contBugs == 3)
        {
            jugador.puntosTiempo -= 2;
            jugador.bugs = jugador.bugs += 3;
            cout << "OBTUVISTE:  " << contBugs << " BUGS, PERDES EL TURNO Y PERDES DOS PUNTOS DE TIEMPO" << endl;
            jugador.turno = false;
        }
        else if (contBugs == 2)
        {
            jugador.puntosTiempo -= 1;
            jugador.bugs -= 2;
            cout << "OBTUVISTE:  " << contBugs << " BUGS, PERDES EL TURNO Y PERDES 1 PUNTO DE TIEMPO" << endl;
            jugador.turno = false;
        }
        else if (contBugs == 1)
        {
            jugador.bugs++;
            cout << "OBTUVISTE:  " << contBugs << " BUG, PERDES EL TURNO " << endl;
            jugador.turno = false;
        }

        // Verificación de Fixes

        if (contFix == 3)
        {
            cout << "¡Sumaste " << suma << " puntos!" << endl;
            cout << "Salieron " << contFix << "FIXES. ";

            if (jugador.bugs >= 3)
            {
                cout << "Se restan 3 BUGS." << endl;
                jugador.bugs -= 3;
            }
            else
            {
                jugador.bugs = 0;
            }

            jugador.puntosTiempo += 2;
        }
        if (contFix == 2)
        {
            if (contBugs < 1)
            {
                cout << "¡Sumaste " << suma << " puntos!" << endl;
            }
            cout << "Salieron " << contFix << "FIXES.";
            if (jugador.bugs >= 2)
            {
                cout << " Se restan 2 BUGS." << endl;
                jugador.bugs -= 2;
            }
            else
            {
                jugador.bugs = 0;
            }

            jugador.puntosTiempo += 1;
        }
        if (contFix == 1)
        {
            if (contBugs == 0)
            {
                cout << "¡Sumaste " << suma << " puntos!" << endl;
            }
            cout << "Salió " << contFix << "FIX. ";
            if (jugador.bugs >= 1)
            {
                cout << "Se resta 1 BUG." << endl;
                jugador.bugs -= 1;
            }

            else
            {
                jugador.bugs = 0;
            }
        }
        if (contBugs == 0 && contFix == 0)
        {

            cout << "¡Sumaste " << suma << " puntos!" << endl;
        }

        // Si no hay ningun bug

        if (contBugs == 0)
        {

            jugador.puntos += jugador.puntosRondaActual;

            // Pregunta para continuar jugando
            do
            {
                cout << "\n¿Desea continuar lanzando? (S/N): ";
                cin >> respuesta;

                if (respuesta == 'N' || respuesta == 'n')
                {
                    continuar = false;
                    break;
                }
                else if (respuesta == 'S' || respuesta == 's')
                {
                    break;
                }

                cout << "Respuesta Invalida" << endl;

            } while (respuesta != 'S' && respuesta != 's' &&
                     respuesta != 'N' && respuesta != 'n');
        }
        jugador.lanzamientos++;
        jugador.lanzamientosRondaActual++;
        ronda++;
        if (jugador.puntosTiempo == 0)
        {
            jugador.turno = false;
        }

        cout << "\nPulsa ENTER para continuar...";
        cin.get();
        cin.get();
    }
}

void mostrarEstadoJugadores(const Jugador &j1, const Jugador &j2)
{
    cout << j1.nombre << ": " << j1.puntos << " puntos " << "de  " << j1.carta << "| PT: " << j1.puntosTiempo << " | BUGS: " << j1.bugs << endl;
    cout << j2.nombre << ": " << j2.puntos << " puntos " << "de  " << j2.carta << "| PT: " << j2.puntosTiempo << " | BUGS: " << j2.bugs << endl;
}
