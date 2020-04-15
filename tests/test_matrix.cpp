#include "matrix.h"
#include <gtest/gtest.h>
#include <list>
#include <tuple>

TEST(matrix, empty_matrix)
{
	Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
    ASSERT_EQ(matrix.size(), 0);
}
TEST(matrix, request_from_empty_matrix)
{
	Matrix<int, -1> matrix; 
	auto a = matrix[0][0];
	ASSERT_EQ(a, -1);
	ASSERT_EQ(matrix.size(), 0);
}
TEST(matrix, add_element)
{
	Matrix<int, -1> matrix; 
	matrix[100][100] = 314;
	ASSERT_EQ(matrix[100][100], 314);
	ASSERT_EQ(matrix.size(), 1);
}
TEST(matrix, reassign_to_init_value)
{
	Matrix<int, -1> matrix; 
	matrix[100][100] = 314;
	ASSERT_EQ(matrix[100][100], 314);
	ASSERT_EQ(matrix.size(), 1);
	matrix[100][100] = -1;
	ASSERT_EQ(matrix.size(), 0);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}