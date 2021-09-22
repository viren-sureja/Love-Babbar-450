/*
    link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1

    for solutions: 14_DP/13_edit_distance.cpp
*/

/*********************************************************** CPP Code passing all Test Cases as of 22-09-2021 ********************************************************/

class Solution {
  public:
  
    int dist(string X, int m, string Y, int n){
        int T[m + 1][n + 1];
 
        memset(T, 0, sizeof T);

        for (int i = 1; i <= m; i++) {
            T[i][0] = i;             
        }
 
        for (int j = 1; j <= n; j++) {
            T[0][j] = j;               
        }
 
        int substitutionCost;
 
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1]) {               
                    substitutionCost = 0;                   
                }
                else {
                    substitutionCost = 1;                
                }
                T[i][j] = min(min(T[i - 1][j] + 1,         
                                T[i][j - 1] + 1),           
                    T[i - 1][j - 1] + substitutionCost);   
            }
        }
 
        return T[m][n];
        }
    
    
        int editDistance(string s, string t) {
            int m = s.length();
            int n = t.length();
        
            return (dist(s, m, t, n));
        }
};

