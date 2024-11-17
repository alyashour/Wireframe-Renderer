#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "ObjParser.hpp"

bool parseObject(std::string& filename, Object& obj) {
    // open the file
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // read line by line
    std::string line;
    while (std::getline(file, line)) {
        // get the prefix
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        // OPTIONS:
        // - v
        // - f
        // - blank
        // anything else yields an error and the file is skipped

        // vertex
        if (prefix == "v") {
            Vertex vertex{};
            iss >> vertex.x >> vertex.y >> vertex.z;
            obj.vertices.push_back(vertex);
        } 
        // face
        else if (prefix == "f") {
            Face face{};
            iss >> face.v1 >> face.v2 >> face.v3;
            obj.faces.push_back(face);
        } 
        // blank or return
        else if (prefix.empty() || prefix == "\n") {
            // do nothing
        } 

        // syntax error
        else {
            std::cerr << R"(Syntax Error: Expected "v" or "f" received ")" << static_cast<int>(prefix[0]) << "\" instead" << std::endl;
            return false;
        }
    }

    // tell the os to close the file
    file.close();
    return true;
}

void printObject(const Object& obj, const std::string& filename) {
    int count;
    std::cout << "Data from file: " << filename << std::endl;

    // print each vertex
    count = 1;
    std::cout << "Vertices: " << std::endl;
    for (const Vertex& vertex : obj.vertices) {
        std::cout << "\t" << count++ << ") " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }

    // print each face
    count = 1;
    std::cout << "Faces: " << std::endl;
    for (const Face& face : obj.faces) {
        std::cout << "\t" << count++ << ") " << face.v1 << " " << face.v2 << " " << face.v3 << std::endl;
    }

    // end
    std::cout << std::endl;
}
