package crypto;

import java.math.BigInteger;
import java.util.ArrayList;

public class ECC extends Algorithms {
    
    public BigInteger K;
    public BigInteger P;
    public BigInteger Q;
    
    ECC(){
    };
    
    ArrayList<String> ECC(BigInteger a, BigInteger b){
        ArrayList<String> results = new ArrayList<String>();
        BigInteger p = a.pow(2).add(b.pow(2));
        if(p.isProbablePrime(100)){
            results.add("p = "+p+"\n");
            P = p;
            BigInteger four = new BigInteger("4");
            if((a.add(b)).mod(four).compareTo(BigInteger.ONE) == 0 && p.mod(four).compareTo(BigInteger.ONE) == 0){
                results.add(a+" + "+b+" mod 4 = 1 \n");
                results.add(p+" mod 4 = 1 \n"); 
                BigInteger two = BigInteger.valueOf(2);
                BigInteger q = p.add(BigInteger.ONE.add(a.multiply(two))).divide(four);
                if(q.isProbablePrime(100)){
                    Q = q;
                    results.add("q = "+q+"\n");
                    results.add("Type your posible generator :)\n");
                }
                else{
                    results.add("(q+2a+1)/4 is not a prime number\n");
                }
            }
            else{
                results.add(a+" + "+b+" mod 4 is not 1, and "+p+" mod 4 is not = 1 \n"); 
            }
        }
        else{
            results.add("a²+b² is not a prime number\n");
        }
        return results;
    }

    ArrayList<String> testGenerator(BigInteger x0, BigInteger y0, BigInteger p, BigInteger q){
        ArrayList<String> results = new ArrayList<String>();
        BigInteger mcd = euclideanAlgorithm(p,x0);
        if(mcd.compareTo(BigInteger.valueOf(1)) == 0){
            BigInteger inverseOf_x0 = findMultiplicativeInverse(p);
            BigInteger k = (((x0.pow(3)).subtract(y0.pow(2))).multiply(inverseOf_x0)).mod(p);
            results.add("k = "+k+"\n");
            K = k;
            BigInteger c = (p.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2));
            if(modularExponentiation(k,c,p).compareTo(BigInteger.valueOf(1)) == 0){
                results.add("k is cuadratic remainder modulo "+p+"\n");
                c = (p.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(4));
                if(modularExponentiation(k,c,p).compareTo(BigInteger.valueOf(1)) != 0){
                    results.add("k is not fourth power modulo "+p+"\n");
                    results.add("Your curve's equation is:\n");
                    results.add("\ty³=x³-"+k+"x mod "+p+"\n");
                }
                else{
                    results.add("k is fourth power modulo "+p+"\n");
                }
            }
            else{
                results.add("k is not cuadratic remainder modulo "+p+"\n");
            }
        }
        else{
            results.add("Aqui mamó");
        }
        return results;
    }
}
