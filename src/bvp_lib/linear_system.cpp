#include <cmath>
#include <cassert>
#include "linear_system.hpp"
#include "matrix_operations.hpp"
#include "vector_operations.hpp"

/*

copy matrix and vector so original ones specified don't change
after Gaussian elimination is performed

*/

Linear_System::Linear_System(const Matrix_Ops& A, const Vector_Ops& vec) {

    //check vector and matrix are same size
    int correct_size {A.Get_Number_Of_Rows()};

    assert(A.Get_Number_Of_Columns() == correct_size);
    assert(vec.GetSize() == correct_size);

    //variables for system
    m_size = correct_size;
    m_A = new Matrix_Ops(A);
    m_vec = new Vector_Ops(vec);

}

//free memory
Linear_System::~Linear_System() {

    delete m_A;
    delete m_vec;

}
//solve system via Gaussian elimination
Vector_Ops Linear_System::solve() {

    Vector_Ops m(m_size);
    Vector_Ops solution(m_size);

    Matrix_Ops& ref_A = *m_A;
    Vector_Ops& ref_vec = *m_vec;

    //forward sweep
    for(int k{0}; k < m_size - 1; k++) {

        double max{0.0};
        int row{-1};

        for(int i{k}; i < m_size; i++) {

            if(fabs(ref_A(i + 1, k + 1)) > max) {

                row = i;
                max = fabs(ref_A(i + 1, k + 1));
            }
        }
        assert(row >= 0);

        //pivot if need to
        if(row != k) {

            //swap matrix rows k+1 with row+1
            for(int i{0}; i < m_size; i++) {

                double swap = ref_A(k + 1, i + 1);

                ref_A(k + 1, i + 1) = ref_A(row + 1, i + 1);
                ref_A(row + 1, i + 1) = swap;
            }
            //swap vector entries k+1 with row+1
            double swap = ref_vec(k + 1);

            ref_vec(k + 1) = ref_vec(row + 1);
            ref_vec(row + 1) = swap;
        }
        //create zeros in lower part of col. k
        for(int i{k + 1}; i < m_size; i++) {

            m(i + 1) = ref_A(i + 1, k + 1)/ref_A(k + 1, k + 1);

            for(int j{k}; j < m_size; j++) {

                ref_A(i + 1, j + 1) -= ref_A(k + 1, j + 1)*m(i + 1);
            }
            ref_vec(i + 1) -= ref_vec(k + 1)*m(i + 1);
        }
    }
    //back substitution
    for(int i{m_size - 1}; i > -1; i--) {

        solution(i + 1) = ref_vec(i + 1);

        for(int j{i + 1}; j < m_size; j++) {

            solution(i+1) = ref_A(i + 1, j + 1)*solution(j + 1);
        }
        solution(i+1) /= ref_A(i + 1, i + 1);
    }
    return solution; 
}

