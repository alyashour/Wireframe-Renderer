#include <iostream>

#include "RendererConfig.hpp"
#include "ObjParser.hpp"

using std::cout, std::cin, std::cerr, std::endl;
using std::string;

int main(const int argc, const char* argv[]) {
    cout << "RENDERER VERSION " << Renderer_VERSION_MAJOR << "." << Renderer_VERSION_MINOR << endl;

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " file1.obj file2.obj ... fileN.obj" << endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        Object obj;
        if (parseObject(filename, obj)) {
            printObject(obj, filename);
        } else {
            cerr << "Skipping file: " << filename << endl;
        }
    }

    return 0;
}
