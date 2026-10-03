# 📚 TALLER 1 — ESTRUCTURAS DE DATOS

## Arreglos y Listas

**Curso:** Algoritmos y Programación 2

---

## 📌 Indicaciones generales

Realizar los siguientes programas teniendo en cuenta las siguientes condiciones:

### Para cada ejercicio:

* **a.** Realizar el **pseudocódigo** y entregarlo en físico.
* **b.** Realizar el **código en C++** y cargarlo en el archivo **“Taller 1”** de Classroom.

---

# 🟦 Parte 1 — Arreglos y Programación Orientada a Objetos

## 1. 🌡️ Registro de temperaturas

Escribe un programa que almacene las **temperaturas diarias de una semana (7 días)** y calcule:

* La temperatura media.
* La temperatura más alta.
* La temperatura más baja.

### Requerimientos

* Usar un **arreglo de tamaño 7**.
* Aplicar **bucles** para calcular:

  * La media.
  * El máximo.
  * El mínimo.

---

## 2. 🌤️ Registro y análisis climático

Crea una clase base llamada `RegistroTemperaturas` que almacene las **temperaturas diarias de una semana (7 días)** y tenga métodos encapsulados para calcular:

* La temperatura media.
* La temperatura máxima.
* La temperatura mínima.

Luego, crea una clase derivada llamada `AnalisisClimatico` que extienda la funcionalidad de la clase base, permitiendo mostrar un **resumen detallado de las temperaturas**.

### Requerimientos

* Usar un **arreglo encapsulado** para almacenar las temperaturas.
* Aplicar **herencia** para extender las funcionalidades.
* Implementar métodos para calcular:

  * Temperatura media.
  * Temperatura máxima.
  * Temperatura mínima.
* Mostrar un resumen detallado de los datos.

---

## 3. 💰 Registro y análisis de ventas

Diseña una clase base llamada `RegistroVentas` que almacene las **ventas diarias de un comerciante durante 10 días**.

La clase debe tener métodos encapsulados para calcular:

* El total de ventas.
* El promedio diario de ventas.

Luego, crea una clase derivada llamada `AnalisisVentas` que **sobrescriba métodos** para incluir funcionalidades adicionales, como determinar:

* El día de mayor venta.
* El día de menor venta.

### Requerimientos

* Encapsular el **arreglo de ventas** dentro de una clase.
* Aplicar **herencia** para extender el análisis de ventas.
* Usar **polimorfismo** para sobrescribir métodos de análisis en la clase derivada.
* Determinar el día con:

  * Mayor venta.
  * Menor venta.

---

## 4. 🌡️ Sistema de sensores de temperatura

Una empresa necesita gestionar los registros de temperatura de sus dispositivos industriales.

Cada dispositivo tiene sensores que miden la temperatura en diferentes momentos del día.

Se deben modelar dos tipos de sensores:

* **Sensor analógico:** registra temperaturas con valores decimales.
* **Sensor digital:** registra temperaturas como valores enteros.

### Implementación

Implementa un programa en C++ que:

1. Defina una clase base `Sensor` que almacene un **arreglo de temperaturas de 7 días**.
2. Aplique **encapsulamiento**, protegiendo los atributos de la clase `Sensor` y permitiendo su acceso únicamente mediante métodos.
3. Implemente dos clases derivadas:

   * `SensorAnalogico`
   * `SensorDigital`
4. Las clases derivadas deben sobrescribir el método `mostrarDatos()`, cada una con su propio formato de salida.
5. Utilice **herencia** para que `SensorAnalogico` y `SensorDigital` hereden de `Sensor`.
6. Utilice **polimorfismo** para permitir que un mismo puntero pueda apuntar a distintos tipos de sensores.

### Conceptos utilizados

* Encapsulamiento
* Herencia
* Polimorfismo
* Sobrescritura de métodos
* Arreglos

---

# 🟩 Parte 2 — Matrices

## 5. 🎓 Calificaciones de estudiantes

En una clase hay **4 estudiantes** que presentan **3 exámenes**.

Escribe un programa que permita:

1. Ingresar las calificaciones de cada examen por estudiante.
2. Calcular el promedio de calificaciones de cada estudiante.
3. Calcular el promedio de cada examen.

### Requerimientos

* Usar una **matriz de 4 × 3** para almacenar las calificaciones.
* Calcular:

  * Promedio por estudiante.
  * Promedio por examen.

---

## 6. 📅 Horario semanal

Una escuela tiene **5 días de clases a la semana** y **6 horas por día**.

Escribe un programa que permita:

1. Ingresar el nombre de las materias para cada hora.
2. Mostrar el horario semanal de un estudiante.

### Requerimientos

* Usar una **matriz de 6 × 5** para almacenar las materias.
* Mostrar el horario en formato de **tabla**.

---

## 7. 🏪 Precios de productos por sucursal

Una tienda tiene **5 productos** y **3 sucursales**.

Escribe un programa que permita:

1. Ingresar el precio de cada producto en cada sucursal.
2. Calcular el promedio de precios por producto.
3. Calcular el promedio de precios por sucursal.

### Requerimientos

* Usar una **matriz de 5 × 3** para almacenar los precios.
* Calcular:

  * Promedio por producto.
  * Promedio por sucursal.

---

# 🟨 Parte 3 — Listas enlazadas

> **Importante:** Para los ejercicios **8 al 11**, realizar el código fuente agregando un **menú** y utilizando un condicional `switch-case`, relacionando cada opción del menú con su respectivo método.

---

## 8. 📦 Inventario de productos

Una tienda desea gestionar su inventario de productos.

Cada producto tiene:

* Código.
* Nombre.
* Precio.

La tienda necesita un sistema que permita:

* Almacenar los productos de manera ordenada por su código.
* Agregar nuevos productos.
* Buscar un producto por su código.
* Mostrar todo el inventario.
* Eliminar un producto cuando ya no esté disponible.

### Requerimientos

Crear una **lista enlazada** donde cada nodo represente un producto con:

| Dato   | Tipo                 |
| ------ | -------------------- |
| Código | Entero               |
| Nombre | Cadena de caracteres |
| Precio | Flotante             |

### Funciones

```text
insertarProducto(codigo, nombre, precio)
```

Inserta un nuevo producto en la lista de manera ordenada por el código.

```text
mostrarInventario()
```

Muestra todos los productos disponibles.

```text
buscarProducto(codigo)
```

Busca un producto por su código y muestra sus detalles.

```text
eliminarProducto(codigo)
```

Elimina un producto del inventario.

---

## 9. 🏥 Registro de citas médicas

Una clínica quiere llevar un registro de las citas médicas de sus pacientes.

Cada cita tiene:

* Número de identificación.
* Nombre del paciente.
* Fecha de la cita.

El sistema debe permitir:

* Agregar nuevas citas.
* Mostrar todas las citas programadas.
* Buscar una cita por su número de identificación.
* Eliminar una cita cuando haya sido cancelada.

### Requerimientos

Crear una **lista enlazada** donde cada nodo represente una cita con:

| Dato                     | Tipo                 |
| ------------------------ | -------------------- |
| Número de identificación | Entero               |
| Nombre del paciente      | Cadena de caracteres |
| Fecha de la cita         | Cadena de caracteres |

### Funciones

```text
agregarCita(id, nombrePaciente, fecha)
```

Inserta una nueva cita de forma ordenada por el número de identificación.

```text
mostrarCitas()
```

Muestra todas las citas programadas.

```text
buscarCita(id)
```

Busca una cita por su número de identificación.

```text
cancelarCita(id)
```

Elimina una cita de la lista si ha sido cancelada.

---

## 10. 📚 Gestión de libros

Una biblioteca necesita un sistema que le permita gestionar su colección de libros.

Cada libro tiene:

* Número ISBN.
* Título.
* Autor.

El sistema debe permitir:

* Agregar nuevos libros.
* Buscar libros por su número ISBN.
* Mostrar todos los libros de la colección.
* Eliminar libros que ya no estén disponibles.

### Requerimientos

Crear una **lista enlazada** donde cada nodo represente un libro con:

| Dato   | Tipo                 |
| ------ | -------------------- |
| ISBN   | Entero               |
| Título | Cadena de caracteres |
| Autor  | Cadena de caracteres |

### Funciones

```text
agregarLibro(ISBN, titulo, autor)
```

Agrega un libro a la colección de manera ordenada por su número ISBN.

```text
mostrarLibros()
```

Muestra todos los libros de la colección.

```text
buscarLibro(ISBN)
```

Busca un libro por su número ISBN.

```text
eliminarLibro(ISBN)
```

Elimina un libro de la colección si ya no está disponible.

---

## 11. 🚗 Registro de vehículos en un estacionamiento

Un estacionamiento necesita registrar los vehículos que ingresan y salen.

Cada vehículo tiene:

* Placa.
* Modelo.
* Hora de entrada.

El sistema debe permitir:

* Registrar un nuevo vehículo cuando ingrese.
* Mostrar todos los vehículos dentro del estacionamiento.
* Buscar un vehículo por su placa.
* Eliminar un vehículo cuando salga.

### Requerimientos

Crear una **lista enlazada** donde cada nodo represente un vehículo con:

| Dato            | Tipo                 |
| --------------- | -------------------- |
| Placa           | Cadena de caracteres |
| Modelo          | Cadena de caracteres |
| Hora de entrada | Cadena de caracteres |

### Funciones

```text
registrarVehiculo(placa, modelo, horaEntrada)
```

Inserta un vehículo en el registro.

```text
mostrarVehiculos()
```

Muestra todos los vehículos dentro del estacionamiento.

```text
buscarVehiculo(placa)
```

Busca un vehículo por su placa.

```text
retirarVehiculo(placa)
```

Elimina un vehículo del registro cuando salga del estacionamiento.

---

# 📋 Resumen de conceptos

| Ejercicios | Tema principal     | Estructura / concepto                               |
| ---------- | ------------------ | --------------------------------------------------- |
| 1          | Temperaturas       | Arreglo                                             |
| 2          | Análisis climático | Arreglo + Herencia                                  |
| 3          | Ventas             | Arreglo + Herencia + Polimorfismo                   |
| 4          | Sensores           | Arreglo + Encapsulamiento + Herencia + Polimorfismo |
| 5          | Calificaciones     | Matriz 4 × 3                                        |
| 6          | Horario            | Matriz 6 × 5                                        |
| 7          | Precios            | Matriz 5 × 3                                        |
| 8          | Inventario         | Lista enlazada + Menú + `switch-case`               |
| 9          | Citas médicas      | Lista enlazada + Menú + `switch-case`               |
| 10         | Biblioteca         | Lista enlazada + Menú + `switch-case`               |
| 11         | Estacionamiento    | Lista enlazada + Menú + `switch-case`               |

---

## 🧠 Conceptos que se trabajan

* **Arreglos**
* **Matrices**
* **Bucles**
* **Encapsulamiento**
* **Clases**
* **Herencia**
* **Polimorfismo**
* **Sobrescritura de métodos**
* **Listas enlazadas**
* **Nodos**
* **Punteros**
* **Menús**
* **`switch-case`**
* **Inserción ordenada**
* **Búsqueda**
* **Eliminación**
