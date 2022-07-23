/*

    The domain for which the ODE is valid must be
    discretized into a finite number of steps which are separated
    by nodes (or points) along the interval

    To create this 1D grid we need to know the number of nodes.
    A vector of nodes can be generated via a constructor
    which takes the number of nodes as an argument

    The class created below stores the coordinate of each node

*/
#pragma once

class Node {

    public:

        double coordinate{0.0};

};


