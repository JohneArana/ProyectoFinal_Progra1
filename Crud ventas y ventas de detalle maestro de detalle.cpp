#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Venta {
    int idVenta;
    string numeroFactura;
    string serie;
    string fechaFactura;
    int idCliente;
    int idEmpleado;
    string fechaIngreso;
};

struct VentaDetalle {
    int idVentaDetalle;
    int idVenta;
    int idProducto;
    int cantidad;
    double precioUnitario;
};
vector<Venta> ventas;
vector<VentaDetalle> detalles;
void crearVenta() {
    Venta v;
    cout << "ID Venta: "; cin >> v.idVenta;
    cin.ignore();
    cout << "Número de Factura: "; getline(cin, v.numeroFactura);
    cout << "Serie: "; getline(cin, v.serie);
    cout << "Fecha de Factura (YYYY-MM-DD): "; getline(cin, v.fechaFactura);
    cout << "ID Cliente: "; cin >> v.idCliente;
    cout << "ID Empleado: "; cin >> v.idEmpleado;
    cin.ignore();
    cout << "Fecha de Ingreso (YYYY-MM-DD): "; getline(cin, v.fechaIngreso);

    ventas.push_back(v);
    cout << "Venta registrada correctamente.\n";
}

void leerVentas() {
    if (ventas.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    for (const auto& v : ventas) {
        cout << "\nID Venta: " << v.idVenta << "\n";
        cout << "Factura: " << v.numeroFactura << "\n";
        cout << "Serie: " << v.serie << "\n";
        cout << "Fecha Factura: " << v.fechaFactura << "\n";
        cout << "ID Cliente: " << v.idCliente << "\n";
        cout << "ID Empleado: " << v.idEmpleado << "\n";
        cout << "Fecha Ingreso: " << v.fechaIngreso << "\n";
    }
}

void actualizarVenta() {
    int id;
    cout << "Ingrese el ID de la venta a actualizar: ";
    cin >> id;

    for (auto& v : ventas) {
        if (v.idVenta == id) {
            cin.ignore();
            cout << "Nuevo número de factura: "; getline(cin, v.numeroFactura);
            cout << "Nueva serie: "; getline(cin, v.serie);
            cout << "Nueva fecha de factura: "; getline(cin, v.fechaFactura);
            cout << "Nuevo ID cliente: "; cin >> v.idCliente;
            cout << "Nuevo ID empleado: "; cin >> v.idEmpleado;
            cin.ignore();
            cout << "Nueva fecha ingreso: "; getline(cin, v.fechaIngreso);

            cout << "Venta actualizada correctamente.\n";
            return;
        }
    }
    cout << "Venta no encontrada.\n";
}

void eliminarVenta() {
    int id;
    cout << "Ingrese el ID de la venta a eliminar: ";
    cin >> id;

    for (auto it = ventas.begin(); it != ventas.end(); ++it) {
        if (it->idVenta == id) {
            ventas.erase(it);
            cout << "Venta eliminada correctamente.\n";
            return;
        }
    }
    cout << "Venta no encontrada.\n";
}
void crearVentaDetalle() {
    VentaDetalle d;
    cout << "ID Detalle Venta: "; cin >> d.idVentaDetalle;
    cout << "ID Venta (relacionado): "; cin >> d.idVenta;
    cout << "ID Producto: "; cin >> d.idProducto;
    cout << "Cantidad: "; cin >> d.cantidad;
    cout << "Precio unitario: "; cin >> d.precioUnitario;

    detalles.push_back(d);
    cout << "Detalle de venta registrado correctamente.\n";
}

void leerDetallesVenta() {
    if (detalles.empty()) {
        cout << "No hay detalles registrados.\n";
        return;
    }

    for (const auto& d : detalles) {
        cout << "\nID Detalle: " << d.idVentaDetalle << "\n";
        cout << "ID Venta: " << d.idVenta << "\n";
        cout << "ID Producto: " << d.idProducto << "\n";
        cout << "Cantidad: " << d.cantidad << "\n";
        cout << "Precio Unitario: " << d.precioUnitario << "\n";
    }
}

void actualizarDetalleVenta() {
    int id;
    cout << "Ingrese el ID del detalle a actualizar: ";
    cin >> id;

    for (auto& d : detalles) {
        if (d.idVentaDetalle == id) {
            cout << "Nuevo ID Venta: "; cin >> d.idVenta;
            cout << "Nuevo ID Producto: "; cin >> d.idProducto;
            cout << "Nueva cantidad: "; cin >> d.cantidad;
            cout << "Nuevo precio unitario: "; cin >> d.precioUnitario;
            cout << "Detalle actualizado correctamente.\n";
            return;
        }
    }

    cout << "Detalle no encontrado.\n";
}

void eliminarDetalleVenta() {
    int id;
    cout << "Ingrese el ID del detalle a eliminar: ";
    cin >> id;

    for (auto it = detalles.begin(); it != detalles.end(); ++it) {
        if (it->idVentaDetalle == id) {
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
        cout << "\n--- MENU CRUD VENTAS Y DETALLE ---\n";
        cout << "1. Crear venta\n";
        cout << "2. Ver ventas\n";
        cout << "3. Actualizar venta\n";
        cout << "4. Eliminar venta\n";
        cout << "5. Crear detalle de venta\n";
        cout << "6. Ver detalles de ventas\n";
        cout << "7. Actualizar detalle de venta\n";
        cout << "8. Eliminar detalle de venta\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearVenta(); break;
            case 2: leerVentas(); break;
            case 3: actualizarVenta(); break;
            case 4: eliminarVenta(); break;
            case 5: crearVentaDetalle(); break;
            case 6: leerDetallesVenta(); break;
            case 7: actualizarDetalleVenta(); break;
            case 8: eliminarDetalleVenta(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}

