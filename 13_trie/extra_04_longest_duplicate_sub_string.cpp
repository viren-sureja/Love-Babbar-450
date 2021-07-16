/*
    link: https://youtu.be/FQ8hcOOzQMU?list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#define p 10000007
//#define lli long long int

vector<int> roll;

class Solution {
    bool match(string s, int len, int size, string& ans)
    {
        unordered_map<int, vector<int>> m;   //Key->hashValue...Value->starting index of substring
        int hash = 0;   //curr window hash
        for (int i = 0;i < size;++i)
            hash = (hash * 26 + (s[i] - 'a')) % p;

        m[hash].push_back(0);
        //Rolling hash (sliding window)
        for (int j = size;j < len;++j)
        {
            hash = ((hash - roll[size - 1] * (s[j - size] - 'a')) % p + p) % p;
            hash = (hash * 26 + (s[j] - 'a')) % p;
            if (m.find(hash) != m.end())
            {
                for (auto start : m[hash])
                {
                    string temp = s.substr(start, size);
                    string curr = s.substr(j - size + 1, size);
                    if (temp.compare(curr) == 0)
                    {
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j - size + 1);
        }
        return false;
    }

    public:
    string longestDupSubstring(string S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int len = S.size();
        if (len == 0)
            return "";

        //Store all rolling hash values
        roll.resize(len);  //Allocating fixed space to array
        roll[0] = 1;    //Since 26^0 = 1
        for (int i = 1;i < len;++i)
            roll[i] = (26 * roll[i - 1]) % p;

        int low = 1, high = len, mid;
        string ans = "", temp;
        while (low <= high)
        {
            temp = "";
            mid = low + (high - low) / 2;
            bool flag = match(S, len, mid, temp);
            if (flag)
            {
                if (temp.size() > ans.size())
                    ans = temp;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};