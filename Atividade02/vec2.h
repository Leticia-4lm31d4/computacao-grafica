/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classe para manipulação de vetores com duas componentes (x,y)
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt; 

class vec2 {
  public:
    double e[2]; // Vetor (x, y).

    vec2() : e{0, 0} {}

    vec2(double e0, double e1) : e{e0, e1} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }

    vec2 operator-() const { return vec2(-e[0], -e[1]); }

    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec2& operator+=(const vec2 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    vec2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    vec2& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1];
    }
};

// Funções globais para as classes

// Imprimir

    inline std::ostream& operator<<(std::ostream &out, const vec2 &v) {
        return out << v.e[0] << ' ' << v.e[1];
    }

// 1.Soma de dois vetores iguais (vecN + vecN)

    inline vec2 operator+(const vec2 &u, const vec2 &v) {
        return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
    }

// 2.Subtraição de dois vetores iguais (vecN - vecN)

    inline vec2 operator-(const vec2 &u, const vec2 &v) {
        return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
    }

// 3.Produto de vetores

    inline vec2 operator*(const vec2 &u, const vec2 &v) {
        return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
    }

// 4.Multiplicação de um vetor por um escalar

    inline vec2 operator*(const vec2 &v, double t) {
        return vec2(v.e[0] * t, v.e[1] * t);
    }

// 5.Multiplicação de um escalar por um vetor

    inline vec2 operator*(double t, const vec2 &v) {
        return v * t;
    }

// 6.Dividisão de um vetor por um escalar

    inline vec2 operator/(const vec2 &v, double t) {
        return (1/t) * v;
    }

// 7.Produto escalar de dois vetores

    inline double dot(const vec2 &u, const vec2 &v) {
        return u.e[0] * v.e[0] + u.e[1] * v.e[1];
    }

// 8.Normalização de um vetor

    inline vec2 unit_vector(const vec2 &v) {
        return v / v.length();
    }

#endif