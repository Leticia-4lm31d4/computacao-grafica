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

    mat2 matrix2a(1.0, 2.0, 
                  3.0, 4.0);

    mat2 matrix2b(3.0, 3.0, 
                  2.0, 5.0);

    mat3 matrix3a(1.0, 2.0, 3.0, 
                  4.0, 5.0, 6.0,
                  7.0, 8.0, 9.0);

    mat3 matrix3b(1.0, 6.0, 7.0, 
                  2.0, 1.0, 8.0,
                  3.0, 4.0, 1.0);

    mat4 matrix4a(1.0, 2.0, 3.0, 4.0,
                  4.0, 5.0, 6.0, 7.0,
                  1.0, 8.0, 9.0, 3.0,
                  2.0, 6.0, 1.0, 5.0);

    mat4 matrix4b(1.0, 2.0, 1.0, 2.0,
                  2.0, 1.0, 2.0, 1.0,
                  1.0, 2.0, 1.0, 2.0,
                  2.0, 1.0, 2.0, 1.0);

    std::cout << "Matriz 2x2: A\n";
    std::cout << matrix2a;
    std::cout << "\nMatriz 2x2: B\n";
    std::cout << matrix2b;

    std::cout << "\n"<< std::endl;

    std::cout << "Matriz 3x3: A\n";
    std::cout << matrix3a;
    std::cout << "\nMatriz 3x3: B\n";
    std::cout << matrix3b;

    std::cout << "\n"<< std::endl;

    std::cout << "Matriz 4x4: A\n";
    std::cout << matrix4a;
    std::cout << "\nMatriz 4x4: B\n";
    std::cout << matrix4b;

    // Negação dos valores
    std::cout << "\nVALORES NEGATIVOS\n";

    std::cout << "\n"<< std::endl;

    // Soma de Matrizes
    std::cout << "SOMA: A + B\n";

    std::cout << "\n"<< std::endl;

    // Subtração de Matrizes
    std::cout << "SUBTRAÇÃO: A - B\n";

    std::cout << "\n"<< std::endl;

    // Produto de Matrizes
    std::cout << "PRODUTO: A * B\n";

    std::cout << "\n"<< std::endl;


    std::cout << "\nFim dos testes unitarios!  \n"<< std::endl;
    return 0;
}

// g++ -o mat.exe matrizes.cpp mat2.h mat3.h mat4.h