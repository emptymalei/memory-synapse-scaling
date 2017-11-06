#include <iostream>
#include "includes/base.h"
#include "includes/initializer.h"
#include "includes/model.h"

using namespace std;

int main() {

    // Neurons Grid: frequency or potential at each point
    double** freqArray = new double*[row];
    for(int i=0;i < row; i++) {
        freqArray[i] = new double[col];
    } 

    // Potential array
    double** potArray = new double*[row];
    for(int i=0;i < row; i++) {
        potArray[i] = new double[col];
    }

    // Weight array
    double** wArray = new double*[wd];
    for(int i=0; i< wd; i++){
        wArray[i] = new double[wd];
    }
    // Test arrays
    cout << "freqArray[0][0] is " << freqArray[0][0] << endl;
    cout << "potArray[0][0] is " << potArray[0][0] << endl;
    cout << "wArray[0][0] is " << wArray[0][0] << endl;


    // Test Array2D class in geometry.h
    Array2D arr2d(10,5);
    cout << "arr2d[0][0] is " << arr2d[0][0] << endl;

    // Test model.h
    cout << model::activity(1.0,1.0,1.0,1.0) << endl;

    cout << "End of Program." << endl;
    return 0;
}