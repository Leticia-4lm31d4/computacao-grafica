#include "color.h"
#include "ray.h"
#include "vec3.h"

// Visualização de um objeto
#include "ObjFileReader.h"

#include <iostream>

// Adicionando a visualização de uma esfera
bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

/* Visualização de um triãgulo */

/**
 * @brief Função para verificar se um raio atinge o triângulo
 * 
 * @param v0 
 * @param v1 
 * @param v2 
 * @param r 
 * @return true 
 * @return false 
 */
bool hit_triangle(const point3& v0, const point3& v1, const point3& v2, const ray& r) {
    vec3 e1 = v1 - v0;
    vec3 e2 = v2 - v0;
    vec3 h = cross(r.direction(), e2);
    double a = dot(e1, h);

    if (a > -0.00001 && a < 0.00001) {
        return false; // O raio é paralelo ao triângulo.
    }

    double f = 1.0 / a;
    vec3 s = r.origin() - v0;
    double u = f * dot(s, h);

    if (u < 0.0 || u > 1.0) {
        return false;
    }

    vec3 q = cross(s, e1);
    double v = f * dot(r.direction(), q);

    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    double t = f * dot(e2, q);

    return t > 0.00001;
}

color ray_color(const ray& r) {
    /* Visualização da esfera */ 
    /*if (hit_sphere(point3(0,0,-1), 0.5, r)) {
        return color(1, 0, 0);
    }*/
    
    /* Visualização do triangulo */

    // triângulo está no plano z = -1 e tem vértices em (-1, -0.5, -1), (1, -0.5, -1) e (0, 0.5, -1)
    point3 v0(-1, -0.5, -1);
    point3 v1(1, -0.5, -1);
    point3 v2(0, 0.5, -1);

    if (hit_triangle(v0, v1, v2, r)) {
        return color(0.2, 0, 0.8); 
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {

    /* Image */ 

    // Rendered image setup
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";

    /*
        Para que as imagens do circulo e triangulo sejam geradas, 
        basta comentar o trecho de código abaixo (linha 139 até 176)
    */

    // implementação da Atividade 3, visualize um objeto todo, lido de um arquivo

    /*
        Leitura de um arquivo obj para gerar um arquivo .txt com os vértices e faces 
        para que esse objeto seja visualizado a partir desse .txt gerado
    */

    std::string filename = "piramide.obj";

    ObjFileReader objReader(filename);

    if (!objReader.readFile()) {
        std::cerr << "Não foi possível ler o arquivo OBJ." << std::endl;
        return 1;
    }

    // Imprimir os vértices
    const std::vector<Vertex>& vertices = objReader.getVertices();
    for (const Vertex& v : vertices) {
        std::cout << "v " << v.x << " " << v.y << " " << v.z << std::endl;
    }

    // Imprimir as faces
    const std::vector<unsigned int>& indices = objReader.getIndices();
    for (size_t i = 0; i < indices.size(); i += 3) {
        std::cout << "f " << indices[i] + 1 << " " << indices[i + 1] + 1 << " " << indices[i + 2] + 1 << std::endl;
    }

    std::clog << "\rDone.  Leitura obj.            \n";
}