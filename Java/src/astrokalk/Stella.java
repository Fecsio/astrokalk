package astrokalk;

import static java.lang.Math.pow;

public class Stella extends CorpoCeleste{

    private double magnitudineAss; //cioè magnitudine a 10 parsec di distanza, da -20 a 10
    private double magnitudineApp; // cioè magnitudine dalla terra, da -26.74(sole) a 10

    public Stella(double r, double ts, double dm, int e, double vRot, double mAss, double mApp) throws  EccInput{
        super(r, ts, dm, e, vRot);
        if(mAss < -30 || mAss >30 || mApp < -38|| mApp > 35){
            throw new EccInput("Valori per le magnitudi invalidi; rispettivamente: -30 <= assoluta <= 30, -38 <= apparente <= 35");
        }
        magnitudineAss = mAss;
        magnitudineApp = mApp;
    }

    public Stella(CorpoCeleste c, double mAss, double mApp) throws EccInput{
        super(c);
        if(mAss < -30 || mAss >10 || mApp < -38 || mApp > 35)
            throw new EccInput("Valori per le magnitudi invalidi; rispettivamente: -30 <= assoluta <= 30, -38 <= apparente <= 35");

        magnitudineApp = mApp;
        magnitudineAss = mAss;
    }

    public Stella(Stella s){
        super(s);
        magnitudineAss = s.magnitudineAss;
        magnitudineApp = s.magnitudineApp;
    }

    public double getMAss(){
        return magnitudineAss;
    }

    public double getMApp(){
        return magnitudineApp;
    }

    public double distanzaTerra(){
        return pow(10, (magnitudineApp-magnitudineAss+5)/5)*206265; //*206265 -> parsec * 206265 = UA
    }

    public Stella somma(Stella s){
        Stella aux = new Stella(this);
        aux.fusione(s);
        aux.magnitudineAss = (magnitudineAss+s.magnitudineAss)/2;
        aux.magnitudineApp = (magnitudineApp+s.magnitudineApp)/2;
        return aux;
    }

    @Override
    public String toString() {
        return super.toString() + "Magn. Assoluta: " + magnitudineAss + " Magn. Apparente " + magnitudineApp + " ";
    }

}
