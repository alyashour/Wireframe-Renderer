#include "RendererConfig.hpp"
#include "ObjParser.hpp"

#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[]) {
    std::cout << "RENDERER VERSION " << Renderer_VERSION_MAJOR << "." << Renderer_VERSION_MINOR << std::endl;
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " file1.obj file2.obj ... filen.obj" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string filename = argv[i];
        Object obj;
        if (parseObject(filename, obj)) {
            printObject(obj, filename);
        } else {
            std::cerr << "Skipping file: " << filename << std::endl;
        }
    }

    Eigen::Matrix4d m;
    m << 1, 2, 3, 4, 
         5, 6, 7, 8,
         9, 10, 11, 12,
         13, 14, 15, 16;
    std::cout << m << std::endl;
    
    return 0;
}