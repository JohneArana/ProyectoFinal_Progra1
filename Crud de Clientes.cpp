#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cliente {
    int idCliente;
    string nombres;
    string apellidos;
    string NIT;
    string genero; // M o F
    string telefono;
    string correoElectronico;
    string fechaIngreso; // Formato YYYY-MM-DD
};
vector<Cliente> clientes;

void crearCliente() {
    Cliente c;
    cout << "ID Cliente: "; cin >> c.idCliente;
    cin.ignore();
    cout << "Nombres: "; getline(cin, c.nombres);
    cout << "Apellidos: "; getline(cin, c.apellidos);
    cout << "NIT: "; getline(cin, c.NIT);
    cout << "Género (M/F): "; getline(cin, c.genero);
    cout << "Teléfono: "; getline(cin, c.telefono);
    cout << "Correo electrónico: "; getline(cin, c.correoElectronico);
    cout << "Fecha de ingreso (YYYY-MM-DD): "; getline(cin, c.fechaIngreso);
    
    clientes.push_back(c);
    cout << "Cliente agregado correctamente.\n";
}

void leerClientes() {
    if (clientes.empty()) {
        cout << "No hay clientes registrados.\n";
        return;
    }

    for (const auto& c : clientes) {
        cout << "ID Cliente: " << c.idCliente << "\n";
        cout << "Nombres: " << c.nombres << "\n";
        cout << "Apellidos: " << c.apellidos << "\n";
        cout << "NIT: " << c.NIT << "\n";
        cout << "Género: " << c.genero << "\n";
        cout << "Teléfono: " << c.telefono << "\n";
        cout << "Correo electrónico: " << c.correoElectronico << "\n";
        cout << "Fecha de ingreso: " << c.fechaIngreso << "\n";
        cout << "-------------------------------\n";
    }
}

void actualizarCliente() {
    int id;
    cout << "Ingrese el ID del cliente a actualizar: ";
    cin >> id;

    for (auto& c : clientes) {
        if (c.idCliente == id) {
            cin.ignore();
            cout << "Nuevos nombres: "; getline(cin, c.nombres);
            cout << "Nuevos apellidos: "; getline(cin, c.apellidos);
            cout << "Nuevo NIT: "; getline(cin, c.NIT);
            cout << "Nuevo género: "; getline(cin, c.genero);
            cout << "Nuevo teléfono: "; getline(cin, c.telefono);
            cout << "Nuevo correo electrónico: "; getline(cin, c.correoElectronico);
            cout << "Nueva fecha de ingreso: "; getline(cin, c.fechaIngreso);

            cout << "Cliente actualizado correctamente.\n";
            return;
        }
    }

    cout << "Cliente no encontrado.\n";
}

void eliminarCliente() {
    int id;
    cout << "Ingrese el ID del cliente a eliminar: ";
    cin >> id;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->idCliente == id) {
            clientes.erase(it);
            cout << "Cliente eliminado correctamente.\n";
            return;
        }
    }

    cout << "Cliente no encontrado.\n";
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU CRUD CLIENTES ---\n";
        cout << "1. Crear cliente\n";
        cout << "2. Ver clientes\n";
        cout << "3. Actualizar cliente\n";
        cout << "4. Eliminar cliente\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearCliente(); break;
            case 2: leerClientes(); break;
            case 3: actualizarCliente(); break;
            case 4: eliminarCliente(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}

