public class Swap {
	static void swap(int a[],int b[]){
		int c=a[0];
		a[0]=b[0];
		b[0]=c;
	}
	public static void main(String[] args) {
		int a=10,b=20;
		int[] A={a},B={b};
		swap(A,B);
		a=A[0];b=B[0];
		System.out.println(a+" "+b);


		int x=5,y=10;
		System.out.println(x+" "+y);
		int temp=x;
		x=y;
		y=temp;
		System.out.println(x+" "+y);
		x+=(y-(y=x));
		System.out.println(x+" "+y);		
	}
}
 