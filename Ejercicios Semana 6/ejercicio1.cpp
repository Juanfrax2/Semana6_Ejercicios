#include <iostream>
#include <string>

class Producto {
public:
    Producto(std::string nombre, double precio, std::string categoria)
        : nombre(nombre), precio(precio), categoria(categoria) {}

    void mostrar_detalle() {
        std::cout << "Nombre: " << nombre << "\nPrecio: $" << precio << "\nCategoria: " << categoria << std::endl;
    }

protected:
    std::string nombre;
    double precio;
    std::string categoria;
};

class Electronico : public Producto {
public:
    Electronico(std::string nombre, double precio, std::string marca)
        : Producto(nombre, precio, "Electronico"), marca(marca) {}

    void mostrar_detalle() {
        Producto::mostrar_detalle();
        std::cout << "Marca: " << marca << std::endl;
    }

private:
    std::string marca;
};

class Alimenticio : public Producto {
public:
    Alimenticio(std::string nombre, double precio, std::string fecha_vencimiento)
        : Producto(nombre, precio, "Alimenticio"), fecha_vencimiento(fecha_vencimiento) {}

    void mostrar_detalle() {
        Producto::mostrar_detalle();
        std::cout << "Fecha de Vencimiento: " << fecha_vencimiento << std::endl;
    }

private:
    std::string fecha_vencimiento;
};

class Vestimenta : public Producto {
public:
    Vestimenta(std::string nombre, double precio, std::string talla)
        : Producto(nombre, precio, "Vestimenta"), talla(talla) {}

    void mostrar_detalle() {
        Producto::mostrar_detalle();
        std::cout << "Talla: " << talla << std::endl;
    }

private:
    std::string talla;
};

void menu_principal() {
    while (true) {
        std::cout << "\nMenu Principal:\n";
        std::cout << "1. Crear producto electronico\n";
        std::cout << "2. Crear producto alimenticio\n";
        std::cout << "3. Crear producto de vestimenta\n";
        std::cout << "4. Salir\n";

        std::cout << "Seleccione una opcion: ";
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "1") {
            std::string nombre, marca;
            double precio;
            std::cout << "Ingresa el nombre del producto electronico: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingresa el precio del producto electronico: ";
            std::cin >> precio;
            std::cout << "Ingresa la marca del producto electronico: ";
            std::cin.ignore();
            std::getline(std::cin, marca);
            Electronico producto(nombre, precio, marca);
            producto.mostrar_detalle();
        } else if (opcion == "2") {
            std::string nombre, fecha_vencimiento;
            double precio;
            std::cout << "Ingresa el nombre del producto alimenticio: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingresa el precio del producto alimenticio: ";
            std::cin >> precio;
            std::cout << "Ingresa la fecha de vencimiento del producto alimenticio: ";
            std::cin.ignore();
            std::getline(std::cin, fecha_vencimiento);
            Alimenticio producto(nombre, precio, fecha_vencimiento);
            producto.mostrar_detalle();
        } else if (opcion == "3") {
            std::string nombre, talla;
            double precio;
            std::cout << "Ingresa el nombre del producto de vestimenta: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingresa el precio del producto de vestimenta: ";
            std::cin >> precio;
            std::cout << "Ingresa la talla del producto de vestimenta: ";
            std::cin.ignore();
            std::getline(std::cin, talla);
            Vestimenta producto(nombre, precio, talla);
            producto.mostrar_detalle();
        } else if (opcion == "4") {
            break;
        } else {
            std::cout << "Opción no valida. Por favor, selecciona una opcion valida." << std::endl;
        }
    }
}

int main() {
    menu_principal();
    return 0;
}
