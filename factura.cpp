#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <algorithm>
using namespace std;

// ==== CLASES ==== //
class Cliente {
public:
    string nit, nombre, direccion;
    Cliente(string nit, string nombre, string direccion)
        : nit(nit), nombre(nombre), direccion(direccion) {}
};

class Producto {
public:
    string codigo, nombre, marca;
    double precio;
    Producto(string codigo, string nombre, string marca, double precio)
        : codigo(codigo), nombre(nombre), marca(marca), precio(precio) {}
};

class DetalleVenta {
public:
    Producto producto;
    int cantidad;
    DetalleVenta(Producto producto, int cantidad)
        : producto(producto), cantidad(cantidad) {}
};

class Venta {
public:
    int numeroFactura;
    string fecha;
    Cliente cliente;
    vector<DetalleVenta> detalles;

    Venta(int numeroFactura, string fecha, Cliente cliente)
        : numeroFactura(numeroFactura), fecha(fecha), cliente(cliente) {}

    void agregarDetalle(DetalleVenta detalle) {
        for (auto& d : detalles) {
            if (d.producto.codigo == detalle.producto.codigo) {
                d.cantidad += detalle.cantidad;
                return;
            }
        }
        detalles.push_back(detalle);
    }

    double total() {
        double total = 0.0;
        for (auto& d : detalles)
            total += d.cantidad * d.producto.precio;
        return total;
    }

    void imprimirFactura() {
        sort(detalles.begin(), detalles.end(), [](DetalleVenta& a, DetalleVenta& b) {
            return a.producto.codigo < b.producto.codigo;
        });

        cout << "\n============================================================\n";
        cout << "|                   FACTURA DE VENTA                      |\n";
        cout << "------------------------------------------------------------\n";
        cout << " No Factura: " << numeroFactura << "\t\tFecha: " << fecha << "\n";
        cout << " NIT: " << cliente.nit << "\n";
        cout << " Cliente: " << cliente.nombre << "\n";
        cout << " Direccion: " << cliente.direccion << "\n";
        cout << "------------------------------------------------------------\n";
        cout << "| Cod  | Producto                     | Cant | Precio | Subtotal |\n";
        cout << "------------------------------------------------------------\n";

        for (auto& d : detalles) {
            double subtotal = d.cantidad * d.producto.precio;
            cout << " " << setw(4) << d.producto.codigo
                 << " | " << setw(28) << left << d.producto.nombre
                 << "| " << setw(4) << d.cantidad
                 << " | Q " << setw(6) << fixed << setprecision(2) << d.producto.precio
                 << " | Q " << setw(7) << fixed << setprecision(2) << subtotal << "\n";
        }

        cout << "------------------------------------------------------------\n";
        cout << " Total a pagar:\t\t\t\t\tQ " << fixed << setprecision(2) << total() << "\n";
        cout << "============================================================\n";
        cout << " Gracias por su compra.\n";
        cout << "============================================================\n";
    }
};

// ==== VARIABLES GLOBALES ==== //
vector<Cliente> clientes;
vector<Producto> productos;
vector<Venta> ventas;
int contadorFactura = 1;

// ==== FUNCIONES DE APOYO ==== //
bool validarNIT(string nit) {
    if (nit == "CF" || nit == "cf") return true;
    return all_of(nit.begin(), nit.end(), ::isdigit) && nit.length() >= 6;
}

Cliente buscarCliente(string nit) {
    for (auto& c : clientes)
        if (c.nit == nit)
            return c;
    return Cliente("", "", "");
}

string obtenerFecha() {
    time_t t = time(nullptr);
    tm* tiempoPtr = localtime(&t); // ? reemplazo compatible
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", tiempoPtr); // ? alternativa a put_time
    return string(buffer);
}

Producto buscarProducto(string codigo) {
    for (auto& p : productos)
        if (p.codigo == codigo)
            return p;
    return Producto("", "", "", 0);
}

void cargarProductos() {
    productos.push_back({ "1", "Sopa Instantanea", "Laky", 2.5 });
    productos.push_back({ "2", "Corn flakes", "Kelloggs", 25.0 });
    productos.push_back({ "3", "Coca cola lata", "Coca Cola", 3.0 });
    productos.push_back({ "4", "Galletas Oreo", "Nabisco", 5.0 });
    productos.push_back({ "5", "Pan Blanco", "Bimbo", 6.5 });
    productos.push_back({ "6", "Leche Entera", "Dos Pinos", 7.5 });
    productos.push_back({ "7", "Jugo de Naranja", "Del Valle", 4.0 });
    productos.push_back({ "8", "Arroz Blanco", "Gallo Dorado", 3.25 });
    productos.push_back({ "9", "Frijol Negro", "La Sierra", 4.75 });
    productos.push_back({ "10", "Aceite Vegetal", "Ideal", 8.9 });
}

void crearVenta() {
    string nit;
    cout << "\nIngrese NIT del cliente: ";
    cin >> nit;

    if (!validarNIT(nit)) {
        cout << "NIT invalido. Solo numeros o CF.\n";
        return;
    }

    Cliente cliente = buscarCliente(nit);
    if (cliente.nit == "") {
        cin.ignore();
        string nombre, direccion;
        cout << "Cliente no encontrado. Ingrese nombre: ";
        getline(cin, nombre);
        cout << "Ingrese direccion: ";
        getline(cin, direccion);
        cliente = Cliente(nit, nombre, direccion);
        clientes.push_back(cliente);
    }

    Venta venta(contadorFactura++, obtenerFecha(), cliente);

    while (true) {
        cout << "\nIngrese codigo del producto (0 para salir): ";
        string codigo;
        cin >> codigo;
        if (codigo == "0") break;

        Producto p = buscarProducto(codigo);
        if (p.codigo == "") {
            cout << "Producto no encontrado.\n";
            continue;
        }

        int cantidad;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "Cantidad invalida.\n";
            continue;
        }

        venta.agregarDetalle(DetalleVenta(p, cantidad));
    }

    ventas.push_back(venta);
    venta.imprimirFactura();
}

// ==== MENU ==== //
int main() {
    cargarProductos();

    int opcion;
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Registrar Venta\n";
        cout << "2. Ver Ultima Factura\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            crearVenta();
            break;
        case 2:
            if (!ventas.empty())
                ventas.back().imprimirFactura();
            else
                cout << "No hay facturas aun.\n";
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}

