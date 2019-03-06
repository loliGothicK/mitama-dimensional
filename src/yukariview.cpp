#include "../include/dimensional/quantity.hpp"
#include "../include/dimensional/arithmetic.hpp"
#include "../include/dimensional/io.hpp"
#include "../include/dimensional/refinement.hpp"
#include "../include/dimensional/prefix.hpp"
#include "../include/dimensional/math/all.hpp"
#include "../include/dimensional/currency/jpy.hpp"
#include "../include/dimensional/expr.hpp"
#include "../include/dimensional/nonsi_units/nonsi_dgree_angle.hpp"
#include <boost/type_index.hpp>
#include <iostream>


#define REPL(...) \
    do { std::cout << "$ " << #__VA_ARGS__ << "\n=> " << (__VA_ARGS__) << std::endl; } while(false)

int main(){
    using namespace mitama;

    { // User defined dimension examples
        // currency units
        REPL(90|dgree_angle);
        quantity<radian_t> s( 90|dgree_angle );
        REPL(s);
    }
        {
        REPL(1|radian);
        quantity<dgree_angle_t> hoge = (1|radian);
        REPL(hoge);
    }
}
