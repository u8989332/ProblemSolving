using System;
using System.Collections.Generic;

namespace LeetCode242
{
	public class Solution {
	    public bool IsAnagram(string s, string t) {
	        List<int> sCheck = new List<int>();
	        List<int> tCheck = new List<int>();
	        for(int i = 0 ; i < 26;++i){
	            sCheck.Add(0);
	            tCheck.Add(0);
	        }
	        
	        for(int i = 0 ; i < s.Length;++i){
	            sCheck[s[i] - 'a']++;
	        }
	        
	        for(int i = 0 ; i < t.Length;++i){
	            tCheck[t[i] - 'a']++;
	        }
	        
	        bool isSame = true;
	        for(int i = 0 ; i < 26;++i){
	            if(sCheck[i] != tCheck[i]){
	                isSame = false;
	                break;
	            }
	        }
	        
	        return isSame;
	    }
	}
	
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.IsAnagram("anagram", "nagaram"));
			Console.Read();
		}
	}
}
