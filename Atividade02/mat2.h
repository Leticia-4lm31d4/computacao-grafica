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
    // Acessar e modificar elementos
    double& operator()(int i, int j) {
        return e[i][j];
    }

    /**
    * @brief Operador de negação para inverter os componentes, alterando o sinal dos elementos da matriz.
    * @return mat2
    */
    mat2 operator-() const {
        return mat2(-e[0][0], -e[0][1], -e[1][0], -e[1][1]);
    }

    /**
    * @brief Operações de adição com outra matriz 2x2.
    * @param m Uma matriz 2x2 com valores a serem adicionados a esta matriz.
    * @return mat2x2& // Matriz resultante.
    */
    mat2& operator+=(const mat2 &m) {
        e[0][0] += m.e[0][0];
        e[0][1] += m.e[0][1];
        e[1][0] += m.e[1][0];
        e[1][1] += m.e[1][1];
        return *this;
    }

    /**
    * @brief Operações de multiplicação por um escalar.
    * @param t O fator da multiplicação.
    * @return mat2& // Matriz resultante.
    */
    mat2& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        return *this;
    }

    /**
    * @brief Operações de divisão por um escalar.
    * @param t O divisor.
    * @return mat2& // Matriz resultante.
    */
    mat2& operator/=(double t) {
        return *this *= 1 / t;
    }

};
// Funções globais para as classes

// Imprimir a matriz
    inline std::ostream& operator<<(std::ostream& out, const mat2& m) {
        out << m.e[0][0] << ' ' << m.e[0][1] << '\n';
        out << m.e[1][0] << ' ' << m.e[1][1] << '\n';
        return out;
    }

// 1. Soma de matrizes
inline mat2 operator+(const mat2 &A, const mat2 &B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result(i, j) = A(i, j) + B(i, j);
        }
    }
    return result;
}

// 2. Subtração de matrizes
inline mat2 operator-(const mat2 &A, const mat2 &B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result(i, j) = A(i, j) - B(i, j);
        }
    }
    return result;
}

// 3. Produto de matrizes
inline mat2 operator*(const mat2 &A, const mat2 &B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result(i, j) = A(i, 0) * B(0, j) + A(i, 1) * B(1, j);
        }
    }
    return result;
}

// 4. Multiplicação de um escalar por uma matriz
inline mat2 operator*(double t, const mat2 &A) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result(i, j) = t * A(i, j);
        }
    }
    return result;
}

// 5. Multiplicação de uma matriz por um escalar
inline mat2 operator*(const mat2 &A, double t) {
    return t * A;
}

// 6. Divisão de uma matriz por um escalar
inline mat2 operator/(const mat2 &A, double t) {
    return (1 / t) * A;
}

// 7. Produto escalar de duas matrizes
inline double dot(const mat2 &A, const mat2 &B) {
    double result = 0.0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result += A(i, j) * B(i, j);
        }
    }
    return result;
}

#endif