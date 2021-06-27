/*
    link: https://practice.geeksforgeeks.org/problems/game-with-string4100/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using max_heap and map
*/
int minValue(string s, int k) {
    map<char, int> mp;
    priority_queue<int> pq;

    // for count of character
    for (int i = 0;i < s.size();i++)
        mp[s[i]]++;

    // get all the count in max_heap
    for (auto it = mp.begin();it != mp.end();it++)
        pq.push(it->second);

    // pop one ele. reduce by 1 and push back
    while (k--) {
        int x = pq.top();
        x--;
        pq.pop();
        pq.push(x);
    }

    // getting result by squaring
    int result = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        result += (x * x);
    }
    return result;
}
