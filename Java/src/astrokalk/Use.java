package astrokalk;

import java.time.Duration;
import java.util.Vector;

import static astrokalk.OggettoCeleste.ordinaPer;

public class Use {

    public static void main(String[] args){
            try{
                Asteroide a0 = new Asteroide(5,-20, 0.93, 200, 10);
                Asteroide a1 = new Asteroide(4,10,0.5,2444,67);

                Stella Sole = new Stella(695700, 5505, 1.41, 5000, 7189, 4.83, -26.74);
                Stella Teide1 = new Stella(150000, 1926.75, 70, 120, 2000, 10.84,16.2);

                Pianeta Terra = new Pianeta(6371, 12.5, 5.51, 4540, 1670, 1, 21, 78, 1, Sole);
                Pianeta Marte = new Pianeta(3390, -60, 3.93, 4600, 868, 1.52366231, 0.13, 2.7, 97.17, Sole);

                Satellite Luna = new Satellite(1737, -23, 3.34, 3000, 16.65, 0.00257, Terra);
                Satellite Deimos = new Satellite(6.2, 70, 1.471, 4500, 1.29, 0.000157, Marte);

                double vSole = Sole.volume();
                double supTerra = Terra.superficie();
                double massaLuna = Luna.massa();
                double vFugaMarte = Marte.velFuga();
                double my_PesoMarte = Marte.calcPeso(65);
                ConseguenzaCollisione cc = a1.Collisione();
                double distT_Teide = Teide1.distanzaTerra();
                double distT_Sole = Sole.distanzaTerra();
                double distS_Marte = Marte.distanzaSole();
                Duration annoT = Terra.periodoOrbitale();
                Duration annoM = Marte.periodoOrbitale();
                Duration annoD= Deimos.periodoOrbitale();
                Duration annoL = Luna.periodoOrbitale();
                boolean terraAb = Terra.abitabile();
                boolean marteAb = Marte.abitabile();
                long my_etaETM = Marte.etaExtraTerrestre(18, 3, 1995);
                long my_etaETT = Terra.etaExtraTerrestre(18, 3, 1995);
                boolean lunaSin = Luna.rotazioneSincrona();
                boolean deimosSin = Deimos.rotazioneSincrona();
                double rivAnnueL = Luna.rivoluzioniAnnue();
                double rivAnnueD = Deimos.rivoluzioniAnnue();
                double velOM = Marte.velOrbitale();
                double velOD = Deimos.velOrbitale();
                Duration giornoMart = Marte.Giorno();
                Duration giornoLuna = Luna.Giorno();
                Duration giornoDeimos = Deimos.Giorno();

                Asteroide sommaAst = a0.somma(a1);
                Stella sommaSte = Sole.somma(Teide1);
                Pianeta sommaPia = Terra.somma(Marte);
                Satellite sommaSat = Luna.somma(Deimos);

                double rappMarteTerra = Marte.rapportaVolume(Terra);

                Vector<OggettoCeleste> vec = new Vector<>();
                vec.add(a0);
                vec.add(a1);
                vec.add(Terra);
                vec.add(Marte);
                vec.add(Sole);
                vec.add(Teide1);
                vec.add(Luna);
                vec.add(Deimos);
                vec.add(sommaAst);
                vec.add(sommaSte);
                vec.add(sommaSat);
                vec.add(sommaPia);

                Vector<OggettoCeleste> vecDisScala = ordinaPer(vec,'v');
                Vector<OggettoCeleste> vecOrEta= ordinaPer(vec,'e');

                System.out.println("Volume del Sole: " + String.valueOf(vSole) + " miliardi di m^3 \n");
                System.out.println("Superficie della Terra: " + String.valueOf(supTerra) + " km^2 \n");
                System.out.println("Massa della Luna: " + String.valueOf(massaLuna) + " miliardi di tonnellate \n");

                System.out.println("Velocità di fuga da Marte: " + String.valueOf(vFugaMarte) + " km/s \n");

                System.out.println("Peso su Marte (65 kg sulla terra): " + String.valueOf(my_PesoMarte) + " kg \n");

                System.out.println("Un asteroide di raggio = " + String.valueOf(a1.getRaggio()) + " km che collide con la terra ad una velocità di "+ String.valueOf(a1.getVel()) + " provoca: \n \t" +
                                    cc.getEn() + " milioni di megaton di energia rilasciati e una magnitudo " + cc.getMa() + "\n");

                System.out.println("La stella Teide1 dista dalla Terra circa " + String.valueOf(distT_Teide) + " AU\n");
                System.out.println("La stella Sole dista dalla Terra circa " + String.valueOf(distT_Sole) + " AU\n");

                System.out.println("Marte dista dal suo sole " + String.valueOf(distS_Marte) + " AU\n");

                System.out.println("Sulla Terra un anno dura " + String.valueOf((double)annoT.toDays()/365) + " anni terrestri\n");
                System.out.println("Su Marte un anno dura " + String.valueOf((double)annoM.toDays()/365) + " anni terrestri\n");
                System.out.println("Su Deimos un anno dura " + String.valueOf((double)annoD.toDays()/365 ) + " anni terrestri\n");
                System.out.println("Su Luna un anno dura " + String.valueOf((double)annoL.toDays()/365) + " anni terrestri\n");


                if(terraAb) System.out.println("Terra potrebbe essere abitabile\n");
                else System.out.println("Terra non è abitabile\n");

                if(marteAb) System.out.println("Marte potrebbe essere abitabile\n");
                else System.out.println("Marte non è abitabile\n");

                System.out.println("La mia età su Marte (nato 18/03/1995) sarebbe " + String.valueOf(my_etaETM) + "  anni \n");
                System.out.println("La mia età su Terra (nato 18/03/1995) è " + String.valueOf(my_etaETT) + "  anni \n");

                if(lunaSin) System.out.println("Luna ha rotazione sincrona rispetto al suo pianeta \n");
                else System.out.println("Luna non ha rotazione sincrona rispetto al suo pianeta \n");

                if(deimosSin) System.out.println("Deimos ha rotazione sincrona rispetto al suo pianeta \n");
                else System.out.println("Deimos non ha rotazione sincrona rispetto al suo pianeta \n");

                System.out.println("Luna compie " + String.valueOf(rivAnnueL) + "  rivoluzioni intorno al suo pianeta in un anno del pianeta \n");
                System.out.println("Deimos compie " + String.valueOf(rivAnnueD) + "  rivoluzioni intorno al suo pianeta in un anno del pianeta \n");

                System.out.println("Velocità orbitale Marte: " + String.valueOf(velOM) + " km/s\n");
                System.out.println("Velocità orbitale Deimos: " + String.valueOf(velOD) + " km/s\n");

                System.out.println("Su Marte un giorno dura " + String.valueOf(giornoMart.toDays()) + " giorni, " + String.valueOf(giornoMart.toHours()%24) + " ore e " + String.valueOf((giornoMart.toMinutes()%1440)%60) + " minuti terrestri \n");
                System.out.println("Su Luna un giorno dura " + String.valueOf(giornoLuna.toDays()) + " giorni, " + String.valueOf(giornoLuna.toHours()%24) + " ore e " + String.valueOf((giornoLuna.toMinutes()%1440)%60) + " minuti terrestri \n");
                System.out.println("Su Deimos un giorno dura " + String.valueOf(giornoDeimos.toDays()) + " giorni, " + String.valueOf(giornoDeimos.toHours()%24) + " ore e " + String.valueOf((giornoDeimos.toMinutes()%1440)%60) + " minuti terrestri \n");

                System.out.println("Marte è grande " + String.valueOf(rappMarteTerra) + " volte Terra\n");

                System.out.println(a0.toString() + "\n+ " + a1.toString() + "\n = " + sommaAst.toString() + "\n");
                System.out.println(Sole.toString() + "\n+ " + Teide1.toString() + "\n = " + sommaSte.toString() + "\n");
                System.out.println(Terra.toString() + "\n+ " + Marte.toString() + "\n = " + sommaPia.toString() + "\n");
                System.out.println(Luna.toString() + "\n+ " + Deimos.toString() + "\n = " + sommaSat.toString() + "\n");

                System.out.println("Oggetti creati in questo main senza un ordine: \n");
                for(OggettoCeleste o : vec){
                    System.out.println(o.toString() + "\n" );
                }

                System.out.println("Oggetti creati in scala: \n");
                for(OggettoCeleste o : vecDisScala){
                    System.out.println(o.toString() + "\n" );
                }

                System.out.println("Oggetti creati in ordine d'età: \n");
                for(OggettoCeleste o : vecOrEta){
                    System.out.println(o.toString() + "\n" );
                }




            }

            catch (EccInput e){
                System.out.println(e.why());
            }



    }
}
