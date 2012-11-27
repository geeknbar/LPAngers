public class Agence {

	
	private String nom;
	private String telephone;
	private int administratif;
	protected String commentaire;
	
	
	public Agence(String n,String tel,int ad,String com){

		nom=n;
		telephone=tel;
		administratif=ad;
		commentaire=com;
	}
	
	public int taillePersonnel(){
		return administratif;
	}
	
	
	public String afficher(){
		return(" - "+this.nom+", - "+telephone+", - "+administratif+" adm - ");
	}
}