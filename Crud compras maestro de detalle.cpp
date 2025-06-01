#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Compra {
    int idCompra;
    string numeroOrdenCompra;
    int idProveedor;
    string fechaOrden;
    string fechaIngreso;
};

struct CompraDetalle {
    int idCompraDetalle;
    int idCompra;
    int idProducto;
    int cantidad;
    double precioCostoUnitario;
};

vector<Compra> compras;
vector<CompraDetalle> detalles;
void crearCompra() {
    Compra c;
    cout << "ID Compra: "; cin >> c.idCompra;
    cin.ignore();
    cout << "Número de orden de compra: "; getline(cin, c.numeroOrdenCompra);
    cout << "ID Proveedor: "; cin >> c.idProveedor;
    cin.ignore();
    cout << "Fecha de orden (YYYY-MM-DD): "; getline(cin, c.fechaOrden);
    cout << "Fecha de ingreso (YYYY-MM-DD): "; getline(cin, c.fechaIngreso);

    compras.push_back(c);
    cout << "Compra registrada correctamente.\n";
}

void leerCompras() {
    if (compras.empty()) {
        cout << "No hay compras registradas.\n";
        return;
    }

    for (const auto& c : compras) {
        cout << "\nID Compra: " << c.idCompra;
        cout << "\nOrden #: " << c.numeroOrdenCompra;
        cout << "\nID Proveedor: " << c.idProveedor;
        cout << "\nFecha Orden: " << c.fechaOrden;
        cout << "\nFecha Ingreso: " << c.fechaIngreso;
        cout << "\n---------------------------\n";
    }
}

void actualizarCompra() {
    int id;
    cout << "Ingrese el ID de la compra a actualizar: ";
    cin >> id;

    for (auto& c : compras) {
        if (c.idCompra == id) {
            cin.ignore();
            cout << "Nuevo número de orden de compra: "; getline(cin, c.numeroOrdenCompra);
            cout << "Nuevo ID proveedor: "; cin >> c.idProveedor;
            cin.ignore();
            cout << "Nueva fecha de orden: "; getline(cin, c.fechaOrden);
            cout << "Nueva fecha de ingreso: "; getline(cin, c.fechaIngreso);
            cout << "Compra actualizada correctamente.\n";
            return;
        }
    }

    cout << "Compra no encontrada.\n";
}

void eliminarCompra() {
    int id;
    cout << "Ingrese el ID de la compra a eliminar: ";
    cin >> id;

    for (auto it = compras.begin(); it != compras.end(); ++it) {
        if (it->idCompra == id) {
            compras.erase(it);
            cout << "Compra eliminada correctamente.\n";
            return;
        }
    }

    cout << "Compra no encontrada.\n";
}
void crearCompraDetalle() {
    CompraDetalle d;
    cout << "ID Detalle: "; cin >> d.idCompraDetalle;
    cout << "ID Compra: "; cin >> d.idCompra;
    cout << "ID Producto: "; cin >> d.idProducto;
    cout << "Cantidad: "; cin >> d.cantidad;
    cout << "Precio costo unitario: "; cin >> d.precioCostoUnitario;

    detalles.push_back(d);
    cout << "Detalle de compra agregado correctamente.\n";
}

void leerCompraDetalles() {
    if (detalles.empty()) {
        cout << "No hay detalles registrados.\n";
        return;
    }

    for (const auto& d : detalles) {
        cout << "\nID Detalle: " << d.idCompraDetalle;
        cout << "\nID Compra: " << d.idCompra;
        cout << "\nID Producto: " << d.idProducto;
        cout << "\nCantidad: " << d.cantidad;
        cout << "\nPrecio costo unitario: " << d.precioCostoUnitario;
        cout << "\n---------------------------\n";
    }
}

void actualizarCompraDetalle() {
    int id;
    cout << "Ingrese el ID del detalle a actualizar: ";
    cin >> id;

    for (auto& d : detalles) {
        if (d.idCompraDetalle == id) {
            cout << "Nuevo ID Compra: "; cin >> d.idCompra;
            cout << "Nuevo ID Producto: "; cin >> d.idProducto;
            cout << "Nueva cantidad: "; cin >> d.cantidad;
            cout << "Nuevo precio costo unitario: "; cin >> d.precioCostoUnitario;
            cout << "Detalle actualizado correctamente.\n";
            return;
        }
    }

    cout << "Detalle no encontrado.\n";
}

void eliminarCompraDetalle() {
    int id;
    cout << "Ingrese el ID del detalle a eliminar: ";
    cin >> id;

    for (auto it = detalles.begin(); it != detalles.end(); ++it) {
        if (it->idCompraDetalle == id) {
            detalles.erase(it);
            cout << "Detalle eliminado correctamente.\n";
            return;
        }
    }

    cout << "Detalle no encontrado.\n";
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU COMPRAS Y DETALLE ---\n";
        cout << "1. Crear compra\n";
        cout << "2. Ver compras\n";
        cout << "3. Actualizar compra\n";
        cout << "4. Eliminar compra\n";
        cout << "5. Crear detalle compra\n";
        cout << "6. Ver detalles de compra\n";
        cout << "7. Actualizar detalle compra\n";
        cout << "8. Eliminar detalle compra\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearCompra(); break;
            case 2: leerCompras(); break;
            case 3: actualizarCompra(); break;
            case 4: eliminarCompra(); break;
            case 5: crearCompraDetalle(); break;
            case 6: leerCompraDetalles(); break;
            case 7: actualizarCompraDetalle(); break;
            case 8: eliminarCompraDetalle(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}

