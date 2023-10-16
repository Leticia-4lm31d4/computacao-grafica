/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classe para manipulação de vetores com 4 campos (x,y,z,w)
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt; 

class vec4 {
public:
    double e[4]; // Vetor quaternário (x, y, z, w).

    vec4() : e{0, 0, 0, 0} {}

    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    // Acessar as componentes
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    double w() const { return e[3]; }

    // Operador de negação para inverter os componentes
    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }

    // Sobrecarga dos operadores para acesso aos elementos
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec4& operator+=(const vec4 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    vec4& operator/=(double t) {
        return *this *= 1.0 / t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }

};


// Funções globais para as classes

// Imprimir

    inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
    }

// 1.Soma 

    inline vec4 operator+(const vec4 &u, const vec4 &v) {
        return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
    }

// 2.Subtraição 

    inline vec4 operator-(const vec4 &u, const vec4 &v) {
        return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
    }

// 3.Produto de vetores

    inline vec4 operator*(const vec4 &u, const vec4 &v) {
        return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
    }

// 3. Multiplicação de um vetor por um escalar
    
    inline vec4 operator*(const vec4 &v, double t) {
        return vec4(v.e[0] * t, v.e[1] * t, v.e[2] * t, v.e[3] * t);
    }

// 4. Multiplicação de um escalar por um vetor

    inline vec4 operator*(double t, const vec4 &v) {
        return v * t;
    }

// 5.Divisão 

    inline vec4 operator/(const vec4 &v, double t) {
        return (1/t) * v;
    }

// 6. Produto escalar 

    inline double dot(const vec4 &u, const vec4 &v) {
        return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2] + u.e[3] * v.e[3];
    }   

// 7. Normalização

    inline vec4 unit_vector(const vec4 &v) {
        return v / v.length();
    }

#endif