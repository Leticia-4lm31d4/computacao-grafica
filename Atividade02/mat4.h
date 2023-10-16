/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classe para manipulação de matrizes 4x4
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAT4_H
#define MAT4_H

#include <iostream>

class mat4 {
public:
    double e[4][4]; // Matriz 4x4

    mat4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                e[i][j] = 0;
            }
        }
    }

    mat4(double e00, double e01, double e02, double e03,
         double e10, double e11, double e12, double e13,
         double e20, double e21, double e22, double e23,
         double e30, double e31, double e32, double e33) {
        e[0][0] = e00;
        e[0][1] = e01;
        e[0][2] = e02;
        e[0][3] = e03;
        e[1][0] = e10;
        e[1][1] = e11;
        e[1][2] = e12;
        e[1][3] = e13;
        e[2][0] = e20;
        e[2][1] = e21;
        e[2][2] = e22;
        e[2][3] = e23;
        e[3][0] = e30;
        e[3][1] = e31;
        e[3][2] = e32;
        e[3][3] = e33;
    }

    // Função para acessar elementos
    double operator()(int i, int j) const {
        return e[i][j];
    }

    double& operator()(int i, int j) {
        return e[i][j];
    }

};

// Função global para imprimir a matriz 4x4
    inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                out << m.e[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }

#endif
