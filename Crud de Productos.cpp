#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    int idProducto;
    string producto;
    int idMarca;
    string descripcion;
    string imagen; // Ruta o nombre de la imagen
    double precioCosto;
    double precioVenta;
    int existencia;
    string fechaIngreso;
};

vector<Producto> productos;

void crearProducto() {
    Producto p;
    cout << "ID Producto: "; cin >> p.idProducto;
    cin.ignore(); // Limpiar buffer
    cout << "Nombre del producto: "; getline(cin, p.producto);
    cout << "ID Marca: "; cin >> p.idMarca;
    cin.ignore();
    cout << "Descripción: "; getline(cin, p.descripcion);
    cout << "Ruta/nombre de la imagen: "; getline(cin, p.imagen);
    cout << "Precio de costo: "; cin >> p.precioCosto;
    cout << "Precio de venta: "; cin >> p.precioVenta;
    cout << "Existencia: "; cin >> p.existencia;
    cin.ignore();
    cout << "Fecha de ingreso (YYYY-MM-DD): "; getline(cin, p.fechaIngreso);
    
    productos.push_back(p);
    cout << "Producto agregado correctamente.\n";
}

void leerProductos() {
    if (productos.empty()) {
        cout << "No hay productos registrados.\n";
        return;
    }

    for (const auto& p : productos) {
        cout << "ID: " << p.idProducto << "\n";
        cout << "Producto: " << p.producto << "\n";
        cout << "ID Marca: " << p.idMarca << "\n";
        cout << "Descripción: " << p.descripcion << "\n";
        cout << "Imagen: " << p.imagen << "\n";
        cout << "Precio Costo: " << p.precioCosto << "\n";
        cout << "Precio Venta: " << p.precioVenta << "\n";
        cout << "Existencia: " << p.existencia << "\n";
        cout << "Fecha Ingreso: " << p.fechaIngreso << "\n";
        cout << "-------------------------------\n";
    }
}

void actualizarProducto() {
    int id;
    cout << "Ingrese el ID del producto a actualizar: ";
    cin >> id;

    for (auto& p : productos) {
        if (p.idProducto == id) {
            cin.ignore();
            cout << "Nuevo nombre del producto: "; getline(cin, p.producto);
            cout << "Nuevo ID Marca: "; cin >> p.idMarca;
            cin.ignore();
            cout << "Nueva descripción: "; getline(cin, p.descripcion);
            cout << "Nueva imagen: "; getline(cin, p.imagen);
            cout << "Nuevo precio costo: "; cin >> p.precioCosto;
            cout << "Nuevo precio venta: "; cin >> p.precioVenta;
            cout << "Nueva existencia: "; cin >> p.existencia;
            cin.ignore();
            cout << "Nueva fecha ingreso: "; getline(cin, p.fechaIngreso);

            cout << "Producto actualizado correctamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void eliminarProducto() {
    int id;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> id;

    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->idProducto == id) {
            productos.erase(it);
            cout << "Producto eliminado correctamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU CRUD PRODUCTOS ---\n";
        cout << "1. Crear producto\n";
        cout << "2. Ver productos\n";
        cout << "3. Actualizar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearProducto(); break;
            case 2: leerProductos(); break;
            case 3: actualizarProducto(); break;
            case 4: eliminarProducto(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}

