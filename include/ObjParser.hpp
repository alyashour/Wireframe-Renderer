#pragma once
#include <vector>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

struct Object {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};
/**
 * @brief Parses an Object from a .obj file
 * 
 * @param filename  the path to the .obj file
 * @param obj       ref to object 
 * @return true     if successful
 * @return false    otherwise
 */
bool parseObject(std::string& filename, Object& obj);

/**
 * @brief Prints an object to cout
 * 
 * @param obj       the object data
 * @param filename  (Optional) where the object came from (the file name)
 */
void printObject(const Object& obj, const std::string& filename = "");