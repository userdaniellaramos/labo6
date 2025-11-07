#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    string direccion;
    double calificaciones[5]; // maximo 5 calificaciones
    int cantidadCalificaciones;
};

// Funcion para mostrar el menu
void mostrarMenu() {
    cout << "\n--- Menu principal ---" << endl;
    cout << "1. Ingresar estudiante" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Buscar estudiante" << endl;
    cout << "4. Modificar estudiante" << endl;
    cout << "5. Salir" << endl;
}

void ingresarEstudiante(Estudiante estudiantes[], int &total) {
    if (total >= 50) {
        cout << "Limite de estudiantes alcanzado.\n";
        return;
    }
    cin.ignore();
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, estudiantes[total].nombre);
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiantes[total].edad;
    cin.ignore();
    cout << "Ingrese la direccion del estudiante: ";
    getline(cin, estudiantes[total].direccion);

    cout << "Cuantas calificaciones desea ingresar (maximo 5)? ";
    cin >> estudiantes[total].cantidadCalificaciones;
    if (estudiantes[total].cantidadCalificaciones > 5)
        estudiantes[total].cantidadCalificaciones = 5;

    for (int i = 0; i < estudiantes[total].cantidadCalificaciones; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> estudiantes[total].calificaciones[i];
    }

    total++;
    cout << "Estudiante agregado correctamente.\n";
}

void mostrarEstudiantes(Estudiante estudiantes[], int total) {
    if (total == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << "\nNombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Direccion: " << estudiantes[i].direccion << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < estudiantes[i].cantidadCalificaciones; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << endl;
    }
}

void buscarEstudiante(Estudiante estudiantes[], int total) {
    if (total == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    cin.ignore();
    string nombre;
    cout << "Ingrese el nombre del estudiante a buscar: ";
    getline(cin, nombre);
    for (int i = 0; i < total; i++) {
        if (estudiantes[i].nombre == nombre) {
            cout << "\nNombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Direccion: " << estudiantes[i].direccion << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < estudiantes[i].cantidadCalificaciones; j++) {
                cout << estudiantes[i].calificaciones[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Estudiante no encontrado.\n";
}

void modificarEstudiante(Estudiante estudiantes[], int total) {
    if (total == 0) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    cin.ignore();
    string nombre;
    cout << "Ingrese el nombre del estudiante a modificar: ";
    getline(cin, nombre);
    for (int i = 0; i < total; i++) {
        if (estudiantes[i].nombre == nombre) {
            cout << "Ingrese la nueva edad: ";
            cin >> estudiantes[i].edad;
            cin.ignore();
            cout << "Ingrese la nueva direccion: ";
            getline(cin, estudiantes[i].direccion);

            cout << "Cuantas calificaciones desea ingresar (maximo 5)? ";
            cin >> estudiantes[i].cantidadCalificaciones;
            if (estudiantes[i].cantidadCalificaciones > 5)
                estudiantes[i].cantidadCalificaciones = 5;

            for (int j = 0; j < estudiantes[i].cantidadCalificaciones; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << "Estudiante modificado con exito.\n";
            return;
        }
    }
    cout << "Estudiante no encontrado.\n";
}

int main() {
    Estudiante estudiantes[50];
    int total = 0;
    int opcion;
    do {
        mostrarMenu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: ingresarEstudiante(estudiantes, total); break;
            case 2: mostrarEstudiantes(estudiantes, total); break;
            case 3: buscarEstudiante(estudiantes, total); break;
            case 4: modificarEstudiante(estudiantes, total); break;
            case 5: cout << "Adios.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);
    return 0;
}
