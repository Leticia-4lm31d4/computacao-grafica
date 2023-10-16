/**
 * @file vec3.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief classe que representa vetores tridimensionais e suas operações.
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt; 

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

// point3 é um alias para o vec3, útil para deixar o código mais legivel
using point3 = vec3;


// Funções estáticas para as funções no vetor

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif