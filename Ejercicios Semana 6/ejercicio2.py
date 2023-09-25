class Empleado:
    def __init__(self, nombre, edad, salario):
        self.nombre = nombre
        self.edad = edad
        self.salario = salario

    def describir_rol(self):
        return f"Soy un empleado de la empresa. Mi nombre es {self.nombre}, tengo {self.edad} años y mi salario es ${self.salario}"

class Gerente(Empleado):
    def __init__(self, nombre, edad, salario, departamento):
        super().__init__(nombre, edad, salario)
        self.departamento = departamento

    def describir_rol(self):
        return f"Soy un gerente de la empresa. Mi nombre es {self.nombre}, tengo {self.edad} años, mi salario es ${self.salario} y estoy a cargo del departamento {self.departamento}"

class Ingeniero(Empleado):
    def __init__(self, nombre, edad, salario, especialidad):
        super().__init__(nombre, edad, salario)
        self.especialidad = especialidad

    def describir_rol(self):
        return f"Soy un ingeniero de la empresa. Mi nombre es {self.nombre}, tengo {self.edad} años, mi salario es ${self.salario} y mi especialidad es {self.especialidad}"

class Asistente(Empleado):
    def __init__(self, nombre, edad, salario, supervisor):
        super().__init__(nombre, edad, salario)
        self.supervisor = supervisor

    def describir_rol(self):
        return f"Soy un asistente de la empresa. Mi nombre es {self.nombre}, tengo {self.edad} años, mi salario es ${self.salario} y mi supervisor es {self.supervisor}"

def interactuar_con_sistema():
    empleados = []
    print("Bienvenido al Sistema de Empleados")
    while True:
        print("\nOpciones:")
        print("1. Crear un empleado")
        print("2. Describir el rol de un empleado")
        print("3. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            nombre = str(input("Nombre del empleado: "))
            edad = int(input("Edad del empleado: "))
            salario = float(input("Salario del empleado: "))
            rol = str(input("Rol del empleado (Gerente/Ingeniero/Asistente): "))
            if rol.lower() == "gerente":
                departamento = int(input("Número del departamento del gerente: "))
                empleado = Gerente(nombre, edad, salario, departamento)
            elif rol.lower() == "ingeniero":
                especialidad = input("Especialidad del ingeniero: ")
                empleado = Ingeniero(nombre, edad, salario, especialidad)
            elif rol.lower() == "asistente":
                supervisor = input("Supervisor del asistente: ")
                empleado = Asistente(nombre, edad, salario, supervisor)
            else:
                print("Rol no válido. Por favor, elija entre Gerente, Ingeniero o Asistente.")
                continue
            empleados.append(empleado)  
            print(f"Empleado creado: {empleado.describir_rol()}")

        elif opcion == "2":
            nombre = input("Nombre del empleado: ")
            encontrado = False
            for empleado in empleados:
                if empleado.nombre == nombre:
                    print(empleado.describir_rol())
                    encontrado = True
                    break
            if not encontrado:
                print(f"No se encontró ningún empleado con el nombre {nombre}")

        elif opcion == "3":
            print("Saliendo del Sistema de Empleados de una Empresa.")
            break

        else:
            print("Opción no válida. Por favor, seleccione una opción válida.")

interactuar_con_sistema()
