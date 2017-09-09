#include "des.hpp"
#include "archivos.hpp"

using namespace std;
using namespace archivos;

int main (int argc, char* argv[]) {
	bitset<MAX_SIZE>* bitsLeidos = new (nothrow)bitset<MAX_SIZE>();
	bitsLeidos = leerArchivo(argv[1]);
	escribirArchivo(bitsLeidos,"nuevaImagen.jpg",tamanio);
    return 0;
}