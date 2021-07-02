/*
    link: https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/

    variation of backtracking
    video: https://youtu.be/KU7Ae2513h0

    ref: oneNote
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    DP in java

    this code has bugs, trace it just for learning

    Time Complexity: O(n),
    where n is the length of the string.
    The dp array creation would take O(4*n*3) = O(12n) = O(n).
    Valid IP creation from dp array would take O(n).

    Auxiliary Space: O(n). As dp array has extra space of size (4 x n). It means O(4n).
*/

class GFG
{
    public static ArrayList<String> list;

    // Function to restore Ip Addresses
    public static ArrayList<String> restoreIpAddresses(String s)
    {
        int n = s.length();
        list = new ArrayList<>();
        if (n < 4 || n > 12)
            return list;

        // initialize the dp array
        int dp[][] = new int[4][n];
        for (int i = 0; i < 4; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == 0)
                {
                    // take the substring
                    String sub = s.substring(j);
                    if (isValid(sub))
                    {
                        dp[i][j] = 1;
                    }
                    else if (j < n - 3)
                    {
                        break;
                    }
                }
                else
                {
                    if (j <= n - i)
                    {
                        for (int k = 1;
                            k <= 3 && j + k <= n;
                            k++)
                        {
                            String temp
                                = s.substring(j, j + k);
                            if (isValid(temp))
                            {
                                if (j + k < n
                                    && dp[i - 1][j + k]
                                    == 1)
                                {
                                    dp[i][j] = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (dp[3][0] == 0)
            return list;


        // Call function createfromDp
        createIpFromDp(dp, 3, 0, s, "");
        return list;
    }

    public static void createIpFromDp(int dp[][], int r, int c, String s, String ans)
    {
        if (r == 0)
        {
            ans += s.substring(c);
            list.add(ans);
            return;
        }
        for (int i = 1; i <= 3 && c + i < s.length(); i++)
        {
            if (isValid(s.substring(c, c + i)) && dp[r - 1] == 1)
            {
                createIpFromDp(dp, r - 1, c + i, s, ans + s.substring(c, c + i) + ".");
            }
        }
    }



    private static boolean isValid(String ip)
    {
        String a[] = ip.split("[.]");
        for (String s : a)
        {
            int i = Integer.parseInt(s);
            if (s.length() > 3 || i < 0 || i > 255)
            {
                return false;
            }
            if (s.length() > 1 && i == 0)
                return false;
            if (s.length() > 1 && i != 0 && s.charAt(0) == '0')
                return false;
        }

        return true;
    }

    // Driver Code
    public static void main(String[] args)
    {
        // Function call
        System.out.println(
            restoreIpAddresses("25525511135").toString());
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive algorithm

    Time Complexity: O(n^3), where n is the length of the string
    Three nested traversal of the string is needed, where n is always less than 12.

    Auxiliary Space: O(n). As as extra space is needed.
*/
int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        }
        else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    // Checking for the corner cases
    for (int i = 0; i < ips.size(); i++) {

        // not greater than 3, or less than 0, or out of bound
        if (ips[i].length() > 3
            || stoi(ips[i]) < 0
            || stoi(ips[i]) > 255)
            return 0;

        // no more than zereos are allowed.
        if (ips[i].length() > 1
            && stoi(ips[i]) == 0)
            return 0;

        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
            return 0;
    }
    return 1;
}

// Function converts string to IP address
void convert(string ip)
{
    int l = ip.length();

    // Check for string size
    if (l > 12 || l < 4) {
        cout << "Not Valid IP Address";
    }

    string check = ip;
    vector<string> ans;

    // Generating different combinations.
    for (int i = 1; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1; k < l; k++) {
                check = check.substr(0, k) + "."
                    + check.substr(k, l - k + 2);
                    // here check.substr(k) will also work
                check
                    = check.substr(0, j) + "."
                    + check.substr(j, l - j + 3);
                    // here check.substr(j) will also work
                check
                    = check.substr(0, i) + "."
                    + check.substr(i, l - i + 4);
                    // here check.substr(i) will also work


                // Check for the validity of combination
                if (is_valid(check)) {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}

// Driver code
int main()
{
    string A = "25525511135";
    string B = "25505011535";

    convert(A);
    convert(B);

    return 0;
}




