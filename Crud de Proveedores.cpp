#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Proveedor {
    int idProveedores;
    string proveedor;
    string NIT;
    string direccion;
    string telefono;
};
vector<Proveedor> proveedores;

void crearProveedor() {
    Proveedor p;
    cout << "ID Proveedor: "; cin >> p.idProveedores;
    cin.ignore();
    cout << "Nombre del proveedor: "; getline(cin, p.proveedor);
    cout << "NIT: "; getline(cin, p.NIT);
    cout << "Dirección: "; getline(cin, p.direccion);
    cout << "Teléfono: "; getline(cin, p.telefono);

    proveedores.push_back(p);
    cout << "Proveedor agregado correctamente.\n";
}

void leerProveedores() {
    if (proveedores.empty()) {
        cout << "No hay proveedores registrados.\n";
        return;
    }

    for (const auto& p : proveedores) {
        cout << "ID: " << p.idProveedores << "\n";
        cout << "Proveedor: " << p.proveedor << "\n";
        cout << "NIT: " << p.NIT << "\n";
        cout << "Dirección: " << p.direccion << "\n";
        cout << "Teléfono: " << p.telefono << "\n";
        cout << "-----------------------------\n";
    }
}

void actualizarProveedor() {
    int id;
    cout << "Ingrese el ID del proveedor a actualizar: ";
    cin >> id;

    for (auto& p : proveedores) {
        if (p.idProveedores == id) {
            cin.ignore();
            cout << "Nuevo nombre del proveedor: "; getline(cin, p.proveedor);
            cout << "Nuevo NIT: "; getline(cin, p.NIT);
            cout << "Nueva dirección: "; getline(cin, p.direccion);
            cout << "Nuevo teléfono: "; getline(cin, p.telefono);
            cout << "Proveedor actualizado correctamente.\n";
            return;
        }
    }

    cout << "Proveedor no encontrado.\n";
}

void eliminarProveedor() {
    int id;
    cout << "Ingrese el ID del proveedor a eliminar: ";
    cin >> id;

    for (auto it = proveedores.begin(); it != proveedores.end(); ++it) {
        if (it->idProveedores == id) {
            proveedores.erase(it);
            cout << "Proveedor eliminado correctamente.\n";
            return;
        }
    }

    cout << "Proveedor no encontrado.\n";
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU CRUD PROVEEDORES ---\n";
        cout << "1. Crear proveedor\n";
        cout << "2. Ver proveedores\n";
        cout << "3. Actualizar proveedor\n";
        cout << "4. Eliminar proveedor\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearProveedor(); break;
            case 2: leerProveedores(); break;
            case 3: actualizarProveedor(); break;
            case 4: eliminarProveedor(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}

