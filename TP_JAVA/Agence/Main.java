
public class Main {

	
	public static void main(String[] args){
	
		Bureau b1= new Bureau("Angers","0241123456",4,"",5);


		Garage g1 = new Garage("Angers Sud","0241234567",1,"",6);

		
		System.out.println(b1.afficherBureau());
		System.out.println(g1.afficherGarage());

	}
	
}
