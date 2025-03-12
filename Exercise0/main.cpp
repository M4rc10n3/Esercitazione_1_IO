#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <numbers>

int main()
{
    
    std::cout << std::numeric_limits<int>::min() << " "
     << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::setprecision(16) << std::scientific;
    std::cout << std::numbers::pi << std::endl;
    return 0;
    
}
