#include "questions.h"
#include "quadratic.h"
#include <vector>


void q1_2(){
    std::vector<QuadraticEquation> equations = {
        QuadraticEquation(1, -2, 1),
        QuadraticEquation(1, -3, 2),
        QuadraticEquation(1, 0, 1)
    };
    
    for (size_t i = 0; i < equations.size(); ++i) {
        try {
            equations[i].solve();
        } catch (const std::exception& e) {
            std::cout << "Equation " << (i + 1) << " failed: " << e.what() << '\n';
        }
    }
    
    // Handling invalid constructor parameters explicitly
    try {
        QuadraticEquation q4(0, 1, 2);
        q4.solve();
    } catch (const std::invalid_argument& e) {
        std::cout << "Failed to process q4: " << e.what() << '\n';
    }
}