package astrokalk;

public class Atmosfera {

    private double ossigeno;
    private double azoto;
    private double altro;

    public Atmosfera(double o, double a, double ar){
        if(a+o+ar != 100 || o < 0 || a <0 || ar < 0){
            ossigeno = 21;
            azoto = 78;
            altro = 1;
        }

        else {
            ossigeno = o;
            azoto = a;
            altro = ar;
        }
    }

    public double getAl(){
        return altro;
    }

    public double getAz(){
        return azoto;
    }

    public double getO(){
        return ossigeno;
    }

    public Atmosfera somma(Atmosfera a){
        return new Atmosfera((ossigeno+a.ossigeno)/2, (azoto+a.azoto)/2, (altro+a.altro)/2);
    }

    @Override
    public String toString() {
        return " ossigeno: " + ossigeno+ ", azoto: " + azoto + ", altro " + altro + " ";
    }

}
