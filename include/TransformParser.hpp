#pragma once
#include <Eigen/Dense>

/**
 * Parses a transform.txt file into 3, 4x4 transformation matrices
 * E.g., file:
 * t t1 t2 t3
 * r r1 r2 r3 angle_in_rads
 * s s1 s2 s3
 * @param filename
 * @param translation
 * @param rotation
 * @param scaling
 * @return true if a success, false otherwise
 */
bool parseTransformFile(
    std::string& filename,
    Eigen::Matrix4f& translation,
    Eigen::Matrix4f& rotation,
    Eigen::Matrix4f& scaling);

/**
 * Parses a transform.txt file into a single combined transformation matrix
 * @param filename
 * @param transform
 * @return
 */
bool parseTransformFile(std::string& filename, Eigen::Matrix4f& transform);