/**
 * @file vector.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Classes para representar vetores (vec3, vec2, vec4) e suas operações.
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

using std::sqrt; 

class vec2 {
  public:
    double e[2]; // Vetor bidimensional (x, y).

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

class vec3 {
  public:
    /** 
     * @brief vetor de 3 elementos para armazenar as coordenadas tridimensionais (x,y,z)
     */
    double e[3]; 

    /**
     * @brief Construtor de um objeto tridimensional que inicializa o vetor com todas as componentes iguais a zero;
     */
    vec3() : e{0,0,0} {}

    /**
     * @brief Outro construtor de um objeto tridimensional, este permite especificar os valores iniciais das componentes.
     * @param e0 valor de x
     * @param e1 valor de y
     * @param e2 valor de z
     */
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    /**
     * @brief Funções que permitem acessar as componentes x,y,z do vetor.
     * @return double 
     */
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
 
    /**
     * @brief Operador de negação para inverter os componentes, alterando o sinal de x,y,z.
     * @return vec3 
     */
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    /**
     * @brief Sobrecarga dos operadores para acesso aos elementos.
     * @param i índice do elemento que quer acessar.
     * @return double 
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Sobrecarga dos operadores para acesso e modificação dos elementos.
     * @param i índice do elemento que quer acessar.
     * @return double&  // o '&' permite acesso e mudança direta ao valor do elemento no índice i
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Permitem realizar operações de adição.
     * @param v um vetor tridimensional com valores a serem adicionados a outro vetor.
     * @return vec3& // vetor resultante
     */
    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /**
     * @brief Permitem realizar operações de multiplicação por um escalar.
     * @param t o fator da multiplicação
     * @return vec3& // vetor resultante
     */
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /**
     * @brief Permitem realizar operações de divisão por um escalar.
     * @param t o divisor
     * @return vec3& // vetor resultante
     */
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    /**
     * @brief Calcular o comprimento do vetor
     * @return double 
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Calcular o comprimento do vetor ao quadrado
     * @return double 
     */
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

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

    inline std::ostream& operator<<(std::ostream &out, const vec2 &v) {
        return out << v.e[0] << ' ' << v.e[1];
    }

    inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
    }

// Soma de dois vetores iguais (vecN + vecN)

    inline vec2 operator+(const vec2 &u, const vec2 &v) {
        return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
    }

    inline vec3 operator+(const vec3 &u, const vec3 &v) {
        return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    inline vec4 operator+(const vec4 &u, const vec4 &v) {
        return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
    }

// Subtraição de dois vetores iguais (vecN - vecN)

    inline vec2 operator-(const vec2 &u, const vec2 &v) {
        return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
    }

    inline vec3 operator-(const vec3 &u, const vec3 &v) {
        return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    inline vec4 operator-(const vec4 &u, const vec4 &v) {
        return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
    }

// Multiplicação de um vetor por um escalar

    inline vec2 operator*(const vec2 &v, double t) {
        return vec2(v.e[0] * t, v.e[1] * t);
    }

    inline vec3 operator*(const vec3 &v, double t) {
        return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
    }

    inline vec4 operator*(const vec4 &v, double t) {
        return vec4(v.e[0] * t, v.e[1] * t, v.e[2] * t, v.e[3] * t);
    }

// Multiplicação de um escalar por um vetor

    inline vec2 operator*(double t, const vec2 &v) {
        return v * t;
    }

    inline vec3 operator*(double t, const vec3 &v) {
        return v * t;
    }

    inline vec4 operator*(double t, const vec4 &v) {
        return v * t;
    }

// Dividisão de um vetor por um escalar

    inline vec2 operator/(const vec2 &v, double t) {
        return (1/t) * v;
    }

    inline vec3 operator/(const vec3 &v, double t) {
        return (1/t) * v;
    }

    inline vec4 operator/(const vec4 &v, double t) {
        return (1/t) * v;
    }

// Calcular o produto escalar de dois vetores (vecN, vecN)

    inline double dot(const vec2 &u, const vec2 &v) {
        return u.e[0] * v.e[0] + u.e[1] * v.e[1];
    }

    inline double dot(const vec3 &u, const vec3 &v) {
        return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
    }

    inline double dot(const vec4 &u, const vec4 &v) {
        return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2] + u.e[3] * v.e[3];
    }   

// Calcular o produto vetorial de dois vec3
/* O produto vetorial é uma operação específica para vetores tridimensionais, por isso não há para vec2 ou vec4 */

    inline vec3 cross(const vec3 &u, const vec3 &v) {
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
    }

// Normalização de um vetor

    inline vec2 unit_vector(const vec2 &v) {
        return v / v.length();
    }

    inline vec3 unit_vector(const vec3 &v) {
        return v / v.length();
    }

    inline vec4 unit_vector(const vec4 &v) {
        return v / v.length();
    }

#endif