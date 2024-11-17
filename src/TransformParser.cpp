#include <fstream>
#include <iostream>
#include <Eigen/Dense>

using std::string;
using std::fstream;
using Eigen::Matrix4f;

bool parseTransformFile(string& filename, Matrix4f& translation, Matrix4f& rotation, Matrix4f& scaling) {
    // open the file
    fstream file(filename);

    // error if couldn't open
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return false;
    }

    // read line by line
    // OPTIONS:
    // - t
    // - r
    // - s
    // - blank
    // anything else yields an error
    string line;
    while (getline(file, line)) {
        std::istringstream linestream(line);
        string prefix;
        linestream >> prefix;

        if (prefix == "t") {

        }
    }
}
