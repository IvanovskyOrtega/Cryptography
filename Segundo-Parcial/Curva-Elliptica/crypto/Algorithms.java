package crypto;

import java.math.BigInteger;
import java.util.ArrayList;

public class Algorithms {
    ArrayList<BigInteger> Qn = new ArrayList<BigInteger>();

    BigInteger euclideanAlgorithm(BigInteger r0, BigInteger r1){
        BigInteger q;
        BigInteger rn = BigInteger.ONE;
        while(rn.compareTo(BigInteger.ZERO) != 0 ){
            q = r0.divide(r1);
            rn = r0.mod(r1);
            if(rn.compareTo(BigInteger.ZERO) != 0){
                //System.out.println(r0+" = ("+q+")"+r1+" + "+rn);
                Qn.add(q);
            }
            else{
                //System.out.println(r0+" = ("+q+")"+r1);
            }
            r0 = r1;
            r1 = rn;
        }
        return r0;
    }

    BigInteger findMultiplicativeInverse(BigInteger r0){
        int j = Qn.size();
        BigInteger t0 = BigInteger.ZERO;
        BigInteger t1 = BigInteger.ONE;
        BigInteger tn = BigInteger.ZERO;
        if (j == 0) {
            return r0.add(BigInteger.ONE);
        }
        for(int i = 0 ; i < j ; i++){
            tn = (t0.subtract(Qn.get(i).multiply(t1)));
            if(tn.compareTo(BigInteger.ZERO) == -1){
                if(tn.abs().compareTo(r0) == 1){
                    tn = (tn.abs()).mod(r0);
                    tn = r0.subtract(tn);
                }
                else{
                    tn = r0.subtract(tn.abs());
                }
            }
            else if(tn.compareTo(BigInteger.ZERO) == 1){
                tn = tn.mod(r0);
            }
            else{
                //System.out.println("0\n");
            }
            t0 = t1;
            t1 = tn;
            //System.out.println("t"+(i+2)+": "+tn+"\n");
        }
        Qn.clear();
        return tn;
    }

    BigInteger modularExponentiation(BigInteger b, BigInteger c, BigInteger n){
        BigInteger z = BigInteger.ONE;
        int l = c.bitLength();
        byte[] c_binary = c.toByteArray();
        for (int i = l - 1 ; i >= 0 ; i--) {
            z = z.multiply(z).mod(n);
            if (c.testBit(i)) {
                z = b.multiply(z).mod(n);
            }
        }
        return z;
    }

    public int getBit(byte current_byte, int position)
    {
        return (current_byte >> position) & 1;
    }

}

