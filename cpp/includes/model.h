//
// Created by Lei Ma on 10/28/17.
//

#ifndef CPP_MODEL_H
#define CPP_MODEL_H

#include <cmath>
namespace model {

   double activity(double u, const double alpha, const double beta, const double epsilon) {
      return alpha / ( 1.0 + exp( beta * ( epsilon - u ) ) );
   }

   double dudt(double u, double frequency, double nbrs, double ext, const double tau, const double resistance){
      // nbrs = sum_excit - sum_inhit =  { f1+, f2+, f3+, f4+, ... } * { wi1+, wi2+, wi3+, wi4+, ... } - { f1-, f2-, f3- f4-, ... } * { wi1-, wi2-, wi3-, wi4-, ... } 
      

      return -u/tau + resistance * ( nbrs +  ext ) ;
   }

   double neighbours( double* excfreq, double* excw, int exclen, double* inhfreq, double* inhw, int inhlen ){
      // excfreq = { f1+, f2+, f3+, f4+, ... } 
      // excw = { wi1+, wi2+, wi3+, wi4+, ... }
      // inhfreq = { f1-, f2-, f3- f4-, ... } 
      // inhw = { wi1-, wi2-, wi3-, wi4-, ... } 
      
      double excsum;
      double inhsum;

      for(int i=0; i < exclen; i++ ){
         excsum = excfreq[i] * excw[i];
      }
      for(int i=0; i < inhlen; i++ ){
         excsum = inhfreq[i] * inhw[i];
      }

      return excsum + inhsum;

   }

   double external(double w, double freq, double bg) {
      return w * (freq + bg);
   }


}


#endif //CPP_MODEL_H
