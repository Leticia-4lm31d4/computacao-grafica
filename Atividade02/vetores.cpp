/**
 * @file main.cpp
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Arquivo para realização dos testes unitários das classes de vetores
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// classes vec2, vec3 e vec4 
#include "vec2.h" 
#include "vec3.h" 
#include "vec4.h" 

#include <iostream>

bool areEqual2(const vec2 &u, const vec2 &v);
bool areEqual3(const vec3 &u, const vec3 &v);
bool areEqual4(const vec4 &u, const vec4 &v);

int main() {

    std::cout << "# TESTES UNITÁRIOS VETORES" << std::endl;
    std::cout << "> vetores.cpp\n" << std::endl;

    vec2 vet2(1.0, 3.0);
    vec3 vet3(2.0, 1.0, 1.5);
    vec4 vet4(4.0, 0.0, 5.0, 1.0);

    std::cout << "Vetor (x, y):\n";
    std::cout << vet2;

    std::cout << "\n"<< std::endl;

    std::cout << "Vetor (x, y, z):\n";
    std::cout << vet3;

    std::cout << "\n"<< std::endl;

    std::cout << "Vetor (x, y, z, w):\n";
    std::cout << vet4;

    std::cout << "\n\n## Vetores auxiliares:\n";

    vec2 u2(1.0, 1.0);
    std::cout << u2; std::cout << "\n";
    vec3 u3(2.0, 2.0, 2.0);
    std::cout << u3; std::cout << "\n";
    vec4 u4(2.0, 0.0, 1.0, 0.0);
    std::cout << u4; std::cout << "\n";

    // Soma 
    std::cout << "\n## SOMA\n" << std::endl;

    vec2 result2 = u2 + vet2;
    vec3 result3 = u3 + vet3;
    vec4 result4 = u4 + vet4;

    vec2 sum2(2.0, 4.0);
    vec3 sum3(4.0, 3.0, 3.5);
    vec4 sum4(6.0, 0.0, 6.0, 1.0); 

    if (areEqual2(result2, sum2)) {
        std::cout << "soma vet2 | ok." << std::endl;
    } else {
        std::cout << "soma vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, sum3)) {
        std::cout << "soma vet3 | ok." << std::endl;
    } else {
        std::cout << "soma vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, sum4)) {
        std::cout << "soma vet4 | ok." << std::endl;
    } else {
        std::cout << "soma vet4 | erro." << std::endl;
    }

    // Subtração
    std::cout << "\n## SUBTRAÇÃO\n" << std::endl;

    result2 = u2 - vet2;
    result3 = u3 - vet3;
    result4 = u4 - vet4;

    vec4 falha4(6.0, 0.0, 6.0, 1.0);

    vec2 sub2(0.0, -2.0);
    vec3 sub3(0.0, 1.0, 0.5);
    vec4 sub4(-2.0, 0.0, -4.0, -1.0); 

    if (areEqual2(result2, sub2)) {
        std::cout << "sub vet2 | ok." << std::endl;
    } else {
        std::cout << "sub vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, sub3)) {
        std::cout << "sub vet3 | ok." << std::endl;
    } else {
        std::cout << "sub vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, sub4)) {
        std::cout << "sub vet4 | ok." << std::endl;
    } else {
        std::cout << "sub vet4 | erro." << std::endl;
    }

    std::cout << "> Verificando se acusa erro" << std::endl;

    if (areEqual4(result4, falha4)) {
        std::cout << "sub vet4 | ok." << std::endl;
    } else {
        std::cout << "sub vet4 | erro." << std::endl;
    }

    // Produto vetores
    std::cout << "\n## PRODUTOS VETORES\n" << std::endl;

    result2 = u2 * vet2;
    result3 = u3 * vet3;
    result4 = u4 * vet4;

    vec2 p2(1.0, 3.0);
    vec3 p3(4.0, 2.0, 3.0);
    vec4 p4(8.0, 0.0, 5.0, 0.0); 

    if (areEqual2(result2, p2)) {
        std::cout << "prod vet2 | ok." << std::endl;
    } else {
        std::cout << "prod vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, p3)) {
        std::cout << "prod vet3 | ok." << std::endl;
    } else {
        std::cout << "prod vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, p4)) {
        std::cout << "prod vet4 | ok." << std::endl;
    } else {
        std::cout << "prod vet4 | erro." << std::endl;
    }

    // Escalar x vetor
    std::cout << "\n## ESCALAR VEZES VETOR\n" << std::endl;

    result2 = 3 * vet2;
    result3 = 2 * vet3;
    result4 = 1 * vet4;

    vec2 ev2(3.0, 9.0);
    vec3 ev3(4.0, 2.0, 3.0);
    vec4 ev4(4.0, 0.0, 5.0, 1.0); 

    if (areEqual2(result2, ev2)) {
        std::cout << "esc_vet vet2 | ok." << std::endl;
    } else {
        std::cout << "esc_vet vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, ev3)) {
        std::cout << "esc_vet vet3 | ok." << std::endl;
    } else {
        std::cout << "esc_vet vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, ev4)) {
        std::cout << "esc_vet vet4 | ok." << std::endl;
    } else {
        std::cout << "esc_vet vet4 | erro." << std::endl;
    }

    // Vetor x escalar
    std::cout << "\n## VETOR VEZES ESCALAR\n" << std::endl;

    result2 = vet2 * 3;
    result3 = vet3 * 2;
    result4 = vet4 * 1;

    vec2 ve2(3.0, 9.0);
    vec3 ve3(4.0, 2.0, 3.0);
    vec4 ve4(4.0, 0.0, 5.0, 1.0); 

    if (areEqual2(result2, ve2)) {
        std::cout << "vet_esc vet2 | ok." << std::endl;
    } else {
        std::cout << "vet_esc vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, ve3)) {
        std::cout << "vet_esc vet3 | ok." << std::endl;
    } else {
        std::cout << "vet_esc vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, ve4)) {
        std::cout << "vet_esc vet4 | ok." << std::endl;
    } else {
        std::cout << "vet_esc vet4 | erro." << std::endl;
    }

    // Divisão
    std::cout << "\n## DIVISÃO\n" << std::endl;

    result2 = vet2 / 2;
    result3 = vet3 / 1;

    // não pode divisão por zero, então vet4 substituído por d4
    vec4 d4(6.0, 6.0, 6.0, 6.0);
    result4 = d4 / 3; 

    vec2 div2(0.5, 1.5);
    vec3 div3(2.0, 1.0, 1.5);
    vec4 div4(2.0, 2.0, 2.0, 2.0);

    if (areEqual2(result2, div2)) {
        std::cout << "div vet2 | ok." << std::endl;
    } else {
        std::cout << "div vet2 | erro." << std::endl;
    }

    if (areEqual3(result3, div3)) {
        std::cout << "div vet3 | ok." << std::endl;
    } else {
        std::cout << "div vet3 | erro." << std::endl;
    }

    if (areEqual4(result4, div4)) {
        std::cout << "div vet4 | ok." << std::endl;
    } else {
        std::cout << "div vet4 | erro." << std::endl;
    } 
    
    // Produto escalar de dois vetores
    std::cout << "\n## PRODUTO ESCALAR DE 2 VETORES\n" << std::endl;

    double r2 = dot(vet2, vet2);
    double r3 = dot(vet3, vet3);
    double r4 = dot(vet4, vet4);

    if(r2 == 10){
        std::cout << "prod_esc vet2 | ok." << std::endl;
    } else {
        std::cout << "prod_esc vet2 | erro." << std::endl;
    } 

    if(r3 == 7.25){
        std::cout << "prod_esc vet3 | ok." << std::endl;
    } else {
        std::cout << "prod_esc vet3 | erro." << std::endl;
    } 

    if(r4 == 42){
        std::cout << "prod_esc vet4 | ok." << std::endl;
    } else {
        std::cout << "prod_esc vet4 | erro." << std::endl;
    } 

    // Produto vetorial VEC3
    std::cout << "\n## PRODUTO VETORIAL\n" << std::endl;

    result3 = cross(vet3, u3);
    vec3 prod_vet(-1.0, -1.0, 2.0);

    if (areEqual3(result3, prod_vet)) {
        std::cout << "prod_vet vet3 | ok." << std::endl;
    } else {
        std::cout << "prod_vet vet3 | erro." << std::endl;
    }

    // Normalização
    std::cout << "\n## NORMALIZAÇÃO\n" << std::endl;

    result2 = unit_vector(vet2);
    result3 = unit_vector(vet3);
    // vetor4 tem 0, divisao por zero não pode

    vec2 norm2(0.316228, 0.948683);
    vec3 norm3(0.742781, 0.371391, 0.557086);

    std::cout << "norma vet2 | Saída: " << std::endl;
    std::cout << result2;
    std::cout << "\nnorma vet2 | Saída esperada: " << std::endl;
    std::cout << norm2;
    std::cout << "\n\nnorma vet3 | Saída: " << std::endl;
    std::cout << result3;
    std::cout << "\nnorma vet3 | Saída: " << std::endl;
    std::cout << norm3;

    std::cout << "\n" << std::endl;

    std::cout << "\nFim dos testes unitarios!  \n"<< std::endl;
    return 0;
}

// Função para saber se o vetor resultado e o esperado são iguais
bool areEqual2(const vec2 &u, const vec2 &v) {
    return (u.x() == v.x()) && (u.y() == v.y());
}

bool areEqual3(const vec3 &u, const vec3 &v) {
    return (u.x() == v.x()) && (u.y() == v.y()) && (u.z() == v.z());
}

bool areEqual4(const vec4 &u, const vec4 &v) {
    return (u.x() == v.x()) && (u.y() == v.y()) && (u.z() == v.z()) && (u.w() == v.w());
}

// g++ -o vet.exe vetores.cpp vec2.h vec3.h vec4.h  