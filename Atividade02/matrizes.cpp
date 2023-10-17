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

    std::cout << "TESTES UNITÁRIOS MATRIZES" << std::endl;
    std::cout << "> matrizes.cpp\n" << std::endl;

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

    mat2 sum2(4.0, 5.0, 
              5.0, 9.0);
    mat3 sum3(2.0, 8.0, 10.0, 
              6.0, 6.0, 14.0,
              10.0, 12.0, 10.0);
    mat4 sum4(2.0, 4.0, 4.0, 6.0,
              6.0, 6.0, 8.0, 8.0,
              2.0, 10.0, 10.0, 5.0,
              4.0, 7.0, 3.0, 6.0);

    if(igual_mat2(sum2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(sum3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(sum4, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Subtração de Matrizes
    std::cout << "SUBTRAÇÃO: A - B\n";

    result2 = matrix2a - matrix2b;
    result3 = matrix3a - matrix3b;
    result4 = matrix4a - matrix4b;

    mat2 sub2(-2.0, -1.0, 1.0, -1.0);
    mat3 sub3(0.0, -4.0, -4.0, 
              2.0, 4.0, -2.0,
              4.0, 4.0, 8.0);
    mat4 sub4(0.0, 0.0, 2.0, 2.0,
              2.0, 4.0, 4.0, 6.0,
              0.0, 6.0, 8.0, 1.0,
              0.0, 5.0, -1.0, 4.0);

    if(igual_mat2(sub2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(sub3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(sub4, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Produto de Matrizes
    std::cout << "PRODUTO: A * B\n";

    result2 = matrix2a * matrix2b;
    result3 = matrix3a * matrix3b;
    result4 = matrix4a * matrix4b;

    mat2 p2(7.0, 13.0, 
            17.0, 29.0);
    mat3 p3(14.0, 20.0, 26.0, 
            32.0, 53.0, 74.0,
            50.0, 86.0, 122.0);
    mat4 p4(16.0, 14.0, 16.0, 14.0,
            34.0, 32.0, 34.0, 32.0,
            32.0, 31.0, 32.0, 31.0,
            25.0, 17.0, 25.0, 17.0);

    if(igual_mat2(p2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(p3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(p4, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Produto de um escalar com matriz
    std::cout << "PRODUTO: n° * A\n";

    result2 = 3 * matrix2a;
    result3 = 4 * matrix3a;
    result4 = 2 * matrix4a;

    mat2 nA2(3.0, 6.0, 
             9.0, 12.0);
    mat3 nA3(4.0,  8.0,  12.0, 
             16.0, 20.0, 24.0,
             28.0, 32.0, 36.0);
    mat4 nA4(2.0, 4.0,  6.0,  8.0,
             8.0, 10.0, 12.0, 14.0,
             2.0, 16.0, 18.0, 6.0,
             4.0, 12.0, 2.0,  10.0);

    if(igual_mat2(nA2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(nA3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(nA4, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Produto de uma matriz com um escalar 
    std::cout << "PRODUTO: A * n°\n";

    result2 = matrix2a * 3;
    result3 = matrix3a * 4;
    result4 = matrix4a * 2;

    mat2 An2(3.0, 6.0, 
             9.0, 12.0);
    mat3 An3(4.0,  8.0,  12.0, 
             16.0, 20.0, 24.0,
             28.0, 32.0, 36.0);
    mat4 An4(2.0, 4.0,  6.0,  8.0,
             8.0, 10.0, 12.0, 14.0,
             2.0, 16.0, 18.0, 6.0,
             4.0, 12.0, 2.0,  10.0);

    if(igual_mat2(An2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(An3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(An4, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Divisão matriz com escalar
    std::cout << "DIVISÃO: A / n°\n";

    result2 = matrix2a / 0.5;
    result3 = matrix3a / 2;
    result4 = matrix4a / 1;

    mat2 d2(2.0, 4.0, 
            6.0, 8.0);
    mat3 d3(0.5, 1.0, 1.5, 
            2.0, 2.5, 3.0,
            3.5, 4.0, 4.5);

    if(igual_mat2(d2, result2)){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(igual_mat3(d3, result3)){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
    }

    if(igual_mat4(matrix4a, result4)){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }

    std::cout << "\n"<< std::endl;

    // Produto escalar de duas matrizes
    std::cout << "PRODUTO ESCALAR: A X B\n";

    double res2 = dot(matrix2a, matrix2b);
    double res3 = dot(matrix3a, matrix3b);
    double res4 = dot(matrix4a, matrix4b);

    if(res2 == 35.0){
        std::cout << "2x2 | ok." << std::endl;
    } else {
        std::cout << "2x2 | erro." << std::endl;
    }

    if(res3 == 157.0){
        std::cout << "3x3 | ok." << std::endl;
    } else {
        std::cout << "3x3 | erro." << std::endl;
        std::cout << res3 << std::endl;
    }

    if(res4 == 97.0){
        std::cout << "4x4 | ok." << std::endl;
    } else {
        std::cout << "4x4 | erro." << std::endl;
    }


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