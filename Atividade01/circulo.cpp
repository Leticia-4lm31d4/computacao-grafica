#include <iostream>
#include <cmath>

// Função para verificar se um ponto (x, y) está dentro do círculo
bool isInsideCircle(int x, int y, int centerX, int centerY, int radius) {
    int dx = x - centerX;
    int dy = y - centerY;
    return (dx * dx + dy * dy) <= (radius * radius);
}

int main() {
    // Tamanho da imagem
    int image_width = 256;
    int image_height = 256;

    // Centro do círculo
    int centerX = image_width / 2;
    int centerY = image_height / 2;

    // Raio do círculo
    int radius = std::min(centerX, centerY);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            if (isInsideCircle(i, j, centerX, centerY, radius)) {
                auto r = 1.0;
                auto g = 0.2;
                auto b = 0.2;
                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);
                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            } else {
                auto r = 1.0;
                auto g = 1.0;
                auto b = 1.0;
                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);
                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }
    }

    std::clog << "\rDone. Circle              \n";
}
