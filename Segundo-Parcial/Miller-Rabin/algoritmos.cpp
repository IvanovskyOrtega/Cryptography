#include "algoritmos.hpp"

using namespace algoritmos;
using namespace std;

namespace algoritmos{
    vector<ll> Qn;
	vector<ll*> sumas;  
}

ll* algoritmos::doblar(ll x0, ll y0, ll x1, ll y1, ll k, ll p){
	ll *res = (ll*)malloc(2*sizeof(ll));
	if(x0 == x1 && y0 == y1){
		ll inv = 2*y1;
		if(inv < 0){
			inv = p - (ll)abs(inv)%p;
		}
		inv %= p;
		if(algoritmoDeEuclides(p,inv) == 1){
			if(y1 == (p-y0%p)){
				res[0] = INFINITO;
				res[1] = INFINITO;
				cout << "res = (" << res[0] << "," << res[1] << ")" << endl;
				return res;
			}
			ll y1_inv = encontrarInverso(p);
			ll lambda = ((3*x1*x1 + k)*y1_inv);
			if(lambda < 0){
				lambda = p - ((ll)abs(lambda)%p);
			}
			lambda = lambda % p;
			res[0] = (lambda*lambda - 2*x1);
			if(res[0] < 0){
				res[0] = p - ((ll)abs(res[0])%p);
			}
			res[0] = res[0] % p;
			res[1] = (lambda*(x1 - res[0]) - y1);
			if(res[1] < 0){
				res[1] = p - ((ll)abs(res[1])%p);
			}
			res[1] = res[1] % p;
			cout << "res = (" << res[0] << "," << res[1] << ")" << endl;
		}
		else{
			Qn.clear();
		}
	}
	else{
		ll inv = x1-x0;
		if(inv < 0){
			inv = p - (ll)abs(inv)%p;
		}
		inv %= p;
		if(inv == 0){
			res[0] = INFINITO;
			res[1] = INFINITO;
			cout << "res = (" << res[0] << "," << res[1] << ")" << endl;
			return res;
		}
		if(algoritmoDeEuclides(p,inv) == 1){
			ll inverso = encontrarInverso(p);
			ll lambda = ((y1-y0)*inverso);
			if(lambda < 0){
				lambda = p - ((ll)abs(lambda)%p);
			}
			lambda = lambda % p;
			res[0] = (lambda*lambda - x1 - x0);
			if(res[0] < 0){
				res[0] = p - ((ll)abs(res[0])%p);
			}
			res[0] = res[0] % p;
			res[1] = (lambda*(x1 - res[0]) - y1);
			if(res[1] < 0){
				res[1] = p - ((ll)abs(res[1])%p);
			}
			res[1] = res[1] % p;
			cout << "res = (" << res[0] << "," << res[1] << ")" << endl;
		}
		else{
			Qn.clear();
		}
	}
	return res;
}

ll* algoritmos::sumar(ll numSumas, ll x0, ll y0, ll x1, ll y1, ll k, ll p){
	ll* res = (ll*)malloc(2*sizeof(ll));
	ll sumaPar = 0;
    ll i = 1;
    while (i < numSumas){
        sumaPar++;
        i*=2;
    }
	sumaPar -= 2;
	cout << sumaPar << endl;
	vector<bool> numSumasBinario;
	llToBinary(numSumas,&numSumasBinario);
	imprimirBinario(numSumas,numSumasBinario);
	res = doblar(x0,y0,x1,y1,k,p);
	sumas.reserve(1);
	sumas.push_back(res);
	for(i = 0; i < sumaPar; i++){
		res = doblar(res[0],res[1],res[0],res[1],k,p);
		sumas.reserve(1);
		sumas.push_back(res);
	}
	for(i = (ll)numSumasBinario.size()-2; i >= 1 ; i--){
		if(numSumasBinario[i] == true){
			res = doblar(res[0], res[1],sumas[i-1][0],sumas[i-1][1],k,p);
		}
	}
	sumas.clear();
	return res;
}

void algoritmos::verificarK(ll k, ll p, ll x0, ll y0, ll q){
	ll c;
	c = (p - 1) / 2;
	if(potenciar(k,c,p) == 1){
		cout << k << " es residuo cuadratico modulo " << p << endl;
		c = (p - 1) / 4;
		if(potenciar(k,c,p) != 1){
			cout << k << " no es potencia cuarta modulo " << p << endl;
			ll *generador = sumar(q-1,x0, y0, x0, y0, -k, p);
			cout << "(q-1)*alfa = " << generador[0] << "," << generador[1] << endl;
			if(generador[1] == (p-y0%p)){
				cout << "alfa es generador" << endl;
			}
		}
		else{
			cout << k << " es potencia cuarta modulo " << p << endl;
			cout << "No se puede seguir" << endl;
			return;
		}
	}
	else{
		cout << k << " no es residuo cuadratico modulo " << p << endl;
		cout << "No se puede seguir" << endl;
		return;
	}
	return;
}

void algoritmos::curvaEliptica(ll a, ll b){
	ll p = pow(a,2) + pow(b,2);
	if(esPrimo(p,20)){
		cout << "p = " << p << endl;
		if(((a+b)%4 == 1) && (p%4 == 1)){
			ll q = (p+1+2*a)/4;
			if((esPrimo(q,20))){
				cout << "q = " << q << endl;
				ll x0,y0,x0_inv;
				cout << "Ingresa x0, y0:\t";
				cin >> x0 >> y0;
				if(algoritmoDeEuclides(p,x0) == 1){
					x0_inv = encontrarInverso(p); 
					ll k = ((ll)(pow(x0,3) - pow(y0,2))*x0_inv)%p;
					cout << "k = " << k << endl;
					verificarK(k,p,x0,y0,q);
				}
			}
			else{
				cout << "q no es primo" << endl;
			}
		}
		else{
			cout << "No se cumplio a+b mod 4 = 1 y p mod 4 = 1" << endl;
		}
	}
	else{
		cout << "a*a + b*b no s primo" << endl;
	}
}

void algoritmos::menu(char opcion){
	ll posiblePrimo, iteraciones;
	ll r0, r1, res, potencia, a, b, c, n;
	ll x0, y0, x1, y1, k, p;
	switch(opcion){
		case '1':
			cout << "Ingresa r0: ";
			cin >> r0;( x_0, y_0 )
			cout << "Ingresa r1: ";
			cin >> r1;
			res = algoritmoDeEuclides(r0,r1);( x_0, y_0 )
			if(res == 1){
				char op;
				cout << "encontrar inverso? (s/n)" << endl;
				cin >> op;
				if(op == 's' || op == 'S'){
					ll inverso = encontrarInverso(r0);
					cout << "El inverso es: " << inverso << endl;
				}
				else{
					Qn.clear();
				}
			}
			else{
				Qn.clear();
				cout << "No tiene inverso" << endl;
			}
			break;
		case '2':
			cout << "Ingresa b: ";
			cin >> b;
			cout << "Ingresa c: ";
			cin >> c;
			cout << "Ingresa n: ";
			cin >> n;
			potencia = potenciar(b,c,n);
			cout << "Resultado: " << potencia << endl;
			break;
		case '3':
			cout << "Ingresa un numero n: ";
			cin >> posiblePrimo;
			cout << "Ingresa el numero de iteraciones del algoritmo: ";
			cin >> iteraciones;
			if(esPrimo(posiblePrimo,iteraciones)){
				cout << posiblePrimo << " es primo" << endl;
			}
			else{
				cout << posiblePrimo << " no es primo" << endl;
			}
			break;
		case '4':
			cout << "Ingresa a y b:\t";
			cin >> a >> b;
			curvaEliptica(a,b);
			Qn.clear();
			break;
		case '5':
			cout << "Ingresa x0,y0,x1,y1,k,p:\t";
			cin >> x0 >> y0 >> x1 >> y1 >> k >> p;
			doblar(x0,y0,x1,y1,k,p);
			break;
		default:
			cout << "Opcion invalida" << endl;
	}
}

bool algoritmos::esPrimo(ll n, ll iteraciones) {
	if (n <= 1 || n == 4) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	ll k = 0;
	ll m = n - 1;
	while (m % 2 == 0) {
		k++;
		m /= 2;
	}
	for (ll i = 0; i < iteraciones; i++) {
		if (millerRabin(n,m,k) == false) {
			return false;
		}
	}
	return true;
}

bool algoritmos::millerRabin(ll n, ll m, ll k){
    ll b;
    ll a;
	a = 2 + rand() % (n - 4);
	b = potenciar(a,m,n);
	if (b == 1 || b == (n-1)) {
		return true;
	}
	for (ll i = 0; i < k; i++) {
		b = potenciar(b, 2, n);
		if (b == (n - 1)) {
			return true;
		}
		else if(b == 1){
			return false;
		}
	}
    return false;
}

ll algoritmos::potenciar(ll b, ll c, ll n){
	ll l;
	ull z = 1;
    vector<bool> c_binario;
    llToBinary(c, &c_binario);
    //imprimirBinario(c,c_binario);
	l = c_binario.size();
	for (ll i = l - 1 ; i >= 0 ; i--) {
		z = (z*z) % n;
		if (c_binario[i]) {
			z = (b*z) % n;
		}
	}
	return (ll)z;
}

void algoritmos::llToBinary(ll entero, vector<bool> *entero_binario){
    ll tamanio = 0;
    ll i = 1;
    while (i<entero){
        tamanio++;
        i*=2;
    }
    entero_binario->reserve(tamanio);
    tamanio--;
    while(entero>0){
        if(entero & 1)
            entero_binario->push_back(true);
        else
            entero_binario->push_back(false);
        entero>>=1;
        tamanio--;
    }
 }

 void algoritmos::imprimirBinario(ll entero, vector<bool> binario){
	cout << "El binario de " << entero << " es: ";
    for(ll i = (ll)binario.size()-1 ; i >= 0 ; i--){
        cout << binario[i];
    }
    cout << endl;
 }

ll algoritmos::algoritmoDeEuclides(ll r0, ll r1){
    ll q;
    ll rn = 1;
    while(rn != 0){
        q = r0/r1;
        rn = r0 % r1;
        if(rn != 0){
            //cout << r0 << " = (" << q << ")*" << r1 << " + " << rn << endl;
            Qn.reserve(1);
            Qn.push_back(q);
        }
        else{
            //cout << r0 << " = (" << q << ")*" << r1 << endl;
        } 
        r0 = r1;
        r1 = rn;
    }
    return r0;
}

ll algoritmos::encontrarInverso(ll r0){
    ll j = Qn.size();
    ll t0 = 0;
    ll t1 = 1;
    ll tn;
	if (j == 0) {
		return r0 + 1;
	}
    for(ll i = 0 ; i < j ; i++){
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
            //cout << "0" << endl;
        }
        t0 = t1;
        t1 = tn;
        //cout << "t" << i+2 << ": " << tn << endl;
    }
	Qn.clear();
    return tn;
}
