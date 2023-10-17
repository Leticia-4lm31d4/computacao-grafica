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

    // Construtores
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

    // Acessar elementos
    double operator()(int i, int j) const {
        return e[i][j];
    }
    // Acessar e Modificar elementos
    double& operator()(int i, int j) {
        return e[i][j];
    }

    // Negar os valores
    mat4 operator-() const {
        return mat4(-e[0][0], -e[0][1], -e[0][2], -e[0][3],
                    -e[1][0], -e[1][1], -e[1][2], -e[1][3],
                    -e[2][0], -e[2][1], -e[2][2], -e[2][3],
                    -e[3][0], -e[3][1], -e[3][2], -e[3][3]);
    }

    // Adição
    mat4& operator+=(const mat4 &m) {
        e[0][0] += m.e[0][0]; 
        e[0][1] += m.e[0][1];
        e[0][2] += m.e[0][2];
        e[0][3] += m.e[0][3];
        e[1][0] += m.e[1][0];
        e[1][1] += m.e[1][1];
        e[1][2] += m.e[1][2];
        e[1][3] += m.e[1][3];
        e[2][0] += m.e[2][0];
        e[2][1] += m.e[2][1];
        e[2][2] += m.e[2][2];
        e[2][3] += m.e[2][3];
        e[3][0] += m.e[3][0];
        e[3][1] += m.e[3][1];
        e[3][2] += m.e[3][2];
        e[3][3] += m.e[3][3];
        return *this;
    }

    // Multiplicação
    mat4& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[0][2] *= t;
        e[0][3] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        e[1][2] *= t;
        e[1][3] *= t;
        e[2][0] *= t;
        e[2][1] *= t;
        e[2][2] *= t;
        e[2][3] *= t;
        e[3][0] *= t;
        e[3][1] *= t;
        e[3][2] *= t;
        e[3][3] *= t;
        return *this;
    }

    // Divisão
    mat4& operator/=(double t) {
        return *this *= 1 / t;
    }

};

// Imprimir
    inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                out << m.e[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }

// 1. Soma A + B
inline mat4 operator+(const mat4 &A, const mat4 &B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = A(i, j) + B(i, j);
        }
    }
    return result;
}

// 2. Subtração A - B
inline mat4 operator-(const mat4 &A, const mat4 &B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = A(i, j) - B(i, j);
        }
    }
    return result;
}

// 3. Produto de Matrizes (A * B)
inline mat4 operator*(const mat4 &A, const mat4 &B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = A(i, 0) * B(0, j) + 
                           A(i, 1) * B(1, j) + 
                           A(i, 2) * B(2, j) +
                           A(i, 3) * B(3, j);
        }
    }
    return result;
}

// 4. Multiplicação (escalar * matriz) (t * A)
inline mat4 operator*(double t, const mat4 &A) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = t * A(i, j);
        }
    }
    return result;
}

// 5. Multiplicação (matriz * escalar) (A * t)
inline mat4 operator*(const mat4 &A, double t) {
    return t * A; // chama a função de (escalar * matriz)
}

// 6. Divisão (matriz / t)
inline mat4 operator/(const mat4 &A, double t) {
    return (1 / t) * A;
}

// 7. Produto escalar entre duas matrizes 
inline double dot(const mat4 &A, const mat4 &B) {
    double result = 0.0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result += A(i, j) * B(i, j);
        }
    }
    return result;
}

#endif
