#include "euclides.hpp"

using namespace std;
using namespace euclides;

int main(int argc, char **argv){
    int r0, r1;
    int a, inverso;
    cout << "Ingresa r0: ";
    cin >> r0;
    cout << "Ingresa r1: ";
    cin >> r1;
    a = algoritmoDeEuclides(r0,r1);
    if(a == 1){
        inverso = encontrarInverso(r0);
        cout << "Inverso: " << inverso << endl;
    }
    else{
        cout << "No tiene inverso" << endl;
    }
    return 0;
}