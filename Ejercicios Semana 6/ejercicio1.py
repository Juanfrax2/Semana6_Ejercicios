class Producto:
    def __init__(self, nombre, precio, categoria):
        self.nombre = nombre
        self.precio = precio
        self.categoria = categoria

    def mostrar_detalle(self):
        print(f"Nombre: {self.nombre}\nPrecio: ${self.precio}\nCategoría: {self.categoria}")

class Electronico(Producto):
    def __init__(self, nombre, precio, marca):
        super().__init__(nombre, precio, "Electrónico")
        self.marca = marca

    def mostrar_detalle(self):
        super().mostrar_detalle()
        print(f"Marca: {self.marca}")

class Alimenticio(Producto):
    def __init__(self, nombre, precio, fecha_vencimiento):
        super().__init__(nombre, precio, "Alimenticio")
        self.fecha_vencimiento = fecha_vencimiento

    def mostrar_detalle(self):
        super().mostrar_detalle()
        print(f"Fecha de Vencimiento: {self.fecha_vencimiento}")

class Vestimenta(Producto):
    def __init__(self, nombre, precio, talla):
        super().__init__(nombre, precio, "Vestimenta")
        self.talla = talla

    def mostrar_detalle(self):
        super().mostrar_detalle()
        print(f"Talla: {self.talla}")

def menu_principal():
    while True:
        print("\nMenú Principal:")
        print("1. Crear producto electrónico")
        print("2. Crear producto alimenticio")
        print("3. Crear producto de vestimenta")
        print("4. Salir")

        opcion = input("Selecciona una opción: ")

        if opcion == "1":
            nombre = input("Ingresa el nombre del producto electrónico: ")
            precio = float(input("Ingresa el precio del producto electrónico: "))
            marca = input("Ingresa la marca del producto electrónico: ")
            producto = Electronico(nombre, precio, marca)
            producto.mostrar_detalle()
        elif opcion == "2":
            nombre = input("Ingresa el nombre del producto alimenticio: ")
            precio = float(input("Ingresa el precio del producto alimenticio: "))
            fecha_vencimiento = input("Ingresa la fecha de vencimiento del producto alimenticio: ")
            producto = Alimenticio(nombre, precio, fecha_vencimiento)
            producto.mostrar_detalle()
        elif opcion == "3":
            nombre = input("Ingresa el nombre del producto de vestimenta: ")
            precio = float(input("Ingresa el precio del producto de vestimenta: "))
            talla = input("Ingresa la talla del producto de vestimenta: ")
            producto = Vestimenta(nombre, precio, talla)
            producto.mostrar_detalle()
        elif opcion == "4":
            break
        else:
            print("Opción no válida. Por favor, selecciona una opción válida.")

menu_principal()

