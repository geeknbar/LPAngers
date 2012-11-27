
public class Camion extends Vehicule{
	
	protected double volume;
	
	
	public Camion (String modele,int dateAchat,int prixAchat,String numImmatriculation,String numPermit, double vol){
		super(modele,dateAchat,prixAchat,numImmatriculation,numPermit);
		volume=vol;
	}
	
	public boolean peutTransporterVolume(double volumeDemander){
		
		return (volume>=volumeDemander);
		
	}
	public String infoCamion(){
	String s="";
	s=s+"camion :";
	s=s+this.afficher();
	s=s+(" volume : "+volume+ "\n");
		return(s);
	}

}


