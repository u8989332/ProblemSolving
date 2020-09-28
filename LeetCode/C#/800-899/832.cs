using System;
					
public class Program
{
	public class Solution {
		public int[][] FlipAndInvertImage(int[][] A) {
			int n = A.Length;
			int[][] ans = new int[n][];
			for(int i = 0 ; i < n;++i){
				ans[i] = new int[n];
			}

			for(int i = 0 ;i < n;++i){
				int[] row = new int[n];
				for(int j = 0;j < n;++j){
					row[n-j-1] = A[i][j] == 1 ? 0 : 1;
				}

				ans[i] = row;
			}

			return ans; 
		}
	}
	
	public static void Main()
	{
		int[][] A =
		{
			new int[] { 1,1,0,0 },
			new int[] { 1,0,0,1 },
			new int[] { 0,1,1,1 },
			new int[] { 1,0,1,0 }
		};
		
		Solution sol = new Solution();
		var ans = sol.FlipAndInvertImage(A);
		
		foreach(var row in ans){
			foreach(int col in row){
				Console.Write(" " + col);
			}
			Console.WriteLine();
		}
		
		Console.Read();
	}
}