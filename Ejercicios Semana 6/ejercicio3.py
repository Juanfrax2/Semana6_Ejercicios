class Animal:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def sonido(self):
        pass

class Perro(Animal):
    def sonido(self):
        return f"{self.nombre} dice: ¡Guau! ¡Guau!"

class Gato(Animal):
    def sonido(self):
        return f"{self.nombre} dice: ¡Miau! ¡Miau!"

class Pajaro(Animal):
    def sonido(self):
        return f"{self.nombre} dice: ¡Pío! ¡Pío!"

def interactuar():
    animales = []  
    while True:
        print("1. Crear un animal")
        print("2. Emitir sonido de un animal")
        print("3. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            nombre = input("Ingrese el nombre del animal: ")
            edad = int(input("Ingrese la edad del animal: "))
            tipo = input("Ingrese el tipo de animal (Perro, Gato, Pajaro): ").lower()

            if tipo == "perro":
                animal = Perro(nombre, edad)
            elif tipo == "gato":
                animal = Gato(nombre, edad)
            elif tipo == "pajaro":
                animal = Pajaro(nombre, edad)
            else:
                print("Tipo de animal no válido")
                continue

            animales.append(animal)  

        elif opcion == "2":
            nombre = input("Ingrese el nombre del animal del que desea escuchar el sonido: ").lower()  
            encontrado = False
            for animal in animales:
                if animal.nombre.lower() == nombre:  
                    print(animal.sonido())
                    encontrado = True
                    break
            if not encontrado:
                print(f"No se encontró un animal con el nombre {nombre}")

        elif opcion == "3":
            break
        else:
            print("Opción no válida")

if __name__ == "__main__":
    interactuar()
