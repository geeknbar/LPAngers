public class Garage extends Agence {

	private int mecanicien;
	
	public Garage(String nom,String telephone,int administratif,String commentaire, int meca){
		super(nom,telephone,administratif,commentaire);
		mecanicien=meca;
	}
	
	public int taillePersonnel(){
		return (super.taillePersonnel()+mecanicien);
	}
	
	
	public String afficherGarage(){
		return("Garage :"+this.afficher()+mecanicien+" meca"+ "\n");
	}
}