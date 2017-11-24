//
// Created by Lei Ma on 10/28/17.
//

#ifndef CPP_RECORDER_H
#define CPP_RECORDER_H

#include <iostream>
#include <fstream>
#include "base.h"
using namespace std;

namespace Recorder
{
   void record_state( Array2D* array_2d, const int length, ofstream& dumpObj, const int savestep = 1) {
      
      for(int i = 0; i < length; i+=savestep) {
         for(int j=0; j < length-1; j+=savestep) {
            dumpObj << (*array_2d)[i][j] << ", ";
         }
            dumpObj << (*array_2d)[i][length-1] << endl;
      }

   }



}

#endif //CPP_RECORDER_H
