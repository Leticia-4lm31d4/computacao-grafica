/**
 * @file main.cpp
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Arquivo para realização dos testes unitários das classes de vetores
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// classes vec2, vec3 e vec4 
#include "vec2.h" 
#include "vec3.h" 
#include "vec4.h" 

#include <iostream>

int main() {

    std::cout << "TESTES UNITÁRIOS VETORES\n" << std::endl;

    vec2 vet2(1.0, 3.0);
    vec3 vet3(2.0, 1.0, 1.5);
    vec4 vet4(4.0, 0.0, 5.0, 1.0);

    std::cout << "Vetor (x, y):\n";
    std::cout << vet2;

    std::cout << "\n"<< std::endl;

    std::cout << "Vetor (x, y, z):\n";
    std::cout << vet3;

    std::cout << "\n"<< std::endl;

    std::cout << "Vetor (x, y, z, w):\n";
    std::cout << vet4;

    std::cout << "\n\nFim dos testes unitarios!  \n"<< std::endl;
    return 0;
}

// g++ -o vet.exe vetores.cpp vec2.h vec3.h vec4.h  