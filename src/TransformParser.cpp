#include <fstream>
#include <iostream>
#include <Eigen/Dense>

using std::string;
using std::fstream;
using Eigen::Matrix4f;
using Eigen::Vector3f;

/**
 * Parses a transform matrix from a <transformfile>.txt file.
 * Can handle transforms, rotations, and scales.
 * @param filename the path to the txt file
 * @param transform a homogenous transform matrix
 * @return true if successful, false otherwise
 */
bool parseTransformFile(string& filename, Matrix4f& transform) {
    // open the file
    fstream file(filename);

    // error if it couldn't be open
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        std::istringstream lineStream(line);
        string prefix;
        lineStream >> prefix;

        if (prefix == "t") {
            // read the transform
            Matrix4f t{};
            float tx, ty, tz;
            lineStream >> tx >> ty >> tz;
            t << 1, 0, 0, tx,
                 0, 1, 0, ty,
                 0, 0, 1, tz,
                 0, 0, 0, 1;
            transform = t * transform;
        }
        // rotate
        else if (prefix == "r") {
            float rx, ry, rz, theta;
            lineStream >> rx >> ry >> rz >> theta;
            Vector3f axis(rx, ry, rz);
            axis.normalize();

            Eigen::Matrix3f r3 = Eigen::AngleAxisf(theta, axis).toRotationMatrix();
            Matrix4f r4 = Matrix4f::Identity();
            r4.block<3, 3>(0, 0) = r3;
            transform = r4 * transform;
        }
        // scale
        else if (prefix == "s") {
            float sx, sy, sz;
            lineStream >> sx >> sy >> sz;
            Matrix4f scale_matrix = Matrix4f::Identity();
            scale_matrix(0, 0) = sx;
            scale_matrix(1, 1) = sy;
            scale_matrix(2, 2) = sz;
            transform = scale_matrix * transform;
        } else {
            std::cerr << "Unrecognized transform file format" << std::endl;
            return false;
        }
    }

    file.close();
    return true;
}
