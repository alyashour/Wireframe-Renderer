#pragma once
#include <Eigen/Dense>

/**
 * Parses a transform.txt file into a single combined transformation matrix
 * @param filename
 * @param transform
 * @return
 */
bool parseTransformFile(std::string& filename, Eigen::Matrix4f& transform);