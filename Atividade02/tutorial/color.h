/**
 * @file color.h
 * @author Letícia Almeida Paulino de Alencar Ferreira - RA 800480
 * @brief Escrever as cores dos pixels rgb
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef COLOR_H
#define COLOR_H

#include "vetor.h"

#include <iostream>

// Define um alias color para a classe vec3
// usando vec3 para representar cores (r,g,b) e color como um alias para vec3
using color = vec3;

/**
 * @brief Escreve a cor no formato [0, 255].
 *
 * Converte as componentes da cor de ponto flutuante no intervalo [0, 1] 
 * em valores inteiros no intervalo [0, 255] e escreve-os no fluxo de saída 'out'.
 *
 * @param out fluxo de saída onde a cor será escrita.
 * @param pixel_color a cor que será escrita.
 */
void write_color(std::ostream &out, color pixel_color) {
    // Escreve o valor traduzido [0, 255] de cada componente de cor (r,g,b).
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif