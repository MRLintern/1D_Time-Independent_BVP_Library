#include <cassert>
#include "finite_difference_method.hpp"
#include "node.hpp"

Finite_Difference::Finite_Difference(int num_nodes, double X_min, double X_max) {

    //differences between nodes
    double step_size = (X_max - X_min)/((double)(num_nodes - 1));

    for(int i{0}; i < num_nodes; i++) {

        //make a node 
        Node node;

        //going from node to node until prescribed amount is reached.
        node.coordinate = X_min + i*step_size;

        //put all the all nodes into the nodes vector, m_Nodes
        m_Nodes.push_back(node);
    }
    //makes sure the number of nodes "collected" is the
    //same as the number of nodes required by the user
    assert(m_Nodes.size() == num_nodes);
}