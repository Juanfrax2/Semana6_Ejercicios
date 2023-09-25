#include <iostream>
#include <vector>
#include <string>

class Empleado {
public:
    Empleado(std::string nombre, int edad, float salario)
        : nombre(nombre), edad(edad), salario(salario) {}

    virtual std::string describirRol() {
        return "Soy un empleado de la empresa. Mi nombre es " + nombre +
               ", tengo " + std::to_string(edad) + " años y mi salario es $" +
               std::to_string(salario);
    }

protected:
    std::string nombre;
    int edad;
    float salario;
};

class Gerente : public Empleado {
public:
    Gerente(std::string nombre, int edad, float salario, std::string departamento)
        : Empleado(nombre, edad, salario), departamento(departamento) {}

    std::string describirRol() override {
        return "Soy un gerente de la empresa. Mi nombre es " + nombre +
               ", tengo " + std::to_string(edad) + " años, mi salario es $" +
               std::to_string(salario) + " y estoy a cargo del departamento " +
               departamento;
    }

private:
    std::string departamento;
};

class Ingeniero : public Empleado {
public:
    Ingeniero(std::string nombre, int edad, float salario, std::string especialidad)
        : Empleado(nombre, edad, salario), especialidad(especialidad) {}

    std::string describirRol() override {
        return "Soy un ingeniero de la empresa. Mi nombre es " + nombre +
               ", tengo " + std::to_string(edad) + " años, mi salario es $" +
               std::to_string(salario) + " y mi especialidad es " + especialidad;
    }

private:
    std::string especialidad;
};

class Asistente : public Empleado {
public:
    Asistente(std::string nombre, int edad, float salario, std::string supervisor)
        : Empleado(nombre, edad, salario), supervisor(supervisor) {}

    std::string describirRol() override {
        return "Soy un asistente de la empresa. Mi nombre es " + nombre +
               ", tengo " + std::to_string(edad) + " años, mi salario es $" +
               std::to_string(salario) + " y mi supervisor es " + supervisor;
    }

private:
    std::string supervisor;
};

void interactuarConSistema() {
    std::vector<Empleado*> empleados;
    std::cout << "Bienvenido al Sistema de Empleados" << std::endl;
    while (true) {
        std::cout << "\nOpciones:" << std::endl;
        std::cout << "1. Crear un empleado" << std::endl;
        std::cout << "2. Describir el rol de un empleado" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "1") {
            std::string nombre;
            int edad;
            float salario;
            std::string rol;

            std::cout << "Nombre del empleado: ";
            std::cin >> nombre;
            std::cout << "Edad del empleado: ";
            std::cin >> edad;
            std::cout << "Salario del empleado: ";
            std::cin >> salario;
            std::cout << "Rol del empleado (Gerente/Ingeniero/Asistente): ";
            std::cin >> rol;

            if (rol == "Gerente" || rol == "gerente") {
                std::string departamento;
                std::cout << "Numero del departamento del gerente: ";
                std::cin >> departamento;
                empleados.push_back(new Gerente(nombre, edad, salario, departamento));
            } else if (rol == "Ingeniero" || rol == "ingeniero") {
                std::string especialidad;
                std::cout << "Especialidad del ingeniero: ";
                std::cin >> especialidad;
                empleados.push_back(new Ingeniero(nombre, edad, salario, especialidad));
            } else if (rol == "Asistente" || rol == "asistente") {
                std::string supervisor;
                std::cout << "Supervisor del asistente: ";
                std::cin >> supervisor;
                empleados.push_back(new Asistente(nombre, edad, salario, supervisor));
            } else {
                std::cout << "Rol no valido. Por favor, elija entre Gerente, Ingeniero o Asistente." << std::endl;
            }

            std::cout << "Empleado creado." << std::endl;
        } else if (opcion == "2") {
            std::string nombre;
            std::cout << "Nombre del empleado: ";
            std::cin >> nombre;
            bool encontrado = false;
            for (Empleado* empleado : empleados) {
                if (empleado->describirRol().find(nombre) != std::string::npos) {
                    std::cout << empleado->describirRol() << std::endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << "No se encontro ningun empleado con el nombre " << nombre << std::endl;
            }
        } else if (opcion == "3") {
            std::cout << "Saliendo del Sistema de Empleados de una Empresa." << std::endl;
            break;
        } else {
            std::cout << "Opcion no valida. Por favor, seleccione una opcion valida." << std::endl;
        }
    }
}

int main() {
    interactuarConSistema();
    return 0;
}
