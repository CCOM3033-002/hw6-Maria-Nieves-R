/*
Asignacion 6: Figuras en 3D
Nombre: Maria A. Nieves Rivera
Num. Est: 801-19-5581
Colaboraciones:
- I. Gonzalez Albino
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Definir pi como una constante
const double Pi = 3.14;

// Funciones para calcular el volumen para las siguientes figuras:

// Cilindro
double volumen(double radio, double altura) { 
    return Pi * radio * radio * altura; 
}

// Esfera
double volumen(double radio) { 
    return (4.0 / 3.0) * Pi * radio * radio * radio;
}

// Prisma rectangular
double volumen(double largo, double ancho, double altura) { 
    return largo * ancho * altura;
}

// Funciones para calcular el area de la superficie de las siguientes figuras:

// Cilindro
double areaSuperficie(double radio, double altura) { 
    return 2 * Pi * radio * (radio + altura);
}

// Esfera
double areaSuperficie(double radio) { 
    return 4 * Pi * radio * radio;
}

// Prisma rectangular
double areaSuperficie(double largo, double ancho, double altura) { 
    return 2 * (largo * ancho + largo * altura + ancho * altura);
}

// Funcion de validacion de numero de entrada
double inputVal(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor; 
        if (cin.fail() || valor <= 0) { // Verifica si la entrada es valida
            cin.clear(); // Limpia error de cin
            cin.ignore(10000, '\n'); // Limpia bufer de entrada
            cout << "Entrada invalida. Entre un numero positivo.\n";
        }
    } while (valor <= 0);
    return valor; // Se repite hasta que la entrada sea una valida
}

int main() {
    // Variables 
    char figura, calculo;

    cout << "Este programa calcula el volumen y el area de la superficie de tres figuras geometricas.\n";

    // Opciones de figuras para el usuario escoger 
    cout << "Escoga una figura:\n";
    cout << "  a. Cilindro\n  b. Esfera\n  c. Prisma rectangular\nSeleccion: ";
    cin >> figura;

    // Validacion de entrada
    if (figura != 'a' && figura != 'b' && figura != 'c') {
        cout << "Seleccion invalida. Programa terminado.\n";
        return 1;
    } // Si el usuario ingresa algo fuera de las opciones, finaliza el programa

    // Opciones de calculo de figura escogida
    cout << "\nEscoga entre las siguientes opciones:\n";
    cout << "  a. Volumen\n  b. Area de la superficie\nSeleccion: ";
    cin >> calculo;

    // Validacion de entrada                                    
    if (calculo != 'a' && calculo != 'b') {
        cout << "Seleccion invalida. Programa terminado.\n";
        return 1;
    }

    // Calculo segun la figura seleccionada
    switch (figura) { // Selecciona la figura escogida y hace el calculo correspondiente

        // Para cilindro
        case 'a': { 
            // Variables de dimensiones de cilindro
            double radio = inputVal("\nIngrese el radio del cilindro: "); // Usuario ingresa valores y se valida
            double altura = inputVal("Ingrese la altura del cilindro: ");
            if (calculo == 'a') { // Para el volumen
                cout << "El volumen del cilindro es " << fixed << setprecision(2) << volumen(radio, altura) << "\n"; // Ajustado a dos espacios decimales
            } else { // Para area de superficie
                cout << "El area de la superficie del cilindro es " << fixed << setprecision(2) << areaSuperficie(radio, altura) << "\n";
            }
            break;
        }

        // Para esfera
        case 'b': { 
            double radio = inputVal("\nIngrese el radio de la esfera: ");
            if (calculo == 'a') {
                cout << "El volumen de la esfera es " << fixed << setprecision(2) << volumen(radio) << "\n";
            } else {
                cout << "El area de la superficie de la esfera es " << fixed << setprecision(2) << areaSuperficie(radio) << "\n";
            }
            break;
        }

        // Para prisma rectangular
        case 'c': { 
            double largo = inputVal("\nIngrese el largo del prisma: ");
            double ancho = inputVal("Ingrese el ancho del prisma: ");
            double altura = inputVal("Ingrese la altura del prisma: ");
            if (calculo == 'a') {
                cout << "El volumen del prisma rectangular es " << fixed << setprecision(2) << volumen(largo, ancho, altura) << "\n";
            } else {
                cout << "El area de la superficie del prisma rectangular es " << fixed << setprecision(2) << areaSuperficie(largo, ancho, altura) << "\n";
            }
            break;
        }
    }
    return 0;
}

