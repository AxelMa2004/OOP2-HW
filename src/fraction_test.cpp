#include "fraction.h"
#include "questions.h"
#include <sstream>


void test_fraction(){
    const auto check = [](bool condition, const char* message) {
        if (!condition) throw std::logic_error(message);
    };

    {
        // Test constructors
        Fraction f1;
        Fraction f2(2);
        Fraction f3(5, 3);

        check(f1.getNom() == 0 && f1.getDenom() == 1, "Default fraction failed.");
        check(f2.getNom() == 2 && f2.getDenom() == 1, "Integer constructor failed.");
        check(f3.getNom() == 5 && f3.getDenom() == 3, "Two-argument constructor failed.");
        
        std::cout << "f1: ";
        f1.print();

        std::cout << "f2: ";
        f2.print();
        
        std::cout << "f3: ";
        f3.print();
        
        bool caught = false;
        try{
            Fraction(3, 0);
        }
        catch(const std::logic_error& e){
            caught = true;
            std::cout << "Logic error:" << e.what() << "\n";
        }
        check(caught, "A zero denominator must throw.");

        std::ostringstream printed;
        auto* previous = std::cout.rdbuf(printed.rdbuf());
        f3.print();
        std::cout.rdbuf(previous);
        check(printed.str() == "5/3\n", "Fraction print format failed.");
    }
    
    {
        // Test reduce
        Fraction f(11*12, 11*(-39));
        f.reduce();  // 4 / (-13)
        check(f.getNom() == 4 && f.getDenom() == -13, "Reduction failed.");
        std::cout << "Reduced fraction: ";
        f.print();
    }
    
    
    {
        Fraction f(3, 4);
        Fraction inverse = f.reciprocal();
        check(inverse.getNom() == 4 && inverse.getDenom() == 3, "Reciprocal failed.");
        std::cout << "f^{-1} = ";
        inverse.print();
        
        bool caught = false;
        try{
            Fraction f;
            f.reciprocal();
        }
        catch(const std::logic_error& e){
            caught = true;
            std::cout << "Logic error:" << e.what() << "\n";
        }
        check(caught, "The reciprocal of zero must throw.");
    }
    
    {
        // Test add and mult
        Fraction f1(3, 4);
        Fraction f2(7, 5);
        Fraction f3(2, 9);
        Fraction sum = f1.add(f2);
        Fraction product = f1.mult(f2);
        Fraction reduced_product = f1.mult(f3);
        check(sum.getNom() == 43 && sum.getDenom() == 20, "Addition failed.");
        check(product.getNom() == 21 && product.getDenom() == 20, "Multiplication failed.");
        check(reduced_product.getNom() == 1 && reduced_product.getDenom() == 6,
              "Product reduction failed.");
        
        std::cout << "f1 + f2 = ";
        sum.print();
        
        std::cout << "f1 * f2 = ";
        product.print();
        
        std::cout << "f1 * f3 = ";
        reduced_product.print();
    }

    {
        // Copies keep their own values. Leaving this block also exercises destruction.
        Fraction original(6, 8);
        Fraction copied(original);
        original.reduce();
        check(copied.getNom() == 6 && copied.getDenom() == 8, "Copy constructor failed.");
        check(original.getNom() == 3 && original.getDenom() == 4, "Source reduction failed.");

        Fraction assigned;
        check(&(assigned = copied) == &assigned, "Assignment must return this object.");
        copied.reduce();
        check(assigned.getNom() == 6 && assigned.getDenom() == 8, "Copy assignment failed.");
        Fraction& self = assigned;
        assigned = self;
        check(assigned.getNom() == 6 && assigned.getDenom() == 8, "Self-assignment failed.");
    }
    std::cout << "Fraction checks passed.\n";
}
