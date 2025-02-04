// Escriba un algoritmo que visualice una clasificación de 50 personas según edad y sexo. Deberá mostrar los siguientes resultados:
// ⦁	Cantidad de personas mayores de edad (18 años o más).
// ⦁	Cantidad de personas menores de edad.
// ⦁	Cantidad de personas masculinas mayores de edad.
// ⦁	Cantidad de personas femeninas menores de edad.
// ⦁	Porcentaje que representan las personas mayores de edad respecto al total de personas.
// ⦁	Porcentaje que representan las mujeres respecto al total de personas.

// Utilice la instrucción LEER PERSONAS al inicio del programa para cargar los datos de las 50 personas en un variable, PERSONAS, que actúa como un vector de 50 posiciones.
// Cada elemento de PERSONAS es de un tipo estructurado que dispone dos campos:
// SEXO y EDAD.

#include <iostream>
#include <vector>

enum Sexo {
    Masculino,
    Femenino
};

struct Persona {
  Sexo sexo;
  int edad;
};


std::vector<Persona> leer_personas(int num_personas) {
    std::vector<Persona> personas;
    
    while (personas.size() < num_personas) {
        std::string sexo_s;
        Sexo sexo;
        bool sexo_obtenido = false;
        do {
            std::cout << "Introduce el sexo de la persona: " + std::to_string(personas.size() + 1) + ": " << std::endl;
            std::cin >> sexo_s;
            if (std::cin.fail())  {
                std::cout << "Sexo inválido" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (sexo_s == "Masculino") {
                sexo = Masculino;
                sexo_obtenido = true;
            } else if (sexo_s == "Femenino") {
                sexo = Femenino;
                sexo_obtenido = true;
            } else {
                std::cout << "Sexo inválido\n";
            }
        } while (!sexo_obtenido);
        
        int edad;
        bool edad_obenida = false;
        do {
            std::cout << "Introduce la edad de la persona: " + std::to_string(personas.size() + 1) + ": " << std::endl;
            std::cin >> edad;
            if (std::cin.fail()){
                std::cout << "Edad inválida" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (0 < edad && edad < 120) {
                edad_obenida = true;
            }
        } while (!edad_obenida);
        
        
        Persona persona;
        persona.sexo = sexo;
        persona.edad = edad;
        personas.push_back(persona);
    }
    
    return personas;
}

void mostrar_resultados(const std::vector<Persona>& personas) {
    int mayores = 0;
    int hombres_mayores = 0;
    int mujeres_menores = 0;
    int mujeres = 0;

    for (int i = 0; i < personas.size(); ++i) {
        if (personas[i].edad >= 18) {
            ++mayores;
            if (personas[i].sexo == Masculino) {
                ++hombres_mayores;
            }
        } else {
            if (personas[i].sexo == Femenino) {
                ++mujeres_menores;
            }
        }
        
        if (personas[i].sexo == Femenino) {
            ++mujeres;
        }
    }
    
    std::cout << "Cantidad de personas mayores de edad (18 años o más): " << mayores << std::endl;
    std::cout << "Cantidad de personas menores de edad: " << personas.size() - mayores << std::endl;
    std::cout << "Cantidad de personas masculinas mayores de edad: " << hombres_mayores << std::endl;
    std::cout << "Cantidad de personas femeninas menores de edad: " << mujeres_menores << std::endl;
    std::cout << "Porcentaje que representan las personas mayores de edad respecto al total de personas: " << (double)mayores / personas.size() * 100 << "%" << std::endl;
    std::cout << "Porcentaje que representan las mujeres respecto al total de personas: " << (double)mujeres/personas.size() * 100 << "%" << std::endl;
}


int main() {
    std::vector<Persona> personas = leer_personas(50);
    mostrar_resultados(personas);
}