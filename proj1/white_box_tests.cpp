//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Dmitrii Kozhevnikov <xkozhe00@stud.fit.vutbr.cz>
// $Date:       $2020-02-21
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Dmitrii Kozhevnikov
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class TestingMatrix : public ::testing::Test {
    protected:

        Matrix matrix;

        Matrix getZeroMatrix1x1() {
            return Matrix();
        }

        void setZeroMatrix1x1() {
            matrix = getZeroMatrix1x1();
        }

        Matrix getMatrix1x1() {
            Matrix matrix = Matrix(1, 1);
            matrix.set(std::vector<std::vector<double>> {
                {5}
            });
            return matrix;
        }
    
        void setMatrix1x1() {
            matrix = getMatrix1x1();
        }

        Matrix getMatrix2x2() {
            Matrix matrix = Matrix(2, 2);
            matrix.set(std::vector<std::vector<double>> {
                {0, 1},
                {2, 3},
            });
            return matrix;
        }
    
        void setMatrix2x2() {
            matrix = getMatrix2x2();
        }

        Matrix getMatrix3x3() {
            Matrix matrix = Matrix(3, 3);
            matrix.set(std::vector<std::vector<double>> {
                {3, 3, -1},
                {4, 1, 3},
                {1, -2, -2},
            });
            return matrix;
        }

        void setMatrix3x3() {
            matrix = getMatrix3x3();
        }

        Matrix getMatrix2x3() {
            Matrix matrix = Matrix(2, 3);
            matrix.set(std::vector<std::vector<double>> {
                {1, -2, 4},
                {2, 0, -1},
            });
            return matrix;
        }

        void setMatrix2x3() {
            matrix = getMatrix2x3();
        }

        Matrix getMatrix3x2() {
            Matrix matrix = Matrix(3, 2);
            matrix.set(std::vector<std::vector<double>> {
                {1, 2},
                {2, -1},
                {3, 0},
            });
            return matrix;
        }

        void setMatrix3x2() {
            matrix = getMatrix3x2();
        }

        Matrix getMatrix4x4() {
            Matrix matrix = Matrix(4, 4);
            matrix.set(std::vector<std::vector<double>> {
                {-2, 1, 3, 2},
                {3, 0, -1, 2},
                {-5, 2, 3, 0},
                {4, -1, 2, -3},
            });
            return matrix;
        }

        void setMatrix4x4() {
            matrix = getMatrix4x4();
        }

        Matrix getMatrix1x3() {
            Matrix matrix = Matrix(1, 3);
            matrix.set(std::vector<std::vector<double>> {
                {1, -2, 0},
            });
            return matrix;
        }

        void setMatrix1x3() {
            matrix = getMatrix1x3();
        }

        Matrix getMatrix3x1() {
            Matrix matrix = Matrix(3, 1);
            matrix.set(std::vector<std::vector<double>> {
                {1},
                {2},
                {3},
            });
            return matrix;
        }

        void setMatrix3x1() {
            matrix = getMatrix3x1();
        }
};

TEST_F(TestingMatrix, Konstruktor) {
    ASSERT_NO_THROW(Matrix());  //  construct matrix 1x1
    ASSERT_NO_THROW(Matrix(1, 1));  //  construct matrix 1x1
    ASSERT_NO_THROW(Matrix(3, 3));  //  construct matrix 3x3
    ASSERT_NO_THROW(Matrix(5, 5));  //  construct matrix 5x5
    ASSERT_NO_THROW(Matrix(10, 10));  //  construct matrix 10x10
    ASSERT_NO_THROW(Matrix(100, 100));  //  construct matrix 100x100
    ASSERT_ANY_THROW(Matrix(0, 0));  //  we can not construct matrix 0x0
    ASSERT_ANY_THROW(Matrix(0, 2));  //  we can not construct matrix 0x2
    ASSERT_ANY_THROW(Matrix(2, 0));  //  we can not construct matrix 2x0
    ASSERT_ANY_THROW(Matrix(-1, 2));  //  we can not construct matrix -1x2
    ASSERT_ANY_THROW(Matrix(2, -1));  //  we can not construct matrix 2x(-1)
}

TEST_F(TestingMatrix, setMatrixValue1x1) {
    setZeroMatrix1x1();
    ASSERT_TRUE(matrix.get(0, 0) == 0); //  value in zeroMatrix is 0
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(0, 0, 10));    //  we can give value 10 on position 1x1
    EXPECT_TRUE(matrix.set(0, 0, -10));    //  we can give value -10 on position 1x1
    EXPECT_FALSE(matrix.set(0, 1, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(1, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue2x2) {
    setMatrix2x2();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 0, 10));    //  we can give value 10 on position 2x1
    EXPECT_TRUE(matrix.set(0, 1, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 2, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(2, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue3x3) {
    setMatrix3x3();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 1, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(0, 1, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 3, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(3, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue2x3) {
    setMatrix2x3();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 1, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(0, 1, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 4, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(4, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue3x2) {
    setMatrix3x2();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 1, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(0, 1, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 4, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(4, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue4x4) {
    setMatrix4x4();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 1, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(0, 1, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 4, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(4, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue1x3) {
    setMatrix1x3();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(0, 1, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(0, 2, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 4, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(4, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
}

TEST_F(TestingMatrix, setMatrixValue3x1) {
    setMatrix3x1();
    EXPECT_TRUE(matrix.set(0, 0, 0));    //  we can give value 0 on position 1x1
    EXPECT_TRUE(matrix.set(1, 0, 10));    //  we can give value 10 on position 2x2
    EXPECT_TRUE(matrix.set(2, 0, -10));    //  we can give value -10 on position 1x2
    EXPECT_FALSE(matrix.set(0, 4, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(4, 0, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(-10, 10, 0));    //  we can not give value 0 on unexisting position
    EXPECT_FALSE(matrix.set(10, 10, 0));    //  we can not give value 0 on unexisting position
    
}

TEST_F(TestingMatrix, goodMatrix2x2) {
	Matrix matrix = getMatrix2x2();
    Matrix newMatrix2x2 = Matrix(2, 2);
    newMatrix2x2.set(std::vector<std::vector<double>> {
        {0, 1},
        {2, 3},
    });
    //  matrix 2x2 is good
    EXPECT_EQ(true, matrix.operator==(newMatrix2x2));
    EXPECT_FALSE(newMatrix2x2.set(std::vector<std::vector<double>> {
        {0, 1, 1},
        {2, 3, 2},
    }));
}



TEST_F(TestingMatrix, goodMatrix3x3) {
	Matrix matrix = getMatrix3x3();
    Matrix newMatrix3x3 = Matrix(3, 3);
    newMatrix3x3.set(std::vector<std::vector<double>> {
        {3, 3, -1},
        {4, 1, 3},
        {1, -2, -2},
    });
    //  matrix 3x3 is good
	EXPECT_EQ(true, matrix.operator==(newMatrix3x3));
}

TEST_F(TestingMatrix, goodMatrix2x3) {
	Matrix matrix = getMatrix2x3();
    Matrix newMatrix2x3 = Matrix(2, 3);
    newMatrix2x3.set(std::vector<std::vector<double>> {
        {1, -2, 4},
        {2, 0, -1},
    });
    //  matrix 2x3 is good
	EXPECT_EQ(true, matrix.operator==(newMatrix2x3));
}

TEST_F(TestingMatrix, goodMatrix3x2) {
	Matrix matrix = getMatrix3x2();
    Matrix newMatrix3x2 = Matrix(3, 2);
    newMatrix3x2.set(std::vector<std::vector<double>> {
        {1, 2},
        {2, -1},
        {3, 0},
    });
    //  matrix 3x2 is good
	EXPECT_EQ(true, matrix.operator==(newMatrix3x2));
}

TEST_F(TestingMatrix, goodMatrix4x4) {
	Matrix matrix = getMatrix4x4();
    Matrix newMatrix4x4 = Matrix(4, 4);
    newMatrix4x4.set(std::vector<std::vector<double>> {
        {-2, 1, 3, 2},
        {3, 0, -1, 2},
        {-5, 2, 3, 0},
        {4, -1, 2, -3},
    });
    //  matrix 4x4 is good

	EXPECT_EQ(true, matrix.operator==(newMatrix4x4));
}

TEST_F(TestingMatrix, goodMatrix1x3) {
	Matrix matrix = getMatrix1x3();
    Matrix newMatrix1x3 = Matrix(1, 3);
    newMatrix1x3.set(std::vector<std::vector<double>> {
        {1, -2, 0},
    });
    //  matrix 1x3 is good
	EXPECT_EQ(true, matrix.operator==(newMatrix1x3));
}

TEST_F(TestingMatrix, goodMatrix3x1) {
	Matrix matrix = getMatrix3x1();
    Matrix newMatrix3x1 = Matrix(3, 1);
    newMatrix3x1.set(std::vector<std::vector<double>> {
        {1},
        {2},
        {3},
    });
    //  matrix 3x1 is good
	EXPECT_EQ(true, matrix.operator==(newMatrix3x1));
}

TEST_F(TestingMatrix, getGoodMatrix2x2) {
	Matrix matrix = getMatrix2x2();
    EXPECT_EQ(0, matrix.get(0, 0));
    EXPECT_EQ(1, matrix.get(0, 1));
    EXPECT_EQ(2, matrix.get(1, 0));
    EXPECT_EQ(3, matrix.get(1, 1));
}

TEST_F(TestingMatrix, getGoodMatrix3x3) {
	Matrix matrix = getMatrix3x3();
    EXPECT_EQ(3, matrix.get(0, 0));
    EXPECT_EQ(3, matrix.get(0, 1));
    EXPECT_EQ(-1, matrix.get(0, 2));
    EXPECT_EQ(4, matrix.get(1, 0));
    EXPECT_EQ(1, matrix.get(1, 1));
    EXPECT_EQ(3, matrix.get(1, 2));
    EXPECT_EQ(1, matrix.get(2, 0));
    EXPECT_EQ(-2, matrix.get(2, 1));
    EXPECT_EQ(-2, matrix.get(2, 2));
    EXPECT_ANY_THROW(matrix.get(-2, 2));
}

TEST_F(TestingMatrix, getGoodMatrix2x3) {
	Matrix matrix = getMatrix2x3();
    EXPECT_EQ(1, matrix.get(0, 0));
    EXPECT_EQ(-2, matrix.get(0, 1));
    EXPECT_EQ(4, matrix.get(0, 2));
    EXPECT_EQ(2, matrix.get(1, 0));
    EXPECT_EQ(0, matrix.get(1, 1));
    EXPECT_EQ(-1, matrix.get(1, 2));
}

TEST_F(TestingMatrix, getGoodMatrix3x2) {
	Matrix matrix = getMatrix3x2();
    EXPECT_EQ(1, matrix.get(0, 0));
    EXPECT_EQ(2, matrix.get(0, 1));
    EXPECT_EQ(2, matrix.get(1, 0));
    EXPECT_EQ(-1, matrix.get(1, 1));
    EXPECT_EQ(3, matrix.get(2, 0));
    EXPECT_EQ(0, matrix.get(2, 1));
}

TEST_F(TestingMatrix, getGoodMatrix4x4) {
	Matrix matrix = getMatrix4x4();
    EXPECT_EQ(-2, matrix.get(0, 0));
    EXPECT_EQ(1, matrix.get(0, 1));
    EXPECT_EQ(3, matrix.get(0, 2));
    EXPECT_EQ(2, matrix.get(0, 3));
    EXPECT_EQ(3, matrix.get(1, 0));
    EXPECT_EQ(0, matrix.get(1, 1));
    EXPECT_EQ(-1, matrix.get(1, 2));
    EXPECT_EQ(2, matrix.get(1, 3));
    EXPECT_EQ(-5, matrix.get(2, 0));
    EXPECT_EQ(2, matrix.get(2, 1));
    EXPECT_EQ(3, matrix.get(2, 2));
    EXPECT_EQ(0, matrix.get(2, 3));
    EXPECT_EQ(4, matrix.get(3, 0));
    EXPECT_EQ(-1, matrix.get(3, 1));
    EXPECT_EQ(2, matrix.get(3, 2));
    EXPECT_EQ(-3, matrix.get(3, 3));
}

TEST_F(TestingMatrix, getGoodMatrix1x3) {
	Matrix matrix = getMatrix1x3();
    EXPECT_EQ(1, matrix.get(0, 0));
    EXPECT_EQ(-2, matrix.get(0, 1));
    EXPECT_EQ(0, matrix.get(0, 2));
}

TEST_F(TestingMatrix, getGoodMatrix3x1) {
	Matrix matrix = getMatrix3x1();
    EXPECT_EQ(1, matrix.get(0, 0));
    EXPECT_EQ(2, matrix.get(1, 0));
    EXPECT_EQ(3, matrix.get(2, 0));
}

TEST_F(TestingMatrix, Porovnani) {
	Matrix matrix2x2 = getMatrix2x2();
	Matrix matrix3x3 = getMatrix3x3();
	Matrix matrix2x3 = getMatrix2x3();
    Matrix matrix3x1 = getMatrix3x1();
    Matrix matrix4x4 = getMatrix4x4();
	EXPECT_TRUE(matrix2x2 == matrix2x2);   //  we can compare matrix with same size
	EXPECT_TRUE(matrix3x1 == matrix3x1);   //  we can compare matrix with same size
	
	EXPECT_ANY_THROW(matrix2x2 == matrix4x4);   //  we can not compare matrix with different size
	EXPECT_ANY_THROW(matrix3x3 == matrix3x1);   //  we can not compare matrix with different size
	Matrix porovnaniMatrix4x4 = Matrix(4, 4);
    porovnaniMatrix4x4.set(std::vector<std::vector<double>> {
        {-2, 1, 3, 2},
        {3, 0, -1, 2},
        {-5, 2, 3, 0},
        {4, -1, 2, -3},
    });
    Matrix nonPorovnaniMatrix4x4 = Matrix(4, 4);
    nonPorovnaniMatrix4x4.set(std::vector<std::vector<double>> {
        {0, 0, 3, 2},
        {3, 0, -1, 2},
        {-5, 2, 0, 0},
        {4, -1, 2, 0},
    });
	EXPECT_TRUE(matrix4x4 == porovnaniMatrix4x4);   //  we have got same matrix
	
	EXPECT_FALSE(matrix4x4 == nonPorovnaniMatrix4x4);   //  we haven't got same matrix
}

TEST_F(TestingMatrix, Sum) {
    Matrix matrix1x1 = getZeroMatrix1x1();
	Matrix matrix2x2 = getMatrix2x2();
	Matrix matrix3x3 = getMatrix3x3();
	Matrix matrix2x3 = getMatrix2x3();
    Matrix matrix1x3 = getMatrix1x3();
    Matrix matrix4x4 = getMatrix4x4();
    //  we can not fold matrix with different size
	EXPECT_ANY_THROW(matrix2x2 + matrix3x3);    
	EXPECT_ANY_THROW(matrix2x2 + matrix2x3);
    EXPECT_ANY_THROW(matrix1x3 + matrix2x3);
	//  sum-control
	Matrix result2x2 = matrix2x2 + matrix2x2;
	Matrix control2x2 = Matrix(2, 2);
	control2x2.set(std::vector<std::vector<double>> {
		{0, 2},
		{4, 6},
	});
	EXPECT_TRUE(result2x2 == control2x2);

    Matrix result1x3 = matrix1x3 + matrix1x3;
	Matrix control1x3 = Matrix(1, 3);
	control1x3.set(std::vector<std::vector<double>> {
		{2, -4, 0},
	});
	EXPECT_TRUE(result1x3 == control1x3);

    Matrix result3x3 = matrix3x3 + matrix3x3;
	Matrix control3x3 = Matrix(3, 3);
	control3x3.set(std::vector<std::vector<double>> {
		{6, 6, -2},
        {8, 2, 6},
        {2, -4, -4},
	});
	EXPECT_TRUE(result3x3 == control3x3);

    Matrix newResult3x3 = matrix3x3 + control3x3;
	Matrix newControl3x3 = Matrix(3, 3);
	newControl3x3.set(std::vector<std::vector<double>> {
    	{9, 9, -3},
        {12, 3, 9},
        {3, -6, -6},
	});
	EXPECT_TRUE(newResult3x3 == newControl3x3);

    Matrix sumZeroMatrix = matrix1x1 + matrix1x1;
	Matrix control1x1 = Matrix(1, 1);
    control1x1.set(std::vector<std::vector<double>> {
    	{0},
	});
	EXPECT_TRUE(sumZeroMatrix == control1x1);
}

TEST_F(TestingMatrix, Multiplication) {
    Matrix matrix1x1 = getZeroMatrix1x1();
	Matrix matrix2x2 = getMatrix2x2();
	Matrix matrix3x3 = getMatrix3x3();
	Matrix matrix2x3 = getMatrix2x3();
    Matrix matrix1x3 = getMatrix1x3();
    Matrix matrix4x4 = getMatrix4x4();
    //  cols in first matrix must be same rows in second matrix
	EXPECT_ANY_THROW(matrix2x2 + matrix3x3);    
	EXPECT_ANY_THROW(matrix2x2 + matrix1x3);
    EXPECT_ANY_THROW(matrix1x3 + matrix4x4);

	//  multiplication-control
	Matrix result2x2 = matrix2x2 * matrix2x2;
	Matrix control2x2 = Matrix(2, 2);
	control2x2.set(std::vector<std::vector<double>> {
		{2, 3},
		{6, 11},
	});
	EXPECT_TRUE(result2x2 == control2x2);

    Matrix result3x3 = matrix3x3 * matrix3x3;
	Matrix control3x3 = Matrix(3, 3);
	control3x3.set(std::vector<std::vector<double>> {
		{20, 14, 8},
        {19, 7, -7},
        {-7, 5, -3},
	});
	EXPECT_TRUE(result3x3 == control3x3);

    Matrix newResult3x3 = matrix3x3 * control3x3;
	Matrix newControl3x3 = Matrix(3, 3);
	newControl3x3.set(std::vector<std::vector<double>> {
    	{124, 58, 6},
        {78, 78, 16},
        {-4, -10, 28},
	});
	EXPECT_TRUE(newResult3x3 == newControl3x3);

    Matrix result1x1to1x3 = matrix1x1 * matrix1x3;
	Matrix control1x1to1x3 = Matrix(1, 3);
    control1x1to1x3.set(std::vector<std::vector<double>> {
    	{0, 0, 0},
	});
	EXPECT_TRUE(result1x1to1x3 == control1x1to1x3);

    Matrix result1x3to3x3 = matrix1x3 * matrix3x3;
	Matrix control1x3to3x3 = Matrix(1, 3);
    control1x3to3x3.set(std::vector<std::vector<double>> {
    	{-5, 1, -7},
	});
	EXPECT_TRUE(result1x3to3x3 == control1x3to3x3);

    //  multiply 2x2 to 3x3
	EXPECT_ANY_THROW(matrix2x2 * matrix3x3);
}

TEST_F(TestingMatrix, MultiplicationForConstNumber){
    Matrix matrix1x1 = getZeroMatrix1x1();
	Matrix matrix2x2 = getMatrix2x2();
    Matrix matrix4x4 = getMatrix4x4();
	Matrix matrix2x3 = getMatrix2x3();
	//  Multiplication-control
	Matrix result1x1 = matrix1x1 * 5;
	Matrix control1x1 = Matrix(1, 1);
    control1x1.set(std::vector<std::vector<double>> {
    	{0},
	});
	EXPECT_TRUE(result1x1 == control1x1);

    Matrix result2x2 = matrix2x2 * 2;
	Matrix control2x2 = Matrix(2, 2);
	control2x2.set(std::vector<std::vector<double>> {
		{0, 2},
		{4, 6},
	});
	EXPECT_TRUE(result2x2 == control2x2);
	
    Matrix result4x4 = matrix4x4 * 0;
	Matrix control4x4 = Matrix(4, 4);
	control4x4.set(std::vector<std::vector<double>> {
    	{0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
	});
	EXPECT_TRUE(result4x4 == control4x4);

    Matrix result2x3 = matrix2x3 * 12;
	Matrix control2x3 = Matrix(2, 3);
	control2x3.set(std::vector<std::vector<double>> {
		{12, -24, 48},
		{24, 0, -12},
	});
	EXPECT_TRUE(result2x3 == control2x3);
}

TEST_F(TestingMatrix,Equation1x1) {
    Matrix matrix = getMatrix1x1();
    std::vector<double> result = {0};
    std::vector<double> right = {0};
    EXPECT_EQ(result, matrix.solveEquation(right));
    
}

TEST_F(TestingMatrix,Equation2x2) {
    Matrix matrix = getMatrix2x2();
    std::vector<double> result = {1, 1};
    std::vector<double> right = {1, 5};
    EXPECT_EQ(result, matrix.solveEquation(right));
    
}

TEST_F(TestingMatrix,Equation3x3) {
    Matrix matrix = getMatrix3x3();
    std::vector<double> result = {1, 1, 1};
    std::vector<double> right = {5, 8, -3};
    EXPECT_EQ(result, matrix.solveEquation(right));
    
}

TEST_F(TestingMatrix,Equation4x4) {
    Matrix matrix = getMatrix4x4();
    std::vector<double> result = {1, 1, 1, 1};
    std::vector<double> right = {4, 4, 0, 2};
    EXPECT_EQ(result, matrix.solveEquation(right));
    
}

TEST_F(TestingMatrix,Equation1x3) {
    Matrix matrix = getMatrix1x3();
    ASSERT_ANY_THROW(matrix.solveEquation({1, 2, 3}));   
}

TEST_F(TestingMatrix,Determinant0) {
    Matrix control4x4 = Matrix(4, 4);
	control4x4.set(std::vector<std::vector<double>> {
    	{0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
	});
    ASSERT_ANY_THROW(matrix.solveEquation({2, 0, 0, 1}));   
}

TEST_F(TestingMatrix,Determinant1x1je0) {
    Matrix control1x1 = getZeroMatrix1x1();
    ASSERT_ANY_THROW(control1x1.solveEquation({0}));   
}

TEST_F(TestingMatrix,RightElementsRovnoMatrixCols) {
    Matrix matrix = getMatrix1x3();
    std::vector<double> right = {4, 4, 4, 4, 4, 4};
    EXPECT_ANY_THROW(matrix.solveEquation(right));
    
}
/*** Konec souboru white_box_tests.cpp ***/