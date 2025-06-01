#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado {
    int idEmpleado;
    string nombres;
    string apellidos;
    string direccion;
    string telefono;
    string DPI;
    char genero; // 'M' o 'F'
    string fechaNacimiento;
    int idPuesto;
    string fechaInicioLabores;
    string fechaIngreso;
};

vector<Empleado> empleados;

bool existeEmpleado(int id) {
    for (const auto& e : empleados) {
        if (e.idEmpleado == id) return true;
    }
    return false;
}

void crearEmpleado() {
    Empleado e;
    cout << "ID empleado: ";
    cin >> e.idEmpleado;
    if (existeEmpleado(e.idEmpleado)) {
        cout << "Error: El ID ya existe.\n";
        return;
    }
    cin.ignore(); // limpiar buffer
    cout << "Nombres: ";
    getline(cin, e.nombres);
    cout << "Apellidos: ";
    getline(cin, e.apellidos);
    cout << "Direccion: ";
    getline(cin, e.direccion);
    cout << "Telefono: ";
    getline(cin, e.telefono);
    cout << "DPI: ";
    getline(cin, e.DPI);
    cout << "Genero (M/F): ";
    cin >> e.genero;
    cin.ignore();
    cout << "Fecha de nacimiento (YYYY-MM-DD): ";
    getline(cin, e.fechaNacimiento);
    cout << "ID puesto: ";
    cin >> e.idPuesto;
    cin.ignore();
    cout << "Fecha inicio de labores (YYYY-MM-DD): ";
    getline(cin, e.fechaInicioLabores);
    cout << "Fecha de ingreso (YYYY-MM-DD): ";
    getline(cin, e.fechaIngreso);

    empleados.push_back(e);
    cout << "Empleado creado correctamente.\n";
}

void mostrarEmpleados() {
    if (empleados.empty()) {
        cout << "No hay empleados registrados.\n";
        return;
    }
    for (const auto& e : empleados) {
        cout << "\nID: " << e.idEmpleado
             << "\nNombres: " << e.nombres
             << "\nApellidos: " << e.apellidos
             << "\nDireccion: " << e.direccion
             << "\nTelefono: " << e.telefono
             << "\nDPI: " << e.DPI
             << "\nGenero: " << e.genero
             << "\nFecha de nacimiento: " << e.fechaNacimiento
             << "\nID puesto: " << e.idPuesto
             << "\nFecha inicio de labores: " << e.fechaInicioLabores
             << "\nFecha de ingreso: " << e.fechaIngreso << "\n";
    }
}

void actualizarEmpleado() {
    int id;
    cout << "Ingrese ID del empleado a actualizar: ";
    cin >> id;
    cin.ignore();
    for (auto& e : empleados) {
        if (e.idEmpleado == id) {
            cout << "Nuevos nombres: ";
            getline(cin, e.nombres);
            cout << "Nuevos apellidos: ";
            getline(cin, e.apellidos);
            cout << "Nueva direccion: ";
            getline(cin, e.direccion);
            cout << "Nuevo telefono: ";
            getline(cin, e.telefono);
            cout << "Nuevo DPI: ";
            getline(cin, e.DPI);
            cout << "Nuevo genero (M/F): ";
            cin >> e.genero;
            cin.ignore();
            cout << "Nueva fecha de nacimiento (YYYY-MM-DD): ";
            getline(cin, e.fechaNacimiento);
            cout << "Nuevo ID puesto: ";
            cin >> e.idPuesto;
            cin.ignore();
            cout << "Nueva fecha inicio de labores (YYYY-MM-DD): ";
            getline(cin, e.fechaInicioLabores);
            cout << "Nueva fecha de ingreso (YYYY-MM-DD): ";
            getline(cin, e.fechaIngreso);
            cout << "Empleado actualizado correctamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

void eliminarEmpleado() {
    int id;
    cout << "Ingrese ID del empleado a eliminar: ";
    cin >> id;
    for (auto it = empleados.begin(); it != empleados.end(); ++it) {
        if (it->idEmpleado == id) {
            empleados.erase(it);
            cout << "Empleado eliminado correctamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

void menu() {
    int opcion;
    do {
        cout << "\n--- MENU EMPLEADOS ---\n";
        cout << "1. Crear empleado\n";
        cout << "2. Mostrar empleados\n";
        cout << "3. Actualizar empleado\n";
        cout << "4. Eliminar empleado\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: crearEmpleado(); break;
            case 2: mostrarEmpleados(); break;
            case 3: actualizarEmpleado(); break;
            case 4: eliminarEmpleado(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

