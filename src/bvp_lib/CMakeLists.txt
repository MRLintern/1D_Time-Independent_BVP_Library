set(LIBRARY_SOURCES

"boundary_conditions.cpp"
"bvplib.cpp"
"finite_difference_method.cpp"
"linear_system.cpp"
"matrix_operations.cpp"
"vector_operations.cpp")

set(LIBRARY_HEADERS

"boundary_conditions.hpp"
"bvplib.hpp"
"finite_difference_method.hpp"
"linear_system.hpp"
"matrix_operations.hpp"
"node.hpp"
"second_order_ODE.hpp"
"vector_operations.hpp")

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC "./")

