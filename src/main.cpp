#include <iostream>
#include "ObjParser.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " obj_file1.obj obj_file2.obj ... obj_fileN.obj" << std::endl;
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
    
    return 0;
}
