public class TestEnsemble{


  public static void main(String[] args){
    
  
    Ensemble e = new Ensemble();
    System.out.println("Vide ?:" +e.estVide());
    Object o = new Object();
    e.ajouter(o);
    System.out.println("taille e"+e.taille());
    System.out.println("Vide ?:" +e.estVide());
    System.out.println("contient :"+e.contient(o));
    Object o1 = new Object();
    System.out.println("contient :"+e.contient(o1));
    //System.out.println("obtenir :"+e.obtenir(o));
    Ensemble e2 = new Ensemble();
    //e2=e.copie();
    System.out.println("taille e2:"+e2.taille());
   // System.out.println("retournerEnlever :"+e.retournerEnlever(o));
    System.out.println("taille e "+e.taille());
    Object o3 = new Object();
    Object o4 = new Object();
    e.ajouter(o);
    e.ajouter(o1);
    e.ajouter(o3);
    e2.ajouter(o1);
    e2.ajouter(o);
    System.out.println("taille e2:"+e2.taille());
    System.out.println("taille e "+e.taille());
    Ensemble e3=new Ensemble();
    e3=e.intersection(e2);
    System.out.println("taille e "+e3.taille());
  }



}