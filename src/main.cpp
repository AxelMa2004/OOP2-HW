/*
GenAI assistance

By hand
I wrote the original classes, tests and notes.

AI did
AI checked my explanations of copy elision and BFS, reviewed the code,
and helped make the small corrections in this version.

I changed
This revision fixes cache invalidation, result updates and input checks.
It also adds self-checks and completes the answers below.

==== Question 1 ====
a. Which constructor is called for Point p4 = Point(40)?
Only the input constructor is called. I first expected a temporary object
followed by a copy. C++17 guarantees copy elision here, so Point(40)
constructs p4 directly. This declaration initializes a new object.

b. What changes with Point& operator=(const Point p)?
The by-value version first copy-constructs the parameter, then runs the
assignment body. The parameter is also destroyed after the call.
For p3 = p2, this adds a copy-constructor message and a destructor message.
The const-reference version only prints the assignment message.
point.h uses the by-value version for this part of the exercise.

==== Question 3 ====
Do I need to define the other special member functions?
The compiler-generated copy constructor, copy assignment and destructor
are sufficient because Fraction only stores two int values.

==== Question 7 ====
One run with the project's Clang C++17 flags took 1642 ms for operator
addition and 586 ms for triple_add. Both totals cover 100 iterations
of 1000 x 1000 matrices, and the final results compared equal.
operator+ builds an intermediate matrix and traverses the entries
twice. triple_add computes each final entry in a single pass.
Both approaches perform two scalar additions per entry.
*/



#include "questions.h"


int main(){
    generate_title("1-1");
    q1_1();
    
    generate_title("1-2");
    q1_2();

    
    generate_title("1-3");
    test_fraction();
    
    generate_title("1-4");
    run_linearsystem_test();
 
    generate_title("1-5");
    run_digragh_test();

    
    generate_title("1-6");
    run_matrix_test();
    
    generate_title("1-7");
    run_matrix_addition_test();
}
