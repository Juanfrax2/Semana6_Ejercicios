#include <iostream>
#include <vector>

class Reserva {
protected:
    std::string nombre_pasajero;
    std::string numero_vuelo;
    std::string fecha;

public:
    Reserva(std::string nombre_pasajero, std::string numero_vuelo, std::string fecha)
        : nombre_pasajero(nombre_pasajero), numero_vuelo(numero_vuelo), fecha(fecha) {}

    virtual void mostrar_detalle() const {
        std::cout << "Reserva - Pasajero: " << nombre_pasajero << ", Vuelo: " << numero_vuelo << ", Fecha: " << fecha << std::endl;
    }
};

class ReservaEconomica : public Reserva {
private:
    std::string asiento;

public:
    ReservaEconomica(std::string nombre_pasajero, std::string numero_vuelo, std::string fecha, std::string asiento)
        : Reserva(nombre_pasajero, numero_vuelo, fecha), asiento(asiento) {}

    void mostrar_detalle() const override {
        std::cout << "Reserva Economica - Pasajero: " << nombre_pasajero << ", Vuelo: " << numero_vuelo << ", Fecha: " << fecha << ", Asiento: " << asiento << std::endl;
    }
};

class ReservaBusiness : public Reserva {
private:
    std::string servicio_empresarial;

public:
    ReservaBusiness(std::string nombre_pasajero, std::string numero_vuelo, std::string fecha, std::string servicio_empresarial)
        : Reserva(nombre_pasajero, numero_vuelo, fecha), servicio_empresarial(servicio_empresarial) {}

    void mostrar_detalle() const override {
        std::cout << "Reserva Business - Pasajero: " << nombre_pasajero << ", Vuelo: " << numero_vuelo << ", Fecha: " << fecha << ", Servicio Empresarial: " << servicio_empresarial << std::endl;
    }
};

class ReservaPrimeraClase : public Reserva {
private:
    std::string acceso_salon;

public:
    ReservaPrimeraClase(std::string nombre_pasajero, std::string numero_vuelo, std::string fecha, std::string acceso_salon)
        : Reserva(nombre_pasajero, numero_vuelo, fecha), acceso_salon(acceso_salon) {}

    void mostrar_detalle() const override {
        std::cout << "Reserva Primera Clase - Pasajero: " << nombre_pasajero << ", Vuelo: " << numero_vuelo << ", Fecha: " << fecha << ", Acceso a Salon: " << acceso_salon << std::endl;
    }
};

class SistemaReservas {
public:
    void agregar_reserva(Reserva* reserva) {
        reservas.push_back(reserva);
    }

    void mostrar_reservas() const {
        for (const Reserva* reserva : reservas) {
            reserva->mostrar_detalle();
        }
    }

private:
    std::vector<Reserva*> reservas;
};

int main() {
    SistemaReservas sistema_reservas;

    while (true) {
        std::cout << "\nSistema de Reservas de Vuelos" << std::endl;
        std::cout << "1. Crear Reserva Economica" << std::endl;
        std::cout << "2. Crear Reserva Business" << std::endl;
        std::cout << "3. Crear Reserva Primera Clase" << std::endl;
        std::cout << "4. Mostrar Reservas" << std::endl;
        std::cout << "5. Salir" << std::endl;

        std::cout << "Seleccione una opcion: ";
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "1") {
            std::string nombre, vuelo, fecha, asiento;
            std::cout << "Nombre del pasajero: ";
            std::cin >> nombre;
            std::cout << "Numero de vuelo: ";
            std::cin >> vuelo;
            std::cout << "Fecha: ";
            std::cin >> fecha;
            std::cout << "Asiento: ";
            std::cin >> asiento;
            ReservaEconomica* reserva = new ReservaEconomica(nombre, vuelo, fecha, asiento);
            sistema_reservas.agregar_reserva(reserva);
            std::cout << "Reserva Economica creada con exito." << std::endl;
        } else if (opcion == "2") {
            std::string nombre, vuelo, fecha, servicio;
            std::cout << "Nombre del pasajero: ";
            std::cin >> nombre;
            std::cout << "Numero de vuelo: ";
            std::cin >> vuelo;
            std::cout << "Fecha: ";
            std::cin >> fecha;
            std::cout << "Servicio empresarial: ";
            std::cin >> servicio;
            ReservaBusiness* reserva = new ReservaBusiness(nombre, vuelo, fecha, servicio);
            sistema_reservas.agregar_reserva(reserva);
            std::cout << "Reserva Business creada con exito." << std::endl;
        } else if (opcion == "3") {
            std::string nombre, vuelo, fecha, acceso;
            std::cout << "Nombre del pasajero: ";
            std::cin >> nombre;
            std::cout << "Numero de vuelo: ";
            std::cin >> vuelo;
            std::cout << "Fecha: ";
            std::cin >> fecha;
            std::cout << "Acceso a salon: ";
            std::cin >> acceso;
            ReservaPrimeraClase* reserva = new ReservaPrimeraClase(nombre, vuelo, fecha, acceso);
            sistema_reservas.agregar_reserva(reserva);
            std::cout << "Reserva de Primera Clase creada con exito." << std::endl;
        } else if (opcion == "4") {
            std::cout << "\nListado de Reservas:" << std::endl;
            sistema_reservas.mostrar_reservas();
        } else if (opcion == "5") {
            std::cout << "¡Hasta luego!" << std::endl;
            break;
        } else {
            std::cout << "Opcion no valida. Intente nuevamente." << std::endl;
        }
    }

    return 0;
}
