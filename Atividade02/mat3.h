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

    // Acessar elementos
    double operator()(int i, int j) const {
        return e[i][j];
    }
    // Acessar e modificar elementos
    double& operator()(int i, int j) {
        return e[i][j];
    }

    // Negar os valores
    mat3 operator-() const {
        return mat2(-e[0][0], -e[0][1], -e[0][2], 
                    -e[1][0], -e[1][1], -e[1][2],
                    -e[2][0], -e[2][1], -e[2][2]);
    }

    // Adição
    mat3& operator+=(const mat3 &m) {
        e[0][0] += m.e[0][0];
        e[0][1] += m.e[0][1];
        e[0][2] += m.e[0][2];
        e[1][0] += m.e[1][0];
        e[1][1] += m.e[1][1];
        e[1][2] += m.e[1][2];
        e[2][0] += m.e[2][0];
        e[2][1] += m.e[2][1];
        e[2][2] += m.e[2][2];
        return *this;
    }

    // Multiplicação
    mat3& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[0][2] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        e[1][2] *= t;
        e[2][0] *= t;
        e[2][1] *= t;
        e[2][2] *= t;
        return *this;
    }

    // Divisão
    mat3& operator/=(double t) {
        return *this *= 1 / t;
    }

};

// Imprimir
    inline std::ostream& operator<<(std::ostream& out, const mat3& m) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                out << m.e[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }

// 1. Soma
inline mat3 operator+(const mat2 &A, const mat2 &B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result(i, j) = A(i, j) + B(i, j);
        }
    }
    return result;
}

// 2. Subtração
inline mat3 operator-(const mat3 &A, const mat3 &B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result(i, j) = A(i, j) - B(i, j);
        }
    }
    return result;
}

// 3. Produto de matrizes
inline mat3 operator*(const mat3 &A, const mat3 &B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result(i, j) = A(i, 0) * B(0, j) + A(i, 1) * B(1, j) + A(i, 2) * B(2, j);
        }
    }
    return result;
}

// 4. Multiplicação (escalar x matriz)
inline mat3 operator*(double t, const mat3 &A) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result(i, j) = t * A(i, j);
        }
    }
    return result;
}

// 5. Multiplicação (matriz x escalar)
inline mat3 operator*(const mat3 &A, double t) {
    return t * A;
}

// 6. Divisão (matriz / escalar)
inline mat3 operator/(const mat3 &A, double t) {
    return (1 / t) * A;
}

// Produto escalar entre duas matrizes
inline double dot(const mat3 &A, const mat3 &B) {
    double result = 0.0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result += A(i, j) * B(i, j);
        }
    }
    return result;
}

#endif
