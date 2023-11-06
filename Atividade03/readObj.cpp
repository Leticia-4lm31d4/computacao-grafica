#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * @brief Vertices do objeto
 */
struct Vertex {
  float x, y, z;
};

class ObjFileReader {
public:
  ObjFileReader(const std::string& filename) : filename_(filename) {}

  bool readFile() {
    std::ifstream file(filename_);
    if (!file) {
      std::cerr << "Failed to open file: " << filename_ << std::endl;
      return false;
    }

    std::string line;
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::string type;
      iss >> type;

      if (type == "v") {
        Vertex v;
        iss >> v.x >> v.y >> v.z;
        vertices_.push_back(v);
      } else if (type == "f") {
        unsigned int v1, v2, v3;
        iss >> v1 >> v2 >> v3;
        indices_.push_back(v1 - 1);
        indices_.push_back(v2 - 1);
        indices_.push_back(v3 - 1);
      }
    }

    return true;
  }

  const std::vector<Vertex>& getVertices() const {
    return vertices_;
  }

  const std::vector<unsigned int>& getIndices() const {
    return indices_;
  }

private:
  std::string filename_;
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
};



int main() {
  std::string filename = "estrela.obj";

  ObjFileReader objReader(filename);

  if (!objReader.readFile()) {
    std::cerr << "Não foi possível ler o arquivo OBJ." << std::endl;
    return 1;
  }

  // Obter os vértices e índices
  const std::vector<Vertex>& vertices = objReader.getVertices();
  const std::vector<unsigned int>& indices = objReader.getIndices();

  // Imprimir os vértices para verificação
  for (const Vertex& v : vertices) {
    std::cout << "Vertex: (" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
  }

  return 0;
}
