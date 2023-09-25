class Reserva:
    def __init__(self, nombre_pasajero, numero_vuelo, fecha):
        self.nombre_pasajero = nombre_pasajero
        self.numero_vuelo = numero_vuelo
        self.fecha = fecha

    def mostrar_detalle(self):
        raise NotImplementedError("Este método debe ser implementado en las clases derivadas")


class ReservaEconomica(Reserva):
    def __init__(self, nombre_pasajero, numero_vuelo, fecha, asiento):
        super().__init__(nombre_pasajero, numero_vuelo, fecha)
        self.asiento = asiento

    def mostrar_detalle(self):
        return f"Reserva Económica - Pasajero: {self.nombre_pasajero}, Vuelo: {self.numero_vuelo}, Fecha: {self.fecha}, Asiento: {self.asiento}"


class ReservaBusiness(Reserva):
    def __init__(self, nombre_pasajero, numero_vuelo, fecha, servicio_empresarial):
        super().__init__(nombre_pasajero, numero_vuelo, fecha)
        self.servicio_empresarial = servicio_empresarial

    def mostrar_detalle(self):
        return f"Reserva Business - Pasajero: {self.nombre_pasajero}, Vuelo: {self.numero_vuelo}, Fecha: {self.fecha}, Servicio Empresarial: {self.servicio_empresarial}"


class ReservaPrimeraClase(Reserva):
    def __init__(self, nombre_pasajero, numero_vuelo, fecha, acceso_salon):
        super().__init__(nombre_pasajero, numero_vuelo, fecha)
        self.acceso_salon = acceso_salon

    def mostrar_detalle(self):
        return f"Reserva Primera Clase - Pasajero: {self.nombre_pasajero}, Vuelo: {self.numero_vuelo}, Fecha: {self.fecha}, Acceso a Salón: {self.acceso_salon}"


class SistemaReservas:
    def __init__(self):
        self.reservas = []

    def agregar_reserva(self, reserva):
        if isinstance(reserva, Reserva):
            self.reservas.append(reserva)
            return True
        else:
            return False

    def mostrar_reservas(self):
        for reserva in self.reservas:
            print(reserva.mostrar_detalle())

def interfaz():
    sistema_reservas = SistemaReservas()

    while True:
        print("\nSistema de Reservas de Vuelos")
        print("1. Crear Reserva Económica")
        print("2. Crear Reserva Business")
        print("3. Crear Reserva Primera Clase")
        print("4. Mostrar Reservas")
        print("5. Salir")

        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            nombre = input("Nombre del pasajero: ")
            vuelo = input("Número de vuelo: ")
            fecha = input("Fecha: ")
            asiento = input("Asiento: ")
            reserva = ReservaEconomica(nombre, vuelo, fecha, asiento)
            if sistema_reservas.agregar_reserva(reserva):
                print("Reserva Económica creada con éxito.")
            else:
                print("Error al crear la reserva.")

        elif opcion == "2":
            nombre = input("Nombre del pasajero: ")
            vuelo = input("Número de vuelo: ")
            fecha = input("Fecha: ")
            servicio = input("Servicio empresarial: ")
            reserva = ReservaBusiness(nombre, vuelo, fecha, servicio)
            if sistema_reservas.agregar_reserva(reserva):
                print("Reserva Business creada con éxito.")
            else:
                print("Error al crear la reserva.")

        elif opcion == "3":
            nombre = input("Nombre del pasajero: ")
            vuelo = input("Número de vuelo: ")
            fecha = input("Fecha: ")
            acceso = input("Acceso a salón: ")
            reserva = ReservaPrimeraClase(nombre, vuelo, fecha, acceso)
            if sistema_reservas.agregar_reserva(reserva):
                print("Reserva de Primera Clase creada con éxito.")
            else:
                print("Error al crear la reserva.")

        elif opcion == "4":
            print("\nListado de Reservas:")
            sistema_reservas.mostrar_reservas()

        elif opcion == "5":
            print("¡Hasta luego!")
            break

        else:
            print("Opción no válida. Intente nuevamente.")

interfaz()
