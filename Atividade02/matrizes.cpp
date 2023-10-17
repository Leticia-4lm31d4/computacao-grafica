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

bool igual_mat2(const mat2 &A, const mat2 &B);
bool igual_mat3(const mat3 &A, const mat3 &B);
bool igual_mat4(const mat4 &A, const mat4 &B);

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
    std::cout << "\nVALORES PASSADOS PARA NEGATIVOS\n";

    std::cout << -matrix2a;
    std::cout << " "<< std::endl;
    std::cout << -matrix3a;
    std::cout << " "<< std::endl;
    std::cout << -matrix4a;
    std::cout << " "<< std::endl;

    // Soma de Matrizes
    std::cout << "SOMA: A + B\n";

    mat2 result2 = matrix2a + matrix2b;
    mat3 result3 = matrix3a + matrix3b;
    mat4 result4 = matrix4a + matrix4b;

    mat2 sum2(1.0, 2.0, 
              3.0, 4.0);
    mat3 sum3(1.0, 6.0, 7.0, 
              2.0, 1.0, 8.0,
              3.0, 4.0, 1.0);
    mat4 sum4(1.0, 2.0, 1.0, 2.0,
              2.0, 1.0, 2.0, 1.0,
              1.0, 2.0, 1.0, 2.0,
              2.0, 1.0, 2.0, 1.0);

    if(igual_mat2(sum2, result2)){
        std::cout << "2 | ok." << std::endl;
    } else {
        std::cout << "2 | erro." << std::endl;
    }

    if(igual_mat3(sum3, result3)){
        std::cout << "3 | ok." << std::endl;
    } else {
        std::cout << "3 | erro." << std::endl;
    }

    if(igual_mat4(sum4, result4)){
        std::cout << "4 | ok." << std::endl;
    } else {
        std::cout << "4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Subtração de Matrizes
    std::cout << "SUBTRAÇÃO: A - B\n";

    result2 = matrix2a + matrix2b;
    result3 = matrix3a + matrix3b;
    result4 = matrix4a + matrix4b;

    mat2 sub2(1.0, 2.0, 3.0, 4.0);
    mat3 sub3(1.0, 6.0, 7.0, 
         2.0, 1.0, 8.0,
         3.0, 4.0, 1.0);
    mat4 sub4(1.0, 2.0, 1.0, 2.0,
         2.0, 1.0, 2.0, 1.0,
         1.0, 2.0, 1.0, 2.0,
         2.0, 1.0, 2.0, 1.0);

    if(igual_mat2(sub2, result2)){
        std::cout << "2 | ok." << std::endl;
    } else {
        std::cout << "2 | erro." << std::endl;
    }

    if(igual_mat3(sub3, result3)){
        std::cout << "3 | ok." << std::endl;
    } else {
        std::cout << "3 | erro." << std::endl;
    }

    if(igual_mat4(sub4, result4)){
        std::cout << "4 | ok." << std::endl;
    } else {
        std::cout << "4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Produto de Matrizes
    std::cout << "PRODUTO: A * B\n";

    result2 = matrix2a + matrix2b;
    result3 = matrix3a + matrix3b;
    result4 = matrix4a + matrix4b;

    mat2 p2(1.0, 2.0, 
         3.0, 4.0);
    mat3 p3(1.0, 6.0, 7.0, 
         2.0, 1.0, 8.0,
         3.0, 4.0, 1.0);
    mat4 p4(1.0, 2.0, 1.0, 2.0,
         2.0, 1.0, 2.0, 1.0,
         1.0, 2.0, 1.0, 2.0,
         2.0, 1.0, 2.0, 1.0);

    if(igual_mat2(p2, result2)){
        std::cout << "2 | ok." << std::endl;
    } else {
        std::cout << "2 | erro." << std::endl;
    }

    if(igual_mat3(p3, result3)){
        std::cout << "3 | ok." << std::endl;
    } else {
        std::cout << "3 | erro." << std::endl;
    }

    if(igual_mat4(p4, result4)){
        std::cout << "4 | ok." << std::endl;
    } else {
        std::cout << "4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;


    std::cout << "\nFim dos testes unitarios!  \n"<< std::endl;
    return 0;
}

// Função para verificar se duas matrizes mat2 são iguais
bool igual_mat2(const mat2 &A, const mat2 &B) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (A.e[i][j] != B.e[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool igual_mat3(const mat3 &A, const mat3 &B) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A.e[i][j] != B.e[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool igual_mat4(const mat4 &A, const mat4 &B) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A.e[i][j] != B.e[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// g++ -o mat.exe matrizes.cpp mat2.h mat3.h mat4.h