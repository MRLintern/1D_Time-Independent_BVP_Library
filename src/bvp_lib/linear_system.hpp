//class allows us to solve matrix equations
#pragma once 

#include "vector_operations.hpp"
#include "matrix_operations.hpp"

class Linear_System {

    private:

        int m_size{0}; //size of linear system
        Matrix_Ops* m_A; //matrix for linear system
        Vector_Ops* m_vec; //vector for linear system

        //constructor specifies matrix and vector
        Linear_System(const Linear_System& other_Linear_System) {};

    public:

        //copy constructor
        Linear_System(const Matrix_Ops& A, const Vector_Ops& vec);

        //destroy memory allocated
        ~Linear_System();

        //method to solve linear system
        virtual Vector_Ops solve();

};