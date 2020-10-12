using System;
using System.Collections.Generic;
namespace LeetCode387
{
	public class Solution {
	    public int FirstUniqChar(string s) {
	        List<List<int>> checkChars = new List<List<int>>();
	        for(int i = 0 ; i < 26;++i){
	            checkChars.Add(new List<int>());
	        }
 
	        for(int i = 0 ; i < s.Length;++i){
	            checkChars[s[i] - 'a'].Add(i);
	        }
 
	        bool isUniqueFind = false;
	        int minIndex = 99999999;
	        for(int i = 0 ; i < 26;++i){
	            if(checkChars[i].Count == 1){
	                isUniqueFind = true;
	                if(checkChars[i][0] < minIndex){
	                    minIndex = checkChars[i][0];
	                }
	            }
	        }
 
	        if(isUniqueFind){
	            return minIndex;
	        }
	        else{
	            return -1;
	        }
	    }
	}
 
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.FirstUniqChar("leetcode"));
			Console.WriteLine(sol.FirstUniqChar("aabbcc"));
			Console.WriteLine(sol.FirstUniqChar("abcabcd"));
			Console.Read();
		}
	}
}