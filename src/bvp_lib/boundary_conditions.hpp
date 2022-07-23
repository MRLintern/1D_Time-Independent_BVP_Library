/*

Now consider the boundary conditions (BCs) for the ODE. 2 to consider

    1. Dirichlet: value of u(x) on LHS and RHS of domain
    2. Neumann: value of u'(x) on LHS and RHS of domain

    Can't choose a mixture of both BCs

*/
#pragma once

class Boundary_Conditions {


    public:

        //allow BVP_ODE class access to coefficients.
        //NB: BVP_ODE = BoundaryValueProblem_OrdinaryDifferentialEquation
        friend class BVP_ODE;

    private:

        //Dirichlet BCs
        bool m_Dirichlet_LHS_BC;
        bool m_Dirichlet_RHS_BC;
        //Neumann BCs
        bool m_Neumann_LHS_BC;
        bool m_Neumann_RHS_BC;
        //BC values at ends of domain
        double m_LHS_BC_Value{0.0};
        double m_RHS_BC_Value{0.0};

    public:

        //default constructor
        Boundary_Conditions();
        //setter methods
        ////////////////
        //Dirichlet
        void set_LHS_BC_Dirichlet(double LHS_BC_Value);
        void set_RHS_BC_Dirichlet(double RHS_BC_Value);
        //Neumann
        void set_LHS_BC_Neumann(double LHS_BC_Derivative_Value);
        void set_RHS_BC_Neumann(double RHS_BC_Derivative_Value);

};
