#include <cmath>
#include <cassert>
#include "matrix_operations.hpp"
#include "vector_operations.hpp"

//overwritten copy constructor
//allocates memory for new matrix
//and copies elements into the new matrix
Matrix_Ops::Matrix_Ops(const Matrix_Ops& matrix_u) {

    m_num_rows = matrix_u.m_num_rows;
    m_num_cols = matrix_u.m_num_cols;
    m_data = new double* [m_num_rows];

    for(int i{0}; i < m_num_rows; i++) {m_data[i] = new double [m_num_cols];}

    for(int i = 0; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            m_data[i][j] = matrix_u.m_data[i][j];
        }
    }
}
//constructor for vector of given length
//allocates memory and initialises elements
Matrix_Ops::Matrix_Ops(int num_rows, int num_cols) {

    assert(num_rows > 0);
    assert(num_cols > 0);
    m_num_rows = num_rows;
    m_num_cols = num_cols;

    m_data = new double* [m_num_rows];

    for(int i{0}; i < m_num_rows; i++) {m_data[i] = new double [m_num_cols];}

    for(int i = 0; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            m_data[i][j] = 0.0;
        }
    }
}
//overwritten destructor to correctly free memory
Matrix_Ops::~Matrix_Ops() {

    for(int i{0}; i < m_num_rows; i++) {delete[] m_data[i];} delete[] m_data;
}
//method to get number of rows of matrix
int Matrix_Ops::Get_Number_Of_Rows() const {return m_num_rows;}

//method to get number of columns of matrix
int Matrix_Ops::Get_Number_Of_Columns() const {return m_num_cols;}

//overload round brackets
double& Matrix_Ops::operator() (int i, int j) {

    assert(i > 0);
    assert(i < m_num_rows+1);
    assert(j > 0);
    assert(j < m_num_cols+1);

    return m_data[i - 1][j - 1];
}
//overload assignment operator
Matrix_Ops& Matrix_Ops::operator=(const Matrix_Ops& matrix_u) {

    assert(m_num_rows = matrix_u.m_num_rows);
    assert(m_num_cols = matrix_u.m_num_cols);

    for(int i = 0; i < m_num_rows; i++) {

        for(int j = 0; j < m_num_cols; j++) {

            m_data[i][j] = matrix_u.m_data[i][j];
        }
    }
    return *this;
}
//overload the unary + operator
Matrix_Ops Matrix_Ops::operator+() const {

    Matrix_Ops matrix(m_num_rows, m_num_cols);

    for(int i{0}; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            matrix(i + 1, j + 1) = m_data[i][j];
        }
    }
    return matrix; 
}
//overload the unary - operator
Matrix_Ops Matrix_Ops::operator-() const {

    Matrix_Ops matrix(m_num_rows, m_num_cols);

    for(int i{0}; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            matrix(i + 1, j + 1) = -m_data[i][j];
        }
    }
    return matrix; 
}
//overload binary + operator
Matrix_Ops Matrix_Ops::operator+(const Matrix_Ops& m1) const {

    assert(m_num_rows == m1.m_num_rows);
    assert(m_num_cols == m1.m_num_cols);

    Matrix_Ops matrix(m_num_rows, m_num_cols);

    for(int i{0}; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            matrix(i + 1, j + 1) = m_data[i][j] + m1.m_data[i][j];
        }
    }
    return matrix;
}
//overload the binary - operator
Matrix_Ops Matrix_Ops::operator-(const Matrix_Ops& m1) const {

    assert(m_num_rows == m1.m_num_rows);
    assert(m_num_cols == m1.m_num_cols);

    Matrix_Ops matrix(m_num_rows, m_num_cols);

    for(int i{0}; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            matrix(i + 1, j + 1) = m_data[i][j] - m1.m_data[i][j];
        }
    }
    return matrix;

}
//overload scalar multiplication
Matrix_Ops Matrix_Ops::operator*(double a) const {

    Matrix_Ops matrix(m_num_rows, m_num_cols);

    for(int i{0}; i < m_num_rows; i++) {

        for(int j{0}; j < m_num_cols; j++) {

            matrix(i + 1, j + 1) = a*m_data[i][j];
        }
    }
    return matrix;
}
//overload matrix multiplied by a vector
Vector_Ops operator*(const Matrix_Ops& m, const Vector_Ops& v) {

    int original_vector_size {v.GetSize()};

    assert(m.Get_Number_Of_Columns() == original_vector_size);

    int new_vector_length = m.Get_Number_Of_Rows();

    Vector_Ops new_vector(new_vector_length);

    for(int i{0}; i < new_vector_length; i++) {

        for(int j{0}; j < new_vector_length; j++) {

            new_vector[i] += m.m_data[i][j]*v.Read(j);
        }
    }
    return new_vector;
}
//overloading vector multiplied by a matrix
Vector_Ops operator*(const Vector_Ops& v, const Matrix_Ops& m) {

    int original_vector_size {v.GetSize()};

    assert(m.Get_Number_Of_Rows() == original_vector_size);

    int new_vector_length = m.Get_Number_Of_Columns();

    Vector_Ops new_vector(new_vector_length);

    for(int i{0}; i < new_vector_length; i++) {

        for(int j{0}; j < original_vector_size; j++) {

            new_vector[i] += v.Read(j)*m.m_data[i][j];
        }
    }
    return new_vector;

}
//calculate determinant of square matrix (recursively)
double Matrix_Ops::Calculate_Determinant() const {

    assert(m_num_rows == m_num_cols);
    
    double determinant {0.0};

    if(m_num_rows == 1) {

        determinant = m_data[0][0];
    }
    else {

        //more than 1 entry
        for(int i_outer{0}; i_outer < m_num_rows; i_outer++) {

            Matrix_Ops sub_matrix(m_num_rows - 1, m_num_cols - 1);

            for(int i{0}; i < m_num_rows; i++) {

                for(int j{0}; j < i_outer; j++) {

                    sub_matrix(i + 1, j + 1) = m_data[i + 1][j];
                }
                for(int j {i_outer}; j < m_num_rows; j++) {

                    sub_matrix(i + 1, j + 1) = m_data[i + 1][j + 1];
                }
            }
            double sub_matrix_determinant = sub_matrix.Calculate_Determinant();
        }
    }
    return determinant;

}