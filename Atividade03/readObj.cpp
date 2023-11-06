#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * @brief Vertices do objeto * 
 */
struct Vertex {
  float x, y, z;
};

/**
 * @brief Cria um vetor de vértices e um vetor de índices
 * Percorre cada linha do arquivo OBJ 
 * Se a linha começar com “v”, adiciona novo vértice ao vetor de vértices
 * Se a linha começar com “f”, adiciona os índices dos vértices que formam a face ao vetor de índices
 * @param filename 
 * @return novo vetor de vértices
 */
std::vector<Vertex> readObjFile(const std::string& filename) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;

  std::ifstream file(filename);
  if (!file) {
     std::cerr << "Failed to open file: " << filename << std::endl;
     return vertices;
  }

  std::string line;
  while (std::getline(file, line)) {
     std::istringstream iss(line);
     std::string type;
     iss >> type;

     if (type == "v") {
        Vertex v;
        iss >> v.x >> v.y >> v.z;
        vertices.push_back(v);
     } else if (type == "f") {
        unsigned int v1, v2, v3;
        iss >> v1 >> v2 >> v3;
        indices.push_back(v1 - 1);
        indices.push_back(v2 - 1);
        indices.push_back(v3 - 1);
     }

  }

  std::vector<Vertex> result(vertices.size());
  for (unsigned int i = 0; i < vertices.size(); ++i) {
     result[i] = vertices[i];
  }

  return result;
}