#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Puesto {
    int id;
    string nombre;
};

vector<Puesto> puestos;

// Función para verificar si un ID ya existe
bool existeId(int id) {
    for (const Puesto& p : puestos) {
        if (p.id == id) return true;
    }
    return false;
}

void crearPuesto() {
    Puesto nuevo;
    cout << "Ingrese ID del puesto: ";
    cin >> nuevo.id;

    if (existeId(nuevo.id)) {
        cout << "Error: El ID ya existe.\n";
        return;
    }

    cin.ignore(); // limpiar buffer
    cout << "Ingrese nombre del puesto: ";
    getline(cin, nuevo.nombre);

    puestos.push_back(nuevo);
    cout << "Puesto creado correctamente.\n";
}

void mostrarPuestos() {
    if (puestos.empty()) {
        cout << "No hay puestos registrados.\n";
        return;
    }

    cout << "Lista de puestos:\n";
    for (const Puesto& p : puestos) {
        cout << "ID: " << p.id << " | Puesto: " << p.nombre << "\n";
    }
}

void actualizarPuesto() {
    int id;
    cout << "Ingrese ID del puesto a actualizar: ";
    cin >> id;

    for (Puesto& p : puestos) {
        if (p.id == id) {
            cin.ignore(); // limpiar buffer
            cout << "Ingrese nuevo nombre del puesto: ";
            getline(cin, p.nombre);
            cout << "Puesto actualizado correctamente.\n";
            return;
        }
    }

    cout << "Puesto no encontrado.\n";
}

void eliminarPuesto() {
    int id;
    cout << "Ingrese ID del puesto a eliminar: ";
    cin >> id;

    for (auto it = puestos.begin(); it != puestos.end(); ++it) {
        if (it->id == id) {
            puestos.erase(it);
            cout << "Puesto eliminado correctamente.\n";
            return;
        }
    }

    cout << "Puesto no encontrado.\n";
}

void menu() {
    int opcion;
    do {
        cout << "\n--- MENU PUESTOS ---\n";
        cout << "1. Crear puesto\n";
        cout << "2. Mostrar puestos\n";
        cout << "3. Actualizar puesto\n";
        cout << "4. Eliminar puesto\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearPuesto(); break;
            case 2: mostrarPuestos(); break;
            case 3: actualizarPuesto(); break;
            case 4: eliminarPuesto(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }

    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

