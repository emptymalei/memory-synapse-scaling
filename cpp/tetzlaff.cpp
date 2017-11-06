#include <iostream>
#include <vector>
#include "includes/base.h"
#include "includes/initializer.h"
#include "includes/model.h"
#include "includes/solver.h"

using namespace std;

int main() {
    
    const int geodim = 10;
    constexpr int wdim = geodim * geodim;

    Array2D* activities_ptr = new Array2D(geodim, geodim);
    Array2D* potential_ptr = new Array2D(geodim, geodim);
    Array2D* weights_ptr = new Array2D(wdim, wdim);

    cout << (*weights_ptr)[0][0] << endl;

    // cout << Model::activity( 0.1, 1.0, 1.0, 0.5 ) << endl;

    vector<double> ef = {0.1,0.5, 0.7};
    vector<double> ew = {0.6,0.4,0.2};
    vector<double> inf = {0.7,0.9};
    vector<double> inw = {0.1,0.3};

    // Model::neighbours(ef, ew, inf, inw);





    cout << "END OF PROGRAM!" << endl;
    return 0;


}