
public class Voiture extends Vehicule{

	
	private boolean autoradio;
	
	
	public Voiture(String modele,int dateAchat,int prixAchat,String numImmatriculation,String numPermit,boolean auto){
		super(modele,dateAchat,prixAchat,numImmatriculation,numPermit);
		autoradio=auto;
	}
	
	public void ajouterAutoradio(){
		autoradio=true;
	}
	
	public void enleverAutoradio(){
		autoradio=false;
	}
	
	public String infoVoiture(){
	String s="";
	s=s+"voiture :";
	s=s+this.afficher();
	s=s+(" autoradio : "+autoradio+ "\n");
		return(s);
	}
}
