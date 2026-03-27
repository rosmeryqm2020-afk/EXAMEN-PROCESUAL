// el sistema de turnos - Examen Estructuras de Datos
//Mejoras al codigo
#include <iostream>
using namespace std;

// Nodo de la lista
struct Nodo {
    string nombre;
    int codigo;
    Nodo* siguiente;
};

// Punteros de la cola
Nodo* frente = NULL;
Nodo* final = NULL;

// 1. Registrar estudiante
void registrar() {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;

    cout << "Ingrese codigo: ";
    cin >> nuevo->codigo;

    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }

    cout << "Estudiante registrado correctamente\n";
}

// 2. Atender estudiante
void atender() {
    if (frente == NULL) {
        cout << "No hay estudiantes en espera\n";
        return;
    }

    Nodo* temp = frente;

    cout << "Atendiendo a: " << temp->nombre << " Codigo: " << temp->codigo << endl;

    frente = frente->siguiente;
    delete temp;

    if (frente == NULL) {
        final = NULL;
    }
}

// 3. Mostrar estudiantes
void mostrar() {
    if (frente == NULL) {
        cout << "No hay estudiantes en espera\n";
        return;
    }

    Nodo* aux = frente;
    int pos = 1;

    cout << "Lista de estudiantes:\n";

    while (aux != NULL) {
        cout << pos << ". " << aux->nombre << " - " << aux->codigo << endl;
        aux = aux->siguiente;
        pos++;
    }
}

// 4. Buscar estudiante
void buscar() {
    if (frente == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    string nombreBuscar;
    cout << "Ingrese nombre a buscar: ";
    cin >> nombreBuscar;

    Nodo* aux = frente;
    int pos = 1;
    bool encontrado = false;

    while (aux != NULL) {
        if (aux->nombre == nombreBuscar) {
            cout << "Encontrado en posicion: " << pos << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
        pos++;
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado\n";
    }
}

// MAIN
int main() {
    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Atender estudiante\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrar(); break;
            case 2: atender(); break;
            case 3: mostrar(); break;
            case 4: buscar(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }

    } while (opcion != 5);

    return 0;
}
