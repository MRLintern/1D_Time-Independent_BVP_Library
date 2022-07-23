#include <cmath>
#include <iostream>
#include <cassert>
#include "vector_operations.hpp"

//overriden copy constructor allocates memory
//for new vector v1 and copies elements of vector_u
//into it
Vector_Ops::Vector_Ops(const Vector_Ops& vector_u) {


    m_size = vector_u.GetSize();
    m_data = new double [m_size];

    for(int i{0}; i < m_size; i++) {m_data[i] = vector_u.m_data[i];}
}
//constructor for vector of a given size allocates memory
//and initialises elements to 0

Vector_Ops::Vector_Ops(int size) {

    assert(size > 0);
    m_size = size;
    m_data = new double [m_size];

    for(int i{0}; i < m_size; i++) {m_data[i] = 0.0;}

}
//overidden destructor to correctly free memory
Vector_Ops::~Vector_Ops() {

    delete[] m_data;
}
//method to get size of vector
int Vector_Ops::GetSize() const {

    return m_size;
}
//overloading square brackets
double& Vector_Ops::operator[] (int i) {

    assert(i > -1);
    assert(i < m_size);

    return m_data[i];
}
//read only variant of []
double Vector_Ops::Read(int i) const {

    assert(i > -1);
    assert(i < m_size);

    return m_data[i];
}
//overload round brackets () 
double& Vector_Ops::operator() (int i) {

    assert(i > 0);
    assert(i < m_size+1);

    return m_data[i - 1];
}
//overload assignment operator
Vector_Ops& Vector_Ops::operator=(const Vector_Ops& vector_u) {

    assert(m_size == vector_u.m_size);

    for(int i{0}; i < m_size; i++) {m_data[i] = vector_u.m_data[i];}

    return *this;
}
//overload unary + operator
Vector_Ops Vector_Ops::operator+() const {

    Vector_Ops v(m_size);

    for(int i{0}; i < m_size; i++) {v[i] = m_data[i];}

    return v;
}
//overload the unary - operator
Vector_Ops Vector_Ops::operator-() const {

    Vector_Ops v(m_size);

    for(int i{0}; i < m_size; i++) {v[i] = -m_data[i];}

    return v;
}
//overload binary + operator
Vector_Ops Vector_Ops::operator+(const Vector_Ops& v1) const {

    assert(m_size == v1.m_size);

    Vector_Ops v(m_size);

    for(int i{0}; i < m_size; i++) {v[i] = m_data[i] + v1.m_data[i];}

    return v;
}
//overload the binary - operator
Vector_Ops Vector_Ops::operator-(const Vector_Ops& v1) const {

    assert(m_size == v1.m_size);
    Vector_Ops v(m_size);

    for(int i{0}; i < m_size; i++) {v[i] = m_data[i] - v1.m_data[i];}

    return v;
}
//overload scalar multiplication
Vector_Ops Vector_Ops::operator*(double a) const {

    Vector_Ops v(m_size);

    for(int i{0}; i < m_size; i++) {v[i] = a*m_data[i];}

    return v;
}
//method to calculate norm; default: p=2
//this is the Euclidean norm
double Vector_Ops::Calculate_Norm(int p) const {

    double normed_value, sum = 0.0;

    for(int i{0}; i < m_size; i++) {sum += pow(fabs(m_data[i]), p);}

    normed_value = pow(sum, 1.0/((double)(p)));

    return normed_value;
}
//get size of vector
int length(const Vector_Ops& v) {return v.m_size;}

