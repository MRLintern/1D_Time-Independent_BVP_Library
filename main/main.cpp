#include <string>
#include <cmath>
#include "boundary_value_problem_ODE.hpp" //the library

#include <fmt/format.h> //formatting library
#include <spdlog/spdlog.h> //logging library

//testing 2 models

double test_model_1(double x) {return 1.0;}
double test_model_2(double x) {return 34.0*sin(x);}

int main(int argc, char* argv[]) {

    //model 1

    Second_Order_ODE ODE_test_model_1(-1.0, 0.0, 0.0, test_model_1, 0.0, 1.0);

    Boundary_Conditions BC_test_model_1;
    BC_test_model_1.set_LHS_BC_Dirichlet(0.0);
    BC_test_model_1.set_RHS_BC_Dirichlet(0.0);

    BVP_ODE bvp_ode_test_model_1(&ODE_test_model_1, &BC_test_model_1, 101);
    bvp_ode_test_model_1.Set_File_Name("model_1_results.dat");
    bvp_ode_test_model_1.solve();

    //model 2
    Second_Order_ODE ODE_test_model_2(1.0, 3.0, -4.0, test_model_2, 0.0, M_PI);

    Boundary_Conditions BC_test_model_2;
    BC_test_model_2.set_LHS_BC_Neumann(-5.0);
    BC_test_model_2.set_RHS_BC_Dirichlet(4.0);

    BVP_ODE bvp_ode_test_model_2(&ODE_test_model_2, &BC_test_model_2, 1001);
    bvp_ode_test_model_2.Set_File_Name("model_2_results.dat");
    bvp_ode_test_model_2.solve();

}
