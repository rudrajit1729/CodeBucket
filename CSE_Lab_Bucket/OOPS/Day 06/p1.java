import java.io.*;
class p1{
	public static void main(String args[]){
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		if (args.length > 0){
			int n = Integer.parseInt(args[0]);
			int i, d, A[] = new int[n], t;
			// Input Array
			for(i = 0; i < n; i++)
				A[i] = Integer.parseInt(args[i+1]);
			// Insertion Sort
			for(i = 1; i < n; i++){
				d = i;
				while(d > 0 && A[d] < A[d-1]){
					t = A[d]; A[d] = A[d-1]; A[d-1] = t;
					d--;
				}
			}
			// Print Array
			System.out.println("Sorted Array: ");
			for(i = 0; i < n; i++)
				System.out.print(A[i] + " ");
			System.out.println();
		}
		else
			System.out.println("No args passed");
	}
}