#include <iostream>
#include <fstream>
#include <vector>
#include "includes/base.h"
#include "includes/initializer.h"
#include "includes/model.h"
#include "includes/solver.h"
#include "includes/recorder.h"

using namespace std;

int main() {
    
    const int geodim = 10;
    int geodimA[2];
    geodimA[0] = geodim;
    geodimA[1] = geodim;
    constexpr int wdim = geodim * geodim;

    // params: {alpha, beta, epsilon, tau, resistance}
    vector<double> pms = {0.1, 0.1, 0.1, 0.1, 0.1};
    // wparams: {double mu, double kappa, double actt}
    vector<double> wpms = {1.0, 1.0, 1.0};
    // extparams: {double w, double freq, double bg}
    vector<double> extpms = { 0.1, 1.0, 1.0 }; 

    
    ofstream data("data.csv" ); 

    Array2D* activities_ptr = new Array2D(geodim, geodim);
    Array2D* potential_ptr = new Array2D(geodim, geodim);
    Array2D* weights_inh_ptr = new Array2D(wdim, wdim);
    Array2D* weights_ext_ptr = new Array2D(wdim, wdim);
    Array2D* Tactivities_ptr = new Array2D(geodim, geodim);
    Array2D* Tpotential_ptr = new Array2D(geodim, geodim);
    Array2D* Tweights_inh_ptr = new Array2D(wdim, wdim);
    Array2D* Tweights_ext_ptr = new Array2D(wdim, wdim);

    cout << (*weights_inh_ptr)[0][0] << endl;

    // cout << Model::activity( 0.1, 1.0, 1.0, 0.5 ) << endl;

    vector<double> ef = {0.1,0.5, 0.7};
    vector<double> ew = {0.6,0.4,0.2};
    vector<double> inf = {0.7,0.9};
    vector<double> inw = {0.1,0.3};

    // Model::neighbours(ef, ew, inf, inw);

    // Solver
    // Solver::euler( Array2D* actA2, Array2D* potA2, Array2D* weiEA2, Array2D* weiIA2, Array2D* TactA2, Array2D* TpotA2, Array2D* TweiEA2, Array2D* TweiIA2, int geodim[2], double dt, vector<double> params, vector<double> wparams, vector<double> extparams ){
    //   Solver::euler( activities_ptr, potential_ptr, weights_ext_ptr, weights_inh_ptr, Tactivities_ptr, Tpotential_ptr, Tweights_ext_ptr, Tweights_inh_ptr, geodimA, 0.01, pms, wpms, extpms);

    // Recorder

    Recorder::record_state(activities_ptr, 10, data);


    cout << "END OF PROGRAM!" << endl;
    return 0;


}