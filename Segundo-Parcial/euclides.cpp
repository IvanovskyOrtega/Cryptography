#include "euclides.hpp"

using namespace euclides;
using namespace std;

namespace euclides{
    vector<int> Qn;
}

int euclides::algoritmoDeEuclides(int r0, int r1){
    int q;
    int rn = 1;
    while(rn != 0){
        q = r0/ r1;
        rn = r0 % r1;
        if(rn != 0){
            cout << r0 << " = (" << q << ")*" << r1 << " + " << rn << endl;
            Qn.reserve(1);
            Qn.push_back(q);
        }
        else{
            cout << r0 << " = (" << q << ")*" << r1 << endl;
        } 
        r0 = r1;
        r1 = rn;
    }
    return r0;
}

int euclides::encontrarInverso(int r0){
    int j = Qn.size();
    int t0 = 0;
    int t1 = 1;
    int tn;
    for(int i = 0 ; i < j ; i++){
        tn = (t0 - Qn[i]*t1);
        if(tn < 0){
            if(abs(tn) > r0){
                tn = abs(tn) % r0;
                tn = r0 - abs(tn);
            }
            else{
                tn = r0 - abs(tn);
            }
        }
        else if(tn > 0){
            tn = tn % r0;
        }
        else{
            cout << "0" << endl;
        }
        t0 = t1;
        t1 = tn;
        cout << "t" << i+2 << ": " << tn << endl;
    }
    return tn;
}

