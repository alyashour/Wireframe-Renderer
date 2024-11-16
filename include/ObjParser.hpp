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

bool parseObject(std::string& filename, Object& obj);
void printObject(const Object& obj, const std::string& filename);