#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "ObjParser.hpp"

bool parseObject(std::string& filename, Object& obj) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            obj.vertices.push_back(vertex);
        } else if (prefix == "f") {
            Face face;
            iss >> face.v1 >> face.v2 >> face.v3;
            obj.faces.push_back(face);
        } else {
            std::cerr << "Syntax Error: Expected \"v\" or \"f\" recieved " << prefix << " instead" << std::endl;
            return false;
        }
    }

    file.close();
    return true;
}

void printObject(const Object& obj, const std::string& filename) {
    std::cout << "Data from file: " << filename << std::endl;
    std::cout << "Vertices: " << std::endl;
    for (const Vertex& vertex : obj.vertices)
        std::cout << "\t" << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;

    std::cout << "Faces: " << std::endl;
    for (const Face& face : obj.faces) 
        std::cout << "\t" << face.v1 << " " << face.v2 << " " << face.v3 << std::endl;
    std::cout << std::endl;
}
