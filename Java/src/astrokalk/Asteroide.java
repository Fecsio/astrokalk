package astrokalk;

import static java.lang.Math.pow;
import static java.lang.Math.log10;

public class Asteroide extends OggettoCeleste{

    private double velocita;

    public Asteroide(double r, double ts, double dm, int e,  double v) throws EccInput{
        super(r,ts,dm,e);
        if(v <= 0){
            throw new EccInput("Velocità deve essere > 0");
        }
        velocita = v;
    }

    public Asteroide(Asteroide a){
        super(a);
        velocita = a.velocita;
    }

   public Asteroide(OggettoCeleste o, double v) throws EccInput{
        super(o);
        if(v <= 0){
            throw new EccInput("Velocità deve essere > 0");
        }
        velocita = v;
    }

    public double getVel(){ return velocita; }


    public ConseguenzaCollisione Collisione(){
        double vC = velocita;

        if(vC< 11.2){
            vC = 11.2;
        }

        else if(vC >72.8){
            vC = 72.8;
        }

        double ej = ((0.5)*massa()*pow(10,12)*pow(vC,2));
        long eMT = (long)((2.39e-16)*ej);
        double m = 0.67*log10(ej)-0.87;
        return new ConseguenzaCollisione(eMT,m);
    }


    public Asteroide somma(Asteroide a){
        Asteroide aux = new Asteroide(this);
        aux.fusione(a);
        aux.velocita = (velocita+a.velocita)/2;
        return aux;
    }


    @Override
    public String toString() {
        return super.toString() + " velocità: " + velocita +" km/s ";
    }

}
