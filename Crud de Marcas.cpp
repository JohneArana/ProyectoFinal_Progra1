#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Marca {
    int idMarca;
    string marca;
};
vector<Marca> marcas;

void crearMarca() {
    Marca m;
    cout << "ID Marca: "; cin >> m.idMarca;
    cin.ignore();
    cout << "Nombre de la marca: "; getline(cin, m.marca);

    marcas.push_back(m);
    cout << "Marca agregada correctamente.\n";
}

void leerMarcas() {
    if (marcas.empty()) {
        cout << "No hay marcas registradas.\n";
        return;
    }

    for (const auto& m : marcas) {
        cout << "ID Marca: " << m.idMarca << "\n";
        cout << "Nombre: " << m.marca << "\n";
        cout << "--------------------------\n";
    }
}

void actualizarMarca() {
    int id;
    cout << "Ingrese el ID de la marca a actualizar: ";
    cin >> id;

    for (auto& m : marcas) {
        if (m.idMarca == id) {
            cin.ignore();
            cout << "Nuevo nombre de la marca: ";
            getline(cin, m.marca);
            cout << "Marca actualizada correctamente.\n";
            return;
        }
    }

    cout << "Marca no encontrada.\n";
}

void eliminarMarca() {
    int id;
    cout << "Ingrese el ID de la marca a eliminar: ";
    cin >> id;

    for (auto it = marcas.begin(); it != marcas.end(); ++it) {
        if (it->idMarca == id) {
            marcas.erase(it);
            cout << "Marca eliminada correctamente.\n";
            return;
        }
    }

    cout << "Marca no encontrada.\n";
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU CRUD MARCAS ---\n";
        cout << "1. Crear marca\n";
        cout << "2. Ver marcas\n";
        cout << "3. Actualizar marca\n";
        cout << "4. Eliminar marca\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearMarca(); break;
            case 2: leerMarcas(); break;
            case 3: actualizarMarca(); break;
            case 4: eliminarMarca(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}

