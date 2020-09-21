using System;
using System.Collections.Generic;

namespace LeetCode1094
{
        public class Passenger{
        public int loc;
        public int num;
    }

    public class CMP : IComparer<Passenger> 
    { 
        public int Compare(Passenger a, Passenger b) 
        { 
            if(a.loc != b.loc)
                return  a.loc < b.loc ? -1 : 1;

            return a.num < b.num ? -1 : 1;
        } 
    } 
    

    public class Solution {
        public bool CarPooling(int[][] trips, int capacity) {
            List<Passenger> list = new List<Passenger>();
            for(int i = 0 ; i < trips.Length; ++i){
                Passenger upPas = new Passenger();
                upPas.loc = trips[i][1];
                upPas.num = trips[i][0];
                list.Add(upPas);
                
                Passenger downPas = new Passenger();
                downPas.loc = trips[i][2];
                downPas.num = -trips[i][0];
                list.Add(downPas);
            }
            
            CMP cmp = new CMP(); 
            list.Sort(cmp);

            for(int i = 0 ; i < list.Count;++i){
                capacity -= list[i].num;
                if(capacity < 0){
                    return false;
                }
            }
            
            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[][] trips = new int[][]
            {
                new int[] {2,1,5},
                new int[] {3,5,7}
            };
            Console.WriteLine(new Solution().CarPooling(trips, 3));
            Console.Read();
        }
    }
}
