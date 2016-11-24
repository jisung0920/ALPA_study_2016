package ALPA;
import java.util.*;

public class LUfactoring {
	Scanner sc = new Scanner(System.in);
	int i,j;
	double input, a1,b1,c1,a2,b2,c2,a3,b3,c3,m1,m2,m3;
	double [][] arr = new double[3][3];
	public void insert(){
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				System.out.print(i+1+"행 "+(j+1)+"열 을 입력해주세요");
				input = sc.nextInt();
				arr[i][j] = input;
				}		
			}
		a1 = arr[0][0];
		a2 = arr[0][1];
		a3 = arr[0][2];
		b1 = arr[1][0];
		b2 = arr[1][1];
		b3 = arr[1][2];
		c1 = arr[2][0];
		c2 = arr[2][1];
		c3 = arr[2][2];
		print();
		calc1();
		}
	public void calc1(){ //3행과 1행을 비교해서 계산하는 과정
		if(c1==0){
			m1 =0;
			System.out.println("첫번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc2();
		}
		else if(c1 == a1){
			m1 = 1;
			c1 = 0;
			c2 = c2 -a2;
			c3 = c3 -a3;
			System.out.println("첫번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc2();
			
		}else if(a1*c1>0){
			m1 = c1/a1;
			double temp;
			temp = c1;
			c1 = c1-(a1*c1)/a1;
			c2 = c2-(a2*temp)/a1;
			c3 = c3-(a3*temp)/a1;
			System.out.println("첫번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc2();
		}else if(a1*c1<0){
			m1 = c1/a1;
			double temp;
			temp = c1;
			c1 = c1-(a1*c1)/a1;
			c2 = c2-(a2*temp)/a1;
			c3 = c3-(a3*temp)/a1;
			System.out.println("첫번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc2();
		}
	}
	public void calc2(){ //2행과 1행을 비교해서 계산하는 과정
		if(b1==0){
			m2 = 0;
			calc3();
			System.out.println("두번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
		}	
		else if(b1 == a1){
			m2 = 1;
			b1 = 0;
			b2 = b2 -a2;
			b3 = b3 -a3;
			System.out.println("두번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc3();
		}else if(b1*a1>0){
			m2 = b1/a1;
			double temp;
			temp = b1;
			b1 = b1-(a1*b1)/a1;
			b2 = b2-(a2*temp)/a1;
			b3 = b3-(a3*temp)/a1;
			
			System.out.println("두번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc3();
		}else if(b1*a1<0){
			m2 = b1/a1;
			double temp;
			temp = b1;
			b1 = b1-(a1*b1)/a1;
			b2 = b2-(a2*temp)/a1;
			b3 = b3-(a3*temp)/a1;
			System.out.println("두번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			calc3();
		}
	}
	public void calc3(){
		if(c2==0){
			m3 = 0;
			System.out.println("세번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.println("upper case는 다음과같습니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.print("lower case는 다음과 같습니다\n");
			lower();
		}else if(c2==b2){
			m3 = 1;
			b1 = 0;
			b2 = b2 -c2;
			b3 = b3 -c3;
			System.out.println("세번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.println("upper case는 다음과같습니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.print("lower case는 다음과 같습니다\n");
			lower();
		}else if(c2*b2>0){
			m3 = c2/b2;
			double temp;
			temp = c2;
			c2 = c2-(b2*c2)/b2;
			c3 = c3-(b3*temp)/b2;
			System.out.println("세번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.println("upper case는 다음과같습니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.print("lower case는 다음과 같습니다\n");
			lower();
		}else if(c2*b2<0){
			m3 = c2/b2;
			double temp;
			temp = c2;
			c2 = c2-(b2*c2)/b2;
			c3 = c3-(b3*temp)/b2;
			System.out.println("세번째 과정입니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3);
			System.out.println("upper case는 다음과같습니다\n"+a1+" "+a2+" "+a3+" "+"\n"+b1+" "+b2+" "+b3+" "+"\n"+c1+" "+c2+" "+c3+"\n");
			System.out.print("lower case는 다음과 같습니다\n");
			lower();
		}
	}
	
	public void lower(){	//LU에서 lower case
		double [][] arr2 = new double[3][3];
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==j)
					arr2[i][j] = 1;
				if(i<j)
					arr2[i][j] = 0;
				}}
		arr2[2][0] = m1;
		arr2[1][0] = m2;
		arr2[2][1] = m3;
		for(int i=0; i<3;i++){
			for(int j=0; j<3; j++){
				System.out.print(arr2[i][j]+" ");
			}
			System.out.println();
		}
	}
	public void print(){
		for(int i=0; i<3;i++){
			for(int j=0; j<3; j++){
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.print("factorization을 시작합니다\n");
	}
}
