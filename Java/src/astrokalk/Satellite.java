package astrokalk;

import java.time.Duration;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Satellite extends Orbitante {

    private Pianeta pianeta;


    public Satellite(double r, double ts, double dm, int e, double vRot, double semiA, Pianeta p) throws EccInput {
        super(r, ts, dm, e, vRot, semiA);
        pianeta = p;
    }

    public Satellite(Orbitante o, Pianeta p) {
        super(o);
        pianeta = p;
    }

    public Satellite(Satellite s) {
        super(s);
        pianeta = s.pianeta;
    }

    public Pianeta getPianeta() {
        return pianeta;
    }

    public double rivoluzioniAnnue() {
        return ((double) pianeta.periodoOrbitale().toHours()) / (double) periodoOrbitale().toHours();
    }

    public Duration periodoOrbitale() {
        double num = 4 * pow(pi, 2) * pow(getAsse() / 6.684587123e-12, 3);
        double den = G * (massa() * pow(10, 12) + pianeta.massa() * pow(10, 12));
        double result = sqrt(num / den) * (3.168753579e-08) * 365;
        return Duration.ofSeconds((long) (result * 86400));
    }


    public boolean rotazioneSincrona() { //dato che l'approssimazione puo non essere perfetta, confronto solo le ore
        return Giorno().toHours() <= (periodoOrbitale().toHours() + 0.1 * periodoOrbitale().toHours()) &&
                Giorno().toHours() >= (periodoOrbitale().toHours() - 0.1 * periodoOrbitale().toHours());
    }

    public double velOrbitale() {
        return sqrt((G * pianeta.massa()) / (pianeta.getRaggio() * pow(10, 3) + getAsse() * 1.5e+11)) * pow(10, 3);
    }

    public double distanzaSole() {
        return pianeta.distanzaSole() + getAsse();
    }


    public Satellite somma(Satellite o) {
        Satellite aux = new Satellite(this);
        aux.fusione(o);
        aux.pianeta = o.pianeta;
        return aux;
    }

}
