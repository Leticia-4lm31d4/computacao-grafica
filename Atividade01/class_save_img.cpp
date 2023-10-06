/**
 * @file class_save_img.cpp
 * @author Leticia Almeida Paulino de Alencar Ferreira | RA: 800480
 * @brief  Classe própria para salvar imagens no formato .png
 * @version 0.1
 * @date 2023-10-05
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#include <iostream>
#include <vector>
#include <png.h>  // Biblioteca libpng
#include <cmath>


class ImageSaver {
public:
    /**
     * @brief Constrói um novo objeto ImageSaver
     * Nele o espaço para os pixels da imagem é alocado e cada pixel da imagem é representado por três valores
     * @param width largura da imagem
     * @param height altura da imagem
     */
    ImageSaver(int width, int height) : width(width), height(height) {
        pixels.resize(width * height * 3); 
    }
    
    /**
     * @brief Define o valor/cor de um pixel da imagem/objeto
     * Os valores são armazenados no vetor pixels nos índices calculados, garantindo que o pixel na posição (x, y) tenha a cor especificada.
     * @param x coordenada do pixel
     * @param y coordenada do pixel
     * @param r valor de de red do pixel
     * @param g valor de green no pixel
     * @param b valor de blue no pixel
     */
    void SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
        int index = (y * width + x) * 3;
        pixels[index] = r;
        pixels[index + 1] = g;
        pixels[index + 2] = b;
    }

    /**
     * @brief Salva uma imagem no formato PNG
     * @param filename nome do arquivo de imagem a ser salvo
     * @return true // foi salvo com sucesso
     * @return false // houve falha de salvamento
     */
    bool SavePNG(const char* filename) {

        // Abre um arquivo para escrita com o nome passado como argumento.
        FILE* file = fopen(filename, "wb");
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo para escrita: " << filename << std::endl;
            return false;
        }

        // Cria uma estrutura png, que permite a escrita de um arqv, utilizando a função da biblioteca libpng
        png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
        if (!png) {
            fclose(file);
            std::cerr << "Erro ao criar a estrutura PNG." << std::endl;
            return false;
        }

        /**
         * @brief Cria uma estrutura para a informação da estrutura "png" criada, 
         * essa é passada como argumento para a função da biblioteca libpng.
         * Caso a estrutura não seja criada, usa-se da função "_destroy_" para destrui-lá.
         * Para destrir a estrutura passa-se como argumento o endereço da estrutura png.
         */
        png_infop info = png_create_info_struct(png);
        if (!info) {
            png_destroy_write_struct(&png, nullptr);
            fclose(file);
            std::cerr << "Erro ao criar a estrutura de informações PNG." << std::endl;
            return false;
        }

        /**
         * @brief Cria um vetor de ponteiros para as linhas da imagem, 
         * com tamanho dado pela altura da imagem já que cada célula do vetor representa uma linha da imagem.
         * Então, com o loop, cada ponteiro apontará para uma linha do vetor de pixels.
         */
        png_bytep row_pointers[height];
        for (int i = 0; i < height; ++i) {
            row_pointers[i] = &pixels[i * width * 3];
        }

        /*O trecho abaixo é um conjunto de funções que foram fornecidas pela biblioteca para que haja a manipulaçao da estruturas png*/

        // Inicialização do objeto png para que possa-se escrever nele. 
        png_init_io(png, file); 
        // Definição das informações "info" da imagem, com seus dados de largura, altura e tipo de cor, rgb nesse caso.
        png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
        // Escreve as informações da imagem no arquivo png.
        png_write_info(png, info);
        // Escreve as linhas da imagem (pixels da imagem) no arquivo.
        png_write_image(png, row_pointers);
        // Utiliza-se essa função para finalizar a escrita no arquivo.
        png_write_end(png, nullptr);

        // fecha o arquivo aberto
        fclose(file);
        // Destroi as estruturas criadas, tanto a do png quanto a de informação paar esse png
        png_destroy_write_struct(&png, &info);

        std::cout << "Imagem salva com sucesso: " << filename << std::endl;
        return true;
    }

private:
    // as propriedades abaixo estão privadas pois são detalhes internos, assim estão encapsulados
    int width;
    int height;
    std::vector<unsigned char> pixels; // definição do vetor de pixels
};

/**
 * @brief Função para verificar se um ponto(x, y) está dentro do círculo
 * 
 * @param x coordenada x do ponto a ser verificado
 * @param y coordenada y do ponto a ser verificado
 * @param centerX coordenada x do centro do circulo
 * @param centerY coordenada y do centro do circulo
 * @param radius raio do circulo
 *
 * Cáculo para saber se o ponto está dentro ou fora do cículo
 * @return true // está dentro do circulo
 * @return false // não está dentro do circulo
 */
bool isInsideCircle(int x, int y, int centerX, int centerY, int radius) {
    int dx = x - centerX;
    int dy = y - centerY;
    return (dx * dx + dy * dy) <= (radius * radius);
}

int main() {

    // Declaração do tamanho (largura e altura) das imagens
    int image_width = 256;
    int image_height = 256;

    // Centro do círculo
    int centerX = image_width / 2;
    int centerY = image_height / 2;
    // Raio do círculo
    int radius = std::min(centerX, centerY);


    /**
     * @brief Instanciando cada objeto que serão as imagem geradas a fim de serem salvas
     * @return ImageSaver 
     */
    ImageSaver degrade_square(image_width, image_height);
    ImageSaver circle(image_width, image_height);
    ImageSaver square(image_width, image_height);

    /**
     * @brief Render Degradê.
     * Gera uma imagem, que consiste em um quadrado colorido em DEGRADE.
     * OBS.: trecho de código retirado da seção 2 do tutorial, com modificação das cores.
     */
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.2;  
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

           degrade_square.SetPixel(i, j, ir, ig, ib);
        }
    }
    std::clog << "\rDone. Degrade           \n";

    /**
     * @brief Salva uma imagem em .png e verifica se o processo ocorreu com sucesso ou não.
     */
    if (degrade_square.SavePNG("degrade.png")) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao salvar a imagem." << std::endl;
    }
    std::clog << "\r\n";

    /**
     * @brief Render Circulo
     * Gera uma imagem, que consiste em um CÍRCULO azul.
     */
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            if (isInsideCircle(i, j, centerX, centerY, radius)) {
                auto r = 0.2;
                auto g = 0.5;
                auto b = 1.0;
                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                circle.SetPixel(i, j, ir, ig, ib);
            } 
            else {
                auto r = 1.0;
                auto g = 1.0;
                auto b = 1.0;
                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                circle.SetPixel(i, j, ir, ig, ib);
            }
        }
    }
    std::clog << "\rDone. Circle              \n";

    if (circle.SavePNG("circulo.png")) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao salvar a imagem." << std::endl;
    }
    std::clog << "\r\n";

    /**
     * @brief Render QUADRADO
     * Gera uma imagem, que consiste em um QUADRADO vermelho.
     */
     for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = 0.9;
            auto g = 0.2;
            auto b = 0.2;
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            square.SetPixel(i, j, ir, ig, ib);
        }
    }
    std::clog << "\rDone. Quadrado              \n";

    if (square.SavePNG("quadrado.png")) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao salvar a imagem." << std::endl;
    }

    return 0;
}
