#include <iostream>
// #include "includes/geometry.h"

using namespace std;

int main() {

    int row = 20;
    int col = 10;
    int wd = row*col;

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



    cout << "End of Program." << endl;
    return 0;
}