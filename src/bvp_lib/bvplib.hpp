#pragma once

#include <string>
#include "matrix_operations.hpp"
#include "vector_operations.hpp"
#include "linear_system.hpp"
#include "finite_difference_method.hpp"
#include "second_order_ODE.hpp"
#include "boundary_conditions.hpp"

class BVP_ODE {

private:
    //instance will be created from a PDE, BCs and number of nodes in mesh
    BVP_ODE(const BVP_ODE& other_BVP_ODE) {}

    //number of nodes in grid
    int m_num_nodes{0};

    //pointer to grid 
    Finite_Difference* m_Grid{nullptr};
    //pointer to instance of of ODE
    Second_Order_ODE* m_ODE{nullptr};
    //pointer to instance of BCs
    Boundary_Conditions* m_BCs{nullptr};
    //vector for solution
    Vector_Ops* m_Solution_Vec{nullptr};
    //right hand side vector
    Vector_Ops* m_RHS_Vector{nullptr};
    //matrix for linear system
    Matrix_Ops* m_Matrix{nullptr};
    //linear system produced
    Linear_System* m_Linear_System{nullptr};
    //user can put results in a file; name below
    std::string m_File_Name;

    //methods for setting up linear system and solving it
    void populate_matrix();
    void populate_vector();
    void apply_boundary_conditions();

public:

    BVP_ODE(Second_Order_ODE* pODE, Boundary_Conditions* pBCs, int num_nodes);

    //destroy object
    ~BVP_ODE();

    void Set_File_Name(const std::string& name) {

        m_File_Name = name;
    }

    void solve();
    void Write_Solution_File();

};