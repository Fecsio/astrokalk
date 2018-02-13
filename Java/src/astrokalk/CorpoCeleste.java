package astrokalk;

import java.time.Duration;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public abstract class CorpoCeleste extends OggettoCeleste{

    private double velRotazione;

    protected static double G=6.67191e-11;

    public CorpoCeleste(double r, double ts, double dm, int e, double vRot) throws EccInput{
        super(r,ts,dm,e);
        if(vRot <= 0){
            throw new EccInput("Velocità di rotazione deve essere > 0");
        }
        velRotazione = vRot;
    }

    public CorpoCeleste(CorpoCeleste obj){
        super(obj);
        velRotazione = obj.velRotazione;
    }


    public double getVRot(){return velRotazione;}


    public  double AccelerazioneGravita(){return G*massa()/pow(getRaggio(), 2);}


    public double calcPeso(double peso){
        double aux = peso/9.80665;
        return aux*AccelerazioneGravita()*pow(10,6);
    }

    public double velFuga(){
        return sqrt((2*G*massa()*pow(10,9))/getRaggio())*pow(10,-3);
    }

    public Duration Giorno(){
        return Duration.ofSeconds((long)(((getRaggio()*2*pi)/velRotazione)*3600)); //*3600 perchè diametro/velrot mi dà le ore
    }

    public void fusione(OggettoCeleste obj){
        CorpoCeleste aux = (CorpoCeleste)obj;
        super.fusione(obj);
        velRotazione = (velRotazione+aux.velRotazione)/2;
    }

    @Override
    public String toString() {
        return super.toString() + " vel. rotazione: " + velRotazione + " km/h ";
    }
}
