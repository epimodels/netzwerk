// Simple SIR model implemented with odeint

#include <iostream>
#include <array>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

const double b = 0.1;
const double g = 0.05;

using std::array<double, 3> = state_type;

void sir( const state_type &x , state_type &dxdt , double t )
{
    dxdt[0] = -b * x[0] * x[1];
    dxdt[1] = b * x[0] * x[1] - g * x[1];
    dxdt[2] = g * x[1];
}

void write_sir(const state_type &x , const double t )
{
    std::cout << t << ' ' << x[0] << ' ' << x[1] << ' ' << x[2] << std::endl;
}

int main(int argc, char **argv)
{
    state_type x = { 0.99 , 0.01 , 0.0 }; // initial conditions
    integrate( sir , x , 0.0 , 200.0 , 0.1 , write_sir );
}
