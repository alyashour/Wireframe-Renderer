#include <gtest/gtest.h>

#include <Eigen/Dense>

#include "ObjParser.hpp"
#include "TransformParser.hpp"

using std::string;

TEST(ObjParse, armadillo) {
    Object obj{};
    string filename = "data/armadillo.obj";
    EXPECT_TRUE(parseObject(filename, obj));

    // check correct number of vertices, faces
    EXPECT_EQ(obj.vertices.size(), 15002);
    EXPECT_EQ(obj.faces.size(), 30000);

    // test some specific values
    // NOT ALL VERTICES ARE TESTED
    const std::vector<Vertex>& vertices = obj.vertices;

    unsigned long index = 1;
    EXPECT_NEAR(vertices[index - 1].x, -0.146637, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, -0.718413, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, -0.528342, 0.001);

    index = 11100;
    EXPECT_NEAR(vertices[index - 1].x, -0.307095, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, 0.275512, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, 0.27425, 0.001);

    index = 15000;
    EXPECT_NEAR(vertices[index - 1].x, 0.424558, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, 0.85363, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, 0.68844, 0.001);
}

TEST(ObjParse, bunny) {
    Object obj{};
    string filename = "data/bunny.obj";
    EXPECT_TRUE(parseObject(filename, obj));

    // check correct number of vertices, faces
    constexpr int MAX = 42866;
    constexpr int MID = 14290;
    EXPECT_EQ(obj.vertices.size(), MID);
    EXPECT_EQ(obj.faces.size(), MAX - MID);

    // test some specific values
    // NOT ALL VERTICES ARE TESTED
    const std::vector<Vertex>& vertices = obj.vertices;

    // vertices
    unsigned long index = 1;
    EXPECT_NEAR(vertices[index - 1].x, 0.309469, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, -0.921392, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, 0.450065, 0.001);

    index = 5000;
    EXPECT_NEAR(vertices[index - 1].x, 0.0451504, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, -0.927159, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, 0.673375, 0.001);

    index = 12000;
    EXPECT_NEAR(vertices[index - 1].x, -0.698943, 0.001);
    EXPECT_NEAR(vertices[index - 1].y, 0.242599, 0.001);
    EXPECT_NEAR(vertices[index - 1].z, -0.094351, 0.001);
}

TEST(TransformTest, test1) {
    Eigen::Matrix4f m = Eigen::Matrix4f::Identity();
    string filename = "data/transform_data1.txt";
    EXPECT_TRUE(parseTransformFile(filename, m));

    // make sure the array is still the proper array
    EXPECT_EQ(m.rows(), 4);
    EXPECT_EQ(m.cols(), 4);

    Eigen::Matrix4f expected{};
    expected << 1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1;

    EXPECT_TRUE(m.isApprox(expected));
}

TEST(TransformTest, test2) {
    Eigen::Matrix4f m = Eigen::Matrix4f::Identity();
    string filename = "data/transform_data2.txt";
    EXPECT_TRUE(parseTransformFile(filename, m));

    // make sure the array is still the proper array
    EXPECT_EQ(m.rows(), 4);
    EXPECT_EQ(m.cols(), 4);

    Eigen::Matrix4f expected{};
    expected << 0.82533561f, 0.3848822f, 0.41314261f, -1.65067123f,
                0.f, 0.73168887f, -0.68163876f, 0.f,
                -0.56464247f, 0.56258075f, 0.60388888f, 1.12928495f,
                0.f, 0.f, 0.f, 1.f;

    EXPECT_TRUE(m.isApprox(expected));
}
