#include <iostream>
#include <fstream>
#include <cassert>
#include "bvplib.hpp"

BVP_ODE::BVP_ODE(Second_Order_ODE* pODE, Boundary_Conditions* pBCs, int num_nodes) {

    m_ODE = pODE;
    m_BCs = pBCs;

    m_num_nodes = num_nodes;
    //allocate memory for gird 
    m_Grid = new Finite_Difference(m_num_nodes, pODE -> m_X_min, pODE -> m_X_max);

    //allocate memory for solution vector 
    m_Solution_Vec = new Vector_Ops(m_num_nodes);
    //allocate memory for vector
    m_RHS_Vector = new Vector_Ops(m_num_nodes);
    //allocate memory for matrix 
    m_Matrix = new Matrix_Ops(m_num_nodes, m_num_nodes);

    //file for solution data
    m_File_Name = "ODE_Solution_Data.dat";
    //solution not yet found
    m_Linear_System = nullptr;

}
//free allocated memory
BVP_ODE::~BVP_ODE() {

    delete m_Solution_Vec;
    delete m_RHS_Vector;
    delete m_Matrix;
    delete m_Grid;

    //delete if solve() has been called
    if(m_Linear_System) {

        delete m_Linear_System;
    }
}
//call solve() 
void BVP_ODE::solve() {

    populate_matrix();
    populate_vector();
    apply_boundary_conditions();

    m_Linear_System = new Linear_System(*m_Matrix, *m_RHS_Vector);

}
//populate the matrix
void BVP_ODE::populate_matrix() {

    for(int i{1}; i < m_num_nodes - 1; i++) {

        //shorten definitions
        //xm is x(i-1)
        //x is x(i)
        //xp is x(i+1)
        //did this to reduce typo errors

        double xm = m_Grid -> m_Nodes[i - 1].coordinate;
        double x = m_Grid -> m_Nodes[i].coordinate;
        double xp = m_Grid -> m_Nodes[i].coordinate;

        double alpha = 2.0/(xp - xm)/(x - xm);
        double beta = -2.0/(xp - x)/(x - xm);
        double gamma = 2.0/(xp - xm)/(xp - x);

        (*m_Matrix)(i + 1, i) = (m_ODE -> m_coefficient_Uxx)*alpha - (m_ODE -> m_coefficient_Ux)/(xp - xm);
        (*m_Matrix)(i + 1, i + 1) = (m_ODE -> m_coefficient_Uxx)*beta + m_ODE -> m_coefficient_U;
        (*m_Matrix)(i + 1, i + 2) = (m_ODE -> m_coefficient_Uxx)*gamma + (m_ODE -> m_coefficient_Ux)/(xp - xm);
        
    }
}
void BVP_ODE::populate_vector() {

    for(int i{1}; i < m_num_nodes; i++) {

        double x = m_Grid -> m_Nodes[i].coordinate;
        
        (*m_RHS_Vector)(i + 1) = m_ODE -> m_source_function(x);
    }
}
void BVP_ODE::apply_boundary_conditions() {

    bool LHS_BC_Applied = false;
    bool RHS_BC_Applied = false;

    //if()
}

    