/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classe para manipulação de matrizes 2x2 
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#ifndef MAT2_H
#define MAT2_H

#include <iostream>

class mat2 {
public:
    double e[2][2]; // Matriz 2x2

    // Construtores
    mat2() {
        e[0][0] = 0;
        e[0][1] = 0;
        e[1][0] = 0;
        e[1][1] = 0;
    }

    mat2(double e00, double e01, double e10, double e11) {
        e[0][0] = e00;
        e[0][1] = e01;
        e[1][0] = e10;
        e[1][1] = e11;
    }

    // Acessar elementos
    double operator()(int i, int j) const {
        return e[i][j];
    }

    double& operator()(int i, int j) {
        return e[i][j];
    }

};

// Imprimir a matriz
    inline std::ostream& operator<<(std::ostream& out, const mat2& m) {
        out << m.e[0][0] << ' ' << m.e[0][1] << '\n';
        out << m.e[1][0] << ' ' << m.e[1][1] << '\n';
        return out;
    }

#endif