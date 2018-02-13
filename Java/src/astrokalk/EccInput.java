package astrokalk;

import java.io.IOException;

public class EccInput extends IOException {
		
	private String motivo;
	
	public EccInput(String s){
			super("Errore input");
			motivo = s;
		}

	public String why(){
		return motivo;
	}
}
