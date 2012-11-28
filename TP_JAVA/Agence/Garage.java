/**
* La classe Garage permet de représenter des Garages
* @author dorian
* @version beta
*/


public class Garage extends Agence {

	/**
	* mecanicien nombre de mecanicien dans le garage
	*
	*/
	private int mecanicien;
	
	
	/**
	* constructeur de la classe
	* @param nom le nom de l'agence
	* @param telephone le telephone
	* @param administratif le nombre d'administratif
	* @param commentaire le commentaire
	* @param meca le nombre de mecanicien
	*/
	public Garage(String nom,String telephone,int administratif,String commentaire, int meca){
		super(nom,telephone,administratif,commentaire);
		mecanicien=meca;
	}
	/**
	* méthode qui renvoie le nombre d'administratif
	* @return la taille du personnel
	*/
	public int taillePersonnel(){
		return (super.taillePersonnel()+mecanicien);
	}
	
	/**
	* méthode qui renvoie une chaine de caractère d'information
	* @return l'information du garage
	*/
	public String afficherGarage(){
		return("Garage :"+this.afficher()+mecanicien+" meca"+ "\n");
	}
}