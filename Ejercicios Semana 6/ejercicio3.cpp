#include <iostream>
#include <vector>
#include <string>

class Animal {
public:
    Animal(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

    virtual std::string sonido() {
        return "";
    }

    std::string getNombre() {
        return nombre;
    }

private:
    std::string nombre;
    int edad;
};

class Perro : public Animal {
public:
    Perro(const std::string& nombre, int edad) : Animal(nombre, edad) {}

    std::string sonido() override {
        return getNombre() + " dice: ¡Guau! ¡Guau!";
    }
};

class Gato : public Animal {
public:
    Gato(const std::string& nombre, int edad) : Animal(nombre, edad) {}

    std::string sonido() override {
        return getNombre() + " dice: ¡Miau! ¡Miau!";
    }
};

class Pajaro : public Animal {
public:
    Pajaro(const std::string& nombre, int edad) : Animal(nombre, edad) {}

    std::string sonido() override {
        return getNombre() + " dice: ¡Pio! ¡Pio!";
    }
};

void interactuar() {
    std::vector<Animal*> animales;
    
    while (true) {
        std::cout << "1. Crear un animal" << std::endl;
        std::cout << "2. Emitir sonido de un animal" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "1") {
            std::string nombre;
            int edad;
            std::string tipo;
            std::cout << "Ingrese el nombre del animal: ";
            std::cin >> nombre;
            std::cout << "Ingrese la edad del animal: ";
            std::cin >> edad;
            std::cout << "Ingrese el tipo de animal (Perro, Gato, Pajaro): ";
            std::cin >> tipo;

            Animal* animal;
            if (tipo == "Perro" || tipo == "perro") {
                animal = new Perro(nombre, edad);
            } else if (tipo == "Gato" || tipo == "gato") {
                animal = new Gato(nombre, edad);
            } else if (tipo == "Pajaro" || tipo == "pajaro") {
                animal = new Pajaro(nombre, edad);
            } else {
                std::cout << "Tipo de animal no valido" << std::endl;
                continue;
            }

            animales.push_back(animal);

        } else if (opcion == "2") {
            std::string nombre;
            std::cout << "Ingrese el nombre del animal del que desea escuchar el sonido: ";
            std::cin >> nombre;
            bool encontrado = false;
            for (Animal* animal : animales) {
                if (animal->getNombre() == nombre) {
                    std::cout << animal->sonido() << std::endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "No se encontro un animal con el nombre " << nombre << std::endl;
            }

        } else if (opcion == "3") {
            for (Animal* animal : animales) {
                delete animal;
            }
            animales.clear();
            break;
        } else {
            std::cout << "Opcion no valida" << std::endl;
        }
    }
}

int main() {
    interactuar();
    return 0;
}
