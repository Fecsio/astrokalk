package astrokalk;

import java.util.Comparator;
import java.util.Vector;

import static java.lang.Math.pow;

public abstract class OggettoCeleste {

	private double raggio;
	private double temperaturaSuperficiale;
	private double densitaMedia;
	private int eta;

	protected  static double pi =  3.141592653589793;

	public OggettoCeleste(double r, double ts, double d, int e) throws EccInput {
		if (r <= 0 || d <= 0 || e < 0) {
			throw new EccInput("Raggio e densità devono essere > 0, età >=0");
		}
		raggio = r;
		temperaturaSuperficiale = ts;
		densitaMedia = d;
		eta = e;
	}

	public OggettoCeleste(OggettoCeleste obj){
		raggio = obj.raggio;
		temperaturaSuperficiale = obj.temperaturaSuperficiale;
		densitaMedia = obj.densitaMedia;
		eta = obj.eta;
	}

	public double getRaggio() {
		return raggio;
	}

	public double getTemp() {
		return temperaturaSuperficiale;
	}

	public double getDens() {
		return densitaMedia;
	}

	public int getEta() {
		return eta;
	}

	public static Vector<OggettoCeleste> ordinaPer(Vector<OggettoCeleste> v, char condizione) {

		Vector<OggettoCeleste> aux = new Vector<>(v);

		aux.sort(Comparator.comparing(primo -> {
			if(condizione == 'v')  return Double.valueOf(primo.raggio);
			else return Double.valueOf(primo.eta);
		}));
		return aux;

	}

	public double volume(){
		return (pi/6)*pow(raggio*2, 3);
	}

	public double rapportaVolume(OggettoCeleste ogg){
		return volume()/ogg.volume();
	}

	public double massa(){
		return densitaMedia*volume();
	}

	public double superficie(){
		return 4*pi*pow(raggio,2);
	}

	public void fusione(OggettoCeleste ogg){
		raggio+=ogg.raggio;
		densitaMedia=(densitaMedia+ogg.densitaMedia)/2;
		temperaturaSuperficiale=(temperaturaSuperficiale+ogg.temperaturaSuperficiale)/2;
		eta=0;
	}

	public boolean maggioreDi(OggettoCeleste obj) {
		return raggio > obj.raggio;
	}

	public boolean minoreDi(OggettoCeleste obj) {
		return raggio < obj.raggio;
	}

	@Override
	public String toString() {
		return "Raggio: " + raggio + " km, temp. super.: " + temperaturaSuperficiale + " C°, densità media: " + densitaMedia + " g/cm^3 età: " + eta + " milioni di anni ";
	}
}
