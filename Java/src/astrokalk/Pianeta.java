package astrokalk;

import java.time.Duration;
import java.time.LocalDate;

import static java.lang.Math.abs;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.time.temporal.ChronoUnit.DAYS;

public class Pianeta extends Orbitante {

    private Atmosfera atmosfera;
    private Stella sole;

    public Pianeta(double r, double ts, double dm, int e, double vRot, double semiA, double ossigeno, double azoto, double altro, Stella s) throws EccInput {
        super(r, ts, dm, e, vRot, semiA);
        atmosfera = new Atmosfera(ossigeno, azoto, altro);
        sole = s;
    }

    public Pianeta(Orbitante c, Atmosfera a, Stella s) throws EccInput {
        super(c);
        atmosfera = new Atmosfera(a.getO(), a.getAz(), a.getAl());
        sole = s;
    }

    public Pianeta(Pianeta p){
        super(p);
        atmosfera = p.atmosfera;
        sole = p.sole;
    }

    public Atmosfera getAtm() {
        return atmosfera;
    }

    public Stella getStella() {
        return sole;
    }

    public double ESI() {
        double r = pow(1 - abs((getRaggio() - 6371) / (getRaggio() + 6371)), 0.57 / 3); //6371 = raggio terrestre
        double d = pow(1 - abs((getDens() - 5.51) / (getDens() + 5.51)), 1.07 / 3); //5.51 = densita terra
        double vf = pow(1 - abs((velFuga() - 11.2) / (velFuga() + 11.2)), 0.7 / 3); // 11.2 = velocita fuga terra in km/s
        return r * d * vf;
    }

    public boolean abitabile() {
        return ((ESI() >= 0.8)
                && (getTemp() >= -80) && (getTemp() <= 100)
                && (atmosfera.getAz() >= 70) && (atmosfera.getAz() <= 85)   //valori riferiti alla composizione atmosferica terrestre, calcolo inventato
                && (atmosfera.getAl() >= 0.5) && (atmosfera.getAl() <= 1.5)
                && (atmosfera.getO() >= 18) && (atmosfera.getO() <= 30));
    }

    public Duration periodoOrbitale() {
        double num = 4 * pow(pi, 2) * pow(getAsse() / 6.684587123e-12, 3);
        double den = G * (massa() * pow(10, 12) + sole.massa() * pow(10, 12));
        double result = sqrt(num / den) * (3.168753579e-08) * 365;
        return Duration.ofSeconds((long) (result * 86400));
    }

    public long etaExtraTerrestre(int g, int m, int a) {
        LocalDate oggi = LocalDate.now();
        LocalDate compleanno = LocalDate.of(a, m, g);
        long etaG = DAYS.between(compleanno, oggi);
        return (long) ((double)etaG / 365 / ((double)periodoOrbitale().toDays() / 365));
    }

    public double velOrbitale(){
        return sqrt((G*sole.massa())/(sole.getRaggio()*pow(10,3)+getAsse()*1.5e+11))*pow(10,3);
    }

    public double distanzaSole(){
        return getAsse();
    }

    public Pianeta somma(Pianeta p){
        Pianeta aux = new Pianeta(this);
        aux.fusione(p);
        aux.atmosfera = atmosfera.somma(p.atmosfera);
        return aux;
    }


    @Override
    public String toString() {
        return super.toString() + ", atmosfera composta da: " + atmosfera + " ";
    }


}
