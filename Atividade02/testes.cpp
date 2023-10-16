/**
 * @file main.cpp
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Arquivo para realização dos testes unitários das classes de vetores e matrizes
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "gtest/gtest.h" // Biblioteca do Google Test.
#include "vetor.h" // classes vec2, vec3 e vec4 
#include <iostream>

TEST(Vec3Test, Addition) {
    vec3 v1(1.0, 2.0, 3.0);
    vec3 v2(4.0, 5.0, 6.0);
    vec3 resultado_adicao = v1 + v2;
    vec3 resultado_adicao_esperado(5.0, 7.0, 9.0);
    EXPECT_EQ(resultado_adicao, resultado_adicao_esperado);
}

int main(int argc, char **argv) {

    std::cout << "\nTESTES UNITÁRIOS\n" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

     std::cout << "\rFim dos testes unitarios das classes  \n"<< std::endl;
    return 0;
}

// g++ -o testes.exe testes.cpp vetor.h 