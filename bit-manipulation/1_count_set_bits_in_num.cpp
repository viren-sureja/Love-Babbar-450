// https://practice.geeksforgeeks.org/problems/set-bits0143/1

// ----------------------------------------------------------------------------------------------------------------------- //

// method 1
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        return __builtin_popcount(N);
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //

// method 2
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here

        int ans = 0;
        while (N) {
            if (N & 1) ans++;
            N = N >> 1;
        }
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //

// method 3
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here

        int ans = 0;
        for (int i = 0;i < 32;i++) {
            if (N & (1 << i)) ans++;
        }
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //