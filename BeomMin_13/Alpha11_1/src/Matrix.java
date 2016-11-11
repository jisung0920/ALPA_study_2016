import java.util.Scanner;

public class Matrix {
	Scanner input = new Scanner(System.in);
	double[][] matrix;
	double[][] Lmatrix;

	public void InputMatrix() {
		System.out.println("Input n x n Matrix Size");
		int MatrixSize = input.nextInt();
		matrix = new double[MatrixSize][MatrixSize];
		Lmatrix = new double[MatrixSize][MatrixSize];

		System.out.println("Input Matrix elements");
		
		for (int i = 0; i < MatrixSize; i++) {
			for (int j = 0; j < MatrixSize; j++) {
				int MatrixEle = input.nextInt();
				matrix[i][j] = MatrixEle;

			}
		}
	}
	public void ShowMatrix() {
		for (int i = 0; i < matrix.length; i++ ) {
			for (int j = 0; j < matrix.length; j ++) {
				System.out.print(Math.round(matrix[i][j]*100)/100.0 + "  ");
				if (j==matrix.length-1) {
					System.out.println("");
				}
			}
		}

	}
	
	public void ComputeLU() {
		for (int i = 0; i < Lmatrix.length; i++) {
			Lmatrix[i][i] = 1;
		}
		for (int i = 1; i < matrix.length; i++) {
			for (int j = 0; j < i; j++){
				while (matrix[i][j] != 0) {
					double R = (double)(matrix[i][j])/(double)(matrix[j][j]);
					Lmatrix[i][j] = R;
						for (int k = 0; k < matrix.length; k++) {
						matrix[i][k] = matrix[i][k] - R*matrix[j][k];
						}
				}
			}
		}
	}
	public void ShowLMatrix() {
		for (int i = 0; i < Lmatrix.length; i++ ) {
			for (int j = 0; j < Lmatrix.length; j ++) {
				System.out.print(Math.round(Lmatrix[i][j]*100)/100.0 + "  ");
				if (j==matrix.length-1) {
					System.out.println("");
				}
			}
		}

	}

}

