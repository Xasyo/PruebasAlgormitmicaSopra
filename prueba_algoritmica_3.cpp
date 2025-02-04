// Desarrolle un algoritmo para el cálculo del salario de un trabajador. El importe
// liquidado (sueldo) depende de una tarifa o precio por hora establecida y de un condicionante
// sobre las horas trabajadas: si la cantidad de horas trabajadas es mayor a 40 horas,
// la tarifa se incrementa en un 50% para las horas extras. Calcular el sueldo recibido
// por el trabajador en base las horas trabajadas y la tarifa. Utilice las instrucciones
// LEER HORASTRABAJADAS y LEER TARIFA al inicio del programa para cargar los valores en las
// variables HORASTRABAJADAS y TARIFA.

#include <iostream>

float leer_horas_trabajadas() {
    float horas_trabajadas;
    bool horas_trabajadas_obtenidas = false;
    
    do {
        std::cout << "Introduce las horas trabajadas: " << std::endl;
        std::cin >> horas_trabajadas;
        if (std::cin.fail() || horas_trabajadas < 0){
            std::cout << "Horas trabajadas inválidas" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else {
            horas_trabajadas_obtenidas = true;
        }
    } while (!horas_trabajadas_obtenidas);
    
    return horas_trabajadas;
}

float leer_tarifa() {
    float tarifa;
    bool tarifa_obtenida = false;
    
    do {
        std::cout << "Introduce la tarifa: " << std::endl;
        std::cin >> tarifa;
        if (std::cin.fail() || tarifa < 0){
            std::cout << "Tarifa inválida" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else {
            tarifa_obtenida = true;
        }
    } while (!tarifa_obtenida);
    
    return tarifa;
}


int main() {
    float horas_trabajadas = leer_horas_trabajadas();
    float tarifa = leer_tarifa();
    float sueldo;
    
    if (horas_trabajadas <= 40) {
        sueldo = horas_trabajadas * tarifa;
    }
    else {
        sueldo = 40 * tarifa;
        sueldo += (horas_trabajadas - 40) * (tarifa + (tarifa*0.50));
    }
    
    std::cout << "Sueldo: " << sueldo << "€" << std::endl;
}