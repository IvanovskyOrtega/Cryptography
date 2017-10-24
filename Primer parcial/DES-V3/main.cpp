#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;
using namespace des;
using namespace bits;

int main (int argc, char* argv[]) {
	if(argc >= 3){
		cout << "hi" << endl;
	}
	else{
		cout << "./a.out nombreArchivoOriginal nombreArchivoEncriptado" << endl;
	}
	return 0;
}
