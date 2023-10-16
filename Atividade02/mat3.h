/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classe para manipulação de matrizes 3x3
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#ifndef MAT3_H
#define MAT3_H

#include <iostream>

class mat3 {
public:
    double e[3][3]; // Matriz 3x3

    // Construtores
    mat3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                e[i][j] = 0;
            }
        }
    }

    mat3(double e00, double e01, double e02,
         double e10, double e11, double e12,
         double e20, double e21, double e22) {
        e[0][0] = e00;
        e[0][1] = e01;
        e[0][2] = e02;
        e[1][0] = e10;
        e[1][1] = e11;
        e[1][2] = e12;
        e[2][0] = e20;
        e[2][1] = e21;
        e[2][2] = e22;
    }

    // Função para acessar elementos
    double operator()(int i, int j) const {
        return e[i][j];
    }

    double& operator()(int i, int j) {
        return e[i][j];
    }

};

// Função global para imprimir a matriz 3x3

    inline std::ostream& operator<<(std::ostream& out, const mat3& m) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                out << m.e[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }

#endif
