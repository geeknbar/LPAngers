
public class Autocar extends Camion {
	
	private int nbVoyageur;
	
	public Autocar(String modele,int dateAchat,int prixAchat,String numImmatriculation,String numPermit,double vol, int nbVoy){
		super(modele,dateAchat,prixAchat,numImmatriculation,numPermit,vol);
		nbVoyageur=nbVoy;
	}
	
	public boolean peutTransporterPassagers(int NbPassager,double VolumeTot){
		boolean res;
		//return (NbPassager>nbVoyageur&&peutTransporterVolume(VolumeTot));
		if(NbPassager>nbVoyageur){
		  res=false;
		}else if(VolumeTot>volume){
		  res=false;
		  }else{
		  res=true;
		  }
		  return res;
	}
	
	public String infoAutocar(){
		return("autocar :"+ this.afficher()+" nombre voyageur : "+nbVoyageur+ "\n");
	}

}
