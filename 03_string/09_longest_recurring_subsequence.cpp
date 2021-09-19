/*
    link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

    ref: DP/8_longest_repeated...
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int LongestRepeatingSubsequence(string s){
	int n = s.size();
    
	int memo[n+1][n+1];
    
	for(int i = 0; i <= n; i++){
		 for(int j = 0; j <= n; j++){
		     if(i == 0 or j == 0)
		         memo[i][j] = 0;
		                
		     else if(s[i-1] == s[j-1] and i != j)
		         memo[i][j] = 1 + memo[i-1][j-1];
		                
		     else
		         memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		 }
	}
		    
	return memo[n][n];
		    
}
