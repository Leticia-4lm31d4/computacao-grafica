/**
 * @file main.cpp
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Arquivo para realização dos testes unitários das classes de matrizes
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// classes mat2, mat3 e mat4 
#include "mat2.h" 
#include "mat3.h" 
#include "mat4.h" 

#include <iostream>

int main() {

    std::cout << "TESTES UNITÁRIOS MATRIZES\n" << std::endl;

    mat2 matrix2(1.0, 2.0, 
                 3.0, 4.0);

    mat3 matrix3(1.0, 2.0, 3.0, 
                 4.0, 5.0, 6.0,
                 7.0, 8.0, 9.0);

    mat4 matrix4(1.0, 2.0, 3.0, 4.0,
                 4.0, 5.0, 6.0, 7.0,
                 0.0, 8.0, 9.0, 3.0,
                 2.0, 6.0, 1.0, 5.0);

    std::cout << "Matriz 2x2:\n";
    std::cout << matrix2;

    std::cout << "\n"<< std::endl;

    std::cout << "Matriz 3x3:\n";
    std::cout << matrix3;

    std::cout << "\n"<< std::endl;

    std::cout << "Matriz 4x4:\n";
    std::cout << matrix4;

    // Inicio teste M2x2

    // Inicio teste M3x3

    // Inicio teste M4x4

    std::cout << "\nFim dos testes unitarios!  \n"<< std::endl;
    return 0;
}

// g++ -o mat.exe matrizes.cpp mat2.h mat3.h mat4.h