//
// Created by Lei Ma on 10/28/17.
//

#ifndef CPP_SOLVER_H
#define CPP_SOLVER_H

#include <vector>
#include "model.h"

namespace Solver{


   void euler( Array2D* actA2, Array2D* potA2, Array2D* weiEA2, Array2D* weiIA2, Array2D* TactA2, Array2D* TpotA2, Array2D* TweiEA2, Array2D* TweiIA2, int geodim[2], double dt, vector<double> params, vector<double> wparams, vector<double> extparams ){
      // params = {alpha, beta, epsilon, tau, resistance}
      // extparams = {w, frequency, background}

      
      int wlen = geodim[0]*geodim[1];

      for(int i=0 ; i< geodim[0]; i++ ){
         for(int j=0; j<geodim[1]; j++) {

            // int idxp0 = ( geodim[0] + ( i + 1 )%geodim[0] )%geodim[0];
            // int idxp1 = ( geodim[1] + ( j + 1 )%geodim[1] )%geodim[1];
            // int idxm0 = ( geodim[0] + ( i - 1 )%geodim[0] )%geodim[0];
            // int idxm1 = ( geodim[1] + ( j - 1 )%geodim[1] )%geodim[1];
         
            // vector<double> excfreq = { (*weiEA2)[idxp0][idxp1], (*weiEA2)[idxp0][idxp1] };
            
            vector<double> excfreq = Model::nnActivity( actA2, geodim, i, j );
            vector<double> excw = Model::nnWeight( weiEA2, geodim, i, j );
            vector<double> inhfreq = Model::nnnActivity( actA2, geodim, i, j );
            vector<double> inhw = Model::nnnWeight( weiEA2, geodim, i, j );

            double neib = Model::neighbours(excfreq, excw, inhfreq, inhw);
            
            double act = Model::activity( (*potA2)[i][j] , params[0], params[1], params[2] );

            double ext = Model::external( extparams[0], extparams[1], extparams[2] );

            double rhs = dt * Model::dudt( (*potA2)[i][j], act, neib, ext, params[3], params[4]); // dudt * dt

            (*TpotA2).set(i,j, rhs);
            
            for(int a : {1, -1}) {
               for(int b : {1, -1}) {

                  int ai = ( geodim[0] + ( a + 1 )%geodim[0] )%geodim[0];
                  int bj = ( geodim[1] + ( b + 1 )%geodim[1] )%geodim[1];
                  int widx1 = a * geodim[1] + b;
                  int widx2 = ai * geodim[1] + bj;
                  
                  double acta = (*actA2)[a][b];
                  double actb = (*actA2)[ai][bj];

                  double weiENew = (*weiEA2)[widx1][widx2] + dt * Model::dwEdt( acta, actb, wparams[0], wparams[1], wparams[2] );
                  // double dwEdt( double acti, double actj, double mu, double kappa, double actt, double dt) {
                     (*TweiEA2).set(widx1, widx2, weiENew);
              }
            }

            (*TweiIA2).set(i,j, (*weiIA2)[i][j] );

            (*TactA2).set(i,j, Model::activity(rhs, params[0], params[1], params[2]) );

            
         }

      }




   }

}

#endif //CPP_SOLVER_H
