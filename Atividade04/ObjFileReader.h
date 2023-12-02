#ifndef OBJ_FILE_READER_H
#define OBJ_FILE_READER_H

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
  /**
   * @brief Construct a new Obj File Reader object
   * @param filename 
   */
  ObjFileReader(const std::string& filename);

  /**
   * @brief Variavel de verificação de leitura do arquivo
   * @return true 
   * @return false 
   */
  bool readFile();

 /**
  * @brief Get dos Vertices do object
  * @return const std::vector<Vertex>& 
  */
  const std::vector<Vertex>& getVertices() const;
  /**
   * @brief Get dos Indices do object
   * @return const std::vector<unsigned int>& 
   */
  const std::vector<unsigned int>& getIndices() const;

private:
  std::string filename_;
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
};

/**
 * @brief Construct a new Obj File Reader:: Obj File Reader object
 * @param filename 
 */
ObjFileReader::ObjFileReader(const std::string& filename) : filename_(filename) {}

/**
 * @brief Leitura de um arquivo obj
 * @return true 
 * @return false 
 */
bool ObjFileReader::readFile() {
  std::ifstream file(filename_);

  if (!file) {
    std::cerr << "Falha ao abriri o arquivo: " << filename_ << std::endl;
    return false;
  }

  std::string line;
  
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string type;
    iss >> type;

    // vertices do obj
    if (type == "v") {
      Vertex v;
      iss >> v.x >> v.y >> v.z;
      vertices_.push_back(v);
    } 
    // faces do obj
    else if (type == "f") {
      unsigned int v1, v2, v3;
      iss >> v1 >> v2 >> v3;
      indices_.push_back(v1 - 1);
      indices_.push_back(v2 - 1);
      indices_.push_back(v3 - 1);
    }
  }

  return true;
}

const std::vector<Vertex>& ObjFileReader::getVertices() const {
  return vertices_;
}

const std::vector<unsigned int>& ObjFileReader::getIndices() const {
  return indices_;
}

#endif