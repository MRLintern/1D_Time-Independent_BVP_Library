/*

    Finite Difference Method 
    ------------------------

    This is a numerical technique for solving differential equations
    by approximating derivatives with finite differences.
    The domain/interval is discretized into a finite number of steps and
    the value of the solution at these discrete points/nodes is approximated
    by solving the resulting system of algebraic equations; these are transformed
    into a matrix equation. 

    interval:

        X_min: x---x---x---x---x: X_max; each x represents a node; simple geometry; differences are equal between each node

*/
#pragma once

#include <vector>
#include "node.hpp"

class Finite_Difference {

    public:

        //BVP_ODE class access to nodes
        friend class BVP_ODE;

    private:

        std::vector<Node> m_Nodes; //Nodes of interval

    public:

        Finite_Difference(int number_nodes, double X_min, double X_max);

};