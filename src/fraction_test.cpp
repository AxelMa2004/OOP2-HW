#include "fraction.h"
#include "questions.h"


void run_fraction_test(){
    {
        // Test constructors
        Fraction f1;
        Fraction f2(2);
        Fraction f3(5, 3);
        
        std::cout << "f1: ";
        f1.print();

        std::cout << "f2: ";
        f2.print();
        
        std::cout << "f3: ";
        f3.print();
        
        try{
            Fraction(3, 0);
        }
        catch(const std::logic_error& e){
            std::cout << "Logic error:" << e.what() << "\n";
        }
    }
    
    {
        // Test reduce
        Fraction f(11*12, 11*(-39));
        f.reduce();  // 4 / (-13)
        std::cout << "Reduced fraction: ";
        f.print();
    }
    
    {
        // Test add and mult
        Fraction f1(3, 4);
        Fraction f2(7, 5);
        
        std::cout << "f1 + f2 = ";
        f1.add(f2).print();
        
        std::cout << "f1 * f2 = ";
        f1.mult(f2).print();
    }
}