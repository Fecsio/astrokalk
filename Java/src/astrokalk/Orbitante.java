package astrokalk;

import java.time.Duration;

public abstract class Orbitante extends CorpoCeleste {

    private double semiAsseOrbita;

    public abstract double velOrbitale();
    public abstract double distanzaSole();
    public abstract Duration periodoOrbitale();

    public Orbitante(double r, double ts, double dm, int e, double vRot, double semiA) throws EccInput{
        super(r,ts,dm,e,vRot);
        semiAsseOrbita = semiA;
        if(semiA <= 0){
            throw new EccInput("Semiasse deve essere > 0");
        }
    }

    public Orbitante(Orbitante obj){
        super(obj);
        semiAsseOrbita = obj.semiAsseOrbita;
    }


    public void fusione(OggettoCeleste obj){
        Orbitante aux = (Orbitante)obj;
        super.fusione(obj);
        semiAsseOrbita = (semiAsseOrbita + aux.semiAsseOrbita)/2;
    }

    public double getAsse(){
        return semiAsseOrbita;
    }

    @Override
    public String toString() {
        return super.toString() + " semiasse magg. orb: " + semiAsseOrbita + " AU ";
    }

}
