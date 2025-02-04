// Escriba un algoritmo que lea un número entero y determine si es par o impar.
// Si es par, que escriba todos los pares de manera descendiente desde sí mismo y
// hasta el cero. Si es impar, que escriba todos los impares de manera descendiente 
// desde si sí mismo hasta el uno. Utilice la instrucción LEER NUMERO al inicio del
// programa para cargar un número en la variable NUMERO.

#include <iostream>

int leer_numero() {
    int numero;
    bool numero_obtenido = false;
    do {
        std::cout << "Introduce un entero: ";
        std::cin >> numero;
        if (std::cin.fail())  {
            std::cout << "Input inválido" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else {
            numero_obtenido = true;
        }
    } while (!numero_obtenido);
    
    return numero;
}



int main() {
    int numero = leer_numero();
    
    while (numero >= 0){
        std::cout << numero << std::endl;
        numero -= 2;
    }
}