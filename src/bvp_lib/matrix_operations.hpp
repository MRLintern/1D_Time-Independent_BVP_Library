//class for matrix operations
#pragma once

#include "vector_operations.hpp"

class Matrix_Ops {

    private:

        double** m_data; //elements of matrix
        int m_num_rows{0}, m_num_cols{0}; //dimensions of matrix

    public:

        //constructors
        Matrix_Ops(const Matrix_Ops& matrix_u); //matrix_u is some other matrix type
        Matrix_Ops(int num_rows, int num_cols);
        //deconstructor
        ~Matrix_Ops();

        //getter methods
        int Get_Number_Of_Rows() const; 
        int Get_Number_Of_Columns() const;
        //1 based indexing
        double& operator() (int i, int j);
        //overloaded assignment operator
        Matrix_Ops& operator=(const Matrix_Ops& matrix_u);
        Matrix_Ops operator+() const; //unary + 
        Matrix_Ops operator-() const; // unary -
        Matrix_Ops operator+(const Matrix_Ops& m1) const; //binary +
        Matrix_Ops operator-(const Matrix_Ops& m1) const; // binary -
        //scalar multiplication
        Matrix_Ops operator*(double a) const;
        //calculating the determinant of matrix
        double Calculate_Determinant() const;
        //vector multiplication friendship
        friend Vector_Ops operator*(const Matrix_Ops& m, const Vector_Ops& v);
        friend Vector_Ops operator*(const Vector_Ops& v, const Matrix_Ops& m);

};
//prototype sigs. for friend operators
Vector_Ops operator*(const Matrix_Ops& m, const Vector_Ops& v);
Vector_Ops operator*(const Vector_Ops& v, const Matrix_Ops& m);
