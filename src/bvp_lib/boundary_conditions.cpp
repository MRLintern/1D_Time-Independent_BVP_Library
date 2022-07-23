#include <cassert>
#include "boundary_conditions.hpp"

Boundary_Conditions::Boundary_Conditions() {

    m_Dirichlet_LHS_BC = false;
    m_Dirichlet_RHS_BC = false;
    m_Neumann_LHS_BC = false;
    m_Neumann_RHS_BC = false;

}
//set up BCs
void Boundary_Conditions::set_LHS_BC_Dirichlet(double LHS_BC_Value) {

    assert(!m_Neumann_LHS_BC);
    m_Dirichlet_LHS_BC = true;
    m_LHS_BC_Value = LHS_BC_Value;   
}
void Boundary_Conditions::set_RHS_BC_Dirichlet(double RHS_BC_Value) {

    assert(!m_Neumann_RHS_BC);
    m_Dirichlet_RHS_BC = true;
    m_RHS_BC_Value = RHS_BC_Value;
}
void Boundary_Conditions::set_LHS_BC_Neumann(double Neumann_LHS_BC) {

    assert(!m_Dirichlet_LHS_BC);
    m_Neumann_LHS_BC = true;
    m_LHS_BC_Value = Neumann_LHS_BC;
}
void Boundary_Conditions::set_RHS_BC_Neumann(double Neumann_RHS_BC) {

    assert(!m_Dirichlet_RHS_BC);
    m_Neumann_LHS_BC = true;
    m_RHS_BC_Value = Neumann_RHS_BC;
}


