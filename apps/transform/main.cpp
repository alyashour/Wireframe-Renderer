/**
 * Example of using the transform parser
 */

#include <iostream>

#include "RendererConfig.hpp"
#include "TransformParser.hpp"

using std::string;
using std::cout, std::endl;;
using Eigen::Matrix4f;

int main(int argc, char **argv) {
    cout << "RENDERER VERSION " << Renderer_VERSION_MAJOR << "." << Renderer_VERSION_MINOR << endl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>.txt" << std::endl;
        return 1;
    }

    Matrix4f m = Matrix4f::Identity();
    string filename = argv[1];
    if (parseTransformFile(filename, m)) {
        cout << m.inverse();
        return 0;
    }

    std::cerr << "Failed to parse file " << filename << std::endl;
    return 1;
}
