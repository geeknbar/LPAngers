import java.util.*;

public class Ensemble {

  private List<Object> liste = new ArrayList<Object>();
  
  
  public Ensemble(){
  
  }
  public Ensemble(List<Object> l){
    liste=l;
  
  }
  
  public boolean estVide() {//retourne true si l'ensemble est vide, false sinon ;

   	return liste.isEmpty();
  }
  
  public int taille(){ //retourne le nombre d'éléments dans l'ensemble ;

      return liste.size();
  }
  
  public boolean contient(Object o){ //retourne true si l'élément passé en paramètre appartient à l'ensemble ou false sinon ;
      return liste.contains(o);
  }
  
  public Object obtenir(int i){ // renvoie l'élément situé à l'emplacement envoyé en paramètre ;
      return liste.get(i);
  }
  
  
  public void ajouter(Object o){ //ajoute un élément à l'ensemble ;
    if(this.contient(o))
      return;
    liste.add(o);
  }
  
  public Ensemble copie(){ // retourne un ensemble contenant les mêmes éléments ;
      Ensemble e = new Ensemble(liste);
      for(int i=0; i<taille();i++){
	e.ajouter(this.liste.get(i));
	}
      return e;
      /*
      Ensemble e = new Ensemble(liste);
      return e;
      */
  }
  
  public Object retournerEnlever(Object o){//retourne un élément de l’ensemble et qui l’enlève de l’ensemble (si l’ensemble n'est pas vide) ;
      /*if (i>=taille())
       return;
      Object o =this.list.get(i);
      this.list.remove(i);
      return o;
      */
      Object o1 = o;
      liste.remove(o);
      return o1;
  }
  
  public Ensemble intersection(Ensemble e1){//renvoie un nouvel ensemble ne contenant que les éléments contenus à la fois dans l'ensemble courant et dans l'ensemble envoyé en paramètre.
  
      Ensemble e= new Ensemble();
      e.copie();
      e.getList().retainAll(e1.getList());
      return e;
  }
  
  public List<Object>getList(){
  
    return liste;
  }
}