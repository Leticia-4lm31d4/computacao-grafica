/**
 * @file class_save_img.cpp
 * @author Leticia Almeida Paulino de Alencar Ferreira | RA: 800480
 * @brief  Classe própria para salvar imagens num determinado formato
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <png.h>  // Biblioteca libpng

class ImageSaver {
public:
    /**
     * @brief Construct a new Image Saver object
     * 
     * @param width da imagem
     * @param height da imagem
     */
    ImageSaver(int width, int height) : width(width), height(height) {
        // Aloca espaço para a imagem
        pixels.resize(width * height * 3);
    }
    
    /**
     * @brief Define os valores dos pixels da imagem/objeto
     * 
     * @param x 
     * @param y 
     * @param r 
     * @param g 
     * @param b 
     */
    void SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
        int index = (y * width + x) * 3;
        pixels[index] = r;
        pixels[index + 1] = g;
        pixels[index + 2] = b;
    }

    /**
     * @brief Salva a imagem em formato PNG
     * 
     * @param filename 
     * @return true 
     * @return false 
     */
    bool SavePNG(const char* filename) {
        FILE* file = fopen(filename, "wb");
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo para escrita: " << filename << std::endl;
            return false;
        }

        png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
        if (!png) {
            fclose(file);
            std::cerr << "Erro ao criar a estrutura PNG." << std::endl;
            return false;
        }

        png_infop info = png_create_info_struct(png);
        if (!info) {
            png_destroy_write_struct(&png, nullptr);
            fclose(file);
            std::cerr << "Erro ao criar a estrutura de informações PNG." << std::endl;
            return false;
        }

        png_bytep row_pointers[height];
        for (int i = 0; i < height; ++i) {
            row_pointers[i] = &pixels[i * width * 3];
        }

        png_init_io(png, file);
        png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
        png_write_info(png, info);
        png_write_image(png, row_pointers);
        png_write_end(png, nullptr);

        fclose(file);
        png_destroy_write_struct(&png, &info);

        std::cout << "Imagem salva com sucesso: " << filename << std::endl;
        return true;
    }

private:
    int width;
    int height;
    std::vector<unsigned char> pixels;
};


int main() {
    /**
     * @brief Declaração do tamanho (largura e altura) das imagens
     */
    int image_width = 256;
    int image_height = 256;

    /**
     * @brief Criação dos objeto que serão as imagem geradas para serem salvas
     * @return ImageSaver 
     */
    ImageSaver degrade_square(image_width, image_height);
    ImageSaver circle(image_width, image_height);
    ImageSaver square(image_width, image_height);

    /**
     * @brief Gera uma imagem, que consiste em um quadrado colorido em DEGRADE, 
     * assim ela será salva no formato png por meio da classe.
     * 
     * OBS.: trecho de código retirado da seção 2 do tutorial, com modificação das cores.
     */
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = 0;
            auto b = double(j) / (image_height - 1);
        
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
        
           degrade_square.SetPixel(i, j, ir, ig, ib);
        }
    }

    /**
     * @brief Salva a imagem e verifica se o processo ocorreu com sucesso ou não.
     */
    if (degrade_square.SavePNG("output.png")) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao salvar a imagem." << std::endl;
    }

    return 0;
}
