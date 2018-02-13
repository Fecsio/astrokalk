package astrokalk;

public class ConseguenzaCollisione {

    private long energia;
    private double magnitudo;


    public ConseguenzaCollisione(long e, double m){
        energia = e;
        magnitudo = m;
    }

    public long getEn(){
        return energia;
    }

    public double getMa(){
        return magnitudo;
    }

}
