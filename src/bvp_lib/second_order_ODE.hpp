/*

we consider a 2nd order ODE on the interval x0 < x < x1

general form: A*u''(x) + B*u'(x) + C*u(x) = f(x)

A,B & C are coefficients
u''(x) 2nd derivate of solution
u'(x) 1st derivate of solution
u(x) is the solution
f(x) is the source function

This class specifies the coefficients, the source function and the interval
the ODE is valid

The user specifies these members via a constructor

*/
#pragma once

class Second_Order_ODE {

    //allow BVP_ODE class access to coefficients.
    //NB: BVP_ODE = BoundaryValueProblem_OrdinaryDifferentialEquation
    friend class BVP_ODE;

    private:

        //coefficients of ODE
        double m_coefficient_Uxx{0}; //A
        double m_coefficient_Ux{0}; //B
        double m_coefficient_U{0}; //C

        //source function
        double (*m_source_function) (double x);

        //interval: x0 < x < x1
        double m_X_min{0}; //x0
        double m_X_max{0}; //x1

    public:

        //constructor to allow user to specify parameters of ODE
        Second_Order_ODE(double coefficient_Uxx, double coefficient_Ux, double coefficient_U, double (*source_func) (double), double X_minimum, double X_maximum) {


            m_coefficient_Uxx = coefficient_Uxx;
            m_coefficient_Ux = coefficient_Ux;
            m_coefficient_U = coefficient_U;
            m_source_function = source_func;
            m_X_min = X_minimum;
            m_X_max = X_maximum;
        }
};