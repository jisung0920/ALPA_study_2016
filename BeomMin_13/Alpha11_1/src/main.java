
public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Matrix M = new Matrix();
		M.InputMatrix();
		System.out.println("Show Initial Matrix");
		M.ShowMatrix();
		M.ComputeLU();
		System.out.println("Show U");
		M.ShowMatrix();
		System.out.println("Show L");
		M.ShowLMatrix();
	}

}
