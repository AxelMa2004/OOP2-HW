#include "linear_system.h"
#include "questions.h"
using namespace std;

void run_linearsystem_test(){
    cout << "- Test 1: Linear system with a unique solution" << endl;
    
    // Construct a 3x3 matrix A and a vector b such that det(A) != 0
    // Example system:
    // 1x + 2y + 3z = 2
    // 2x + 5y + 2z = 10
    // 6x - 3y + z = -1
    vector<double> A1 = {
        1.0, 2.0, 3.0,
        2.0, 5.0, 2.0,
        6.0, -3.0, 1.0
    };
    vector<double> b1 = {2.0, 10.0, -1.0};

    // Instantiate LinearSystem for the first case
    LinearSystem sys1(A1, b1);
    sys1.solve();
    sys1.print();  // Expected solution (1, 2, -1).

    cout << "\n- Test 2: Linear system without a unique solution (det(A) = 0)" << endl;
    
    // Construct a 3x3 matrix A with a determinant of 0 (e.g., linearly dependent rows)
    vector<double> A2 = {
        1.0, 2.0, 3.0,
        2.0, 4.0, 6.0,  // The second row is twice the first row
        0.0, 1.0, 1.0
    };
    vector<double> b2 = {1.0, 2.0, 3.0};

    // Instantiate LinearSystem for the second case
    LinearSystem sys2(A2, b2);
    sys2.solve();
    sys2.print();  // Expected message that there is no unique solution.
}
