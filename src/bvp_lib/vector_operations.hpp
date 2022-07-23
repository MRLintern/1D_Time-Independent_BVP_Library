/*

    The discretization of the ODE via finite differences results in 
    a system of linear algebraic equations, which can be reduced into 
    a matrix equation. 
    
        v = A*u, where v and u are vectors and A is a matrix
    
    This vector_operations class provides tools/methods
    for manipulating the resulting system of equations

*/
#pragma once

class Vector_Ops {

    private:

        double* m_data; //data stored in vector
        int m_size{0}; //size of vector

    public:

        Vector_Ops(const Vector_Ops& vector_u); //vector_u is some other vector
        Vector_Ops(int size);
        ~Vector_Ops();

        //getter
        int GetSize() const;
        double& operator[](int i); //zero based indexing
        //read only zero based indexing 
        double Read(int i) const;
        double& operator() (int i); //one based indexing

        //assignment
        Vector_Ops& operator = (const Vector_Ops& vector_u);
        Vector_Ops operator+() const; //unary +
        Vector_Ops operator-() const; //unary - 
        Vector_Ops operator+(const Vector_Ops& v1) const; //binary +
        Vector_Ops operator-(const Vector_Ops& v1) const; //binary -

        //scalar multiplication
        Vector_Ops operator*(double a) const;

        //p-norm method
        double Calculate_Norm(int p = 2) const; 

        //length function as a friend 
        friend int length(const Vector_Ops& v);

};
//prototype sig. of length() friend function
int length(const Vector_Ops& v);