/*
    link: https://leetcode.com/problems/word-ladder/

    video (just to understand the concept): https://youtu.be/ZVJ3asMoZ18

    code given in video has  O(N * L * logN * 26)
    see at this time: https://youtu.be/ZVJ3asMoZ18?t=972

    but in my code below if we use hashing for storing the complexity will be same
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC:
    N: size of wordList
    L: size of each word

    both while loop: O(N) => as iterating every vertex once
    diffByOneLetter(): O(N * L)
    => as we r maintaining vis array so it will make sure all word are visited once


    so overall time complexity: O(N * N * L)

*/
vector<int> diffByOneLetter(string curr, vector<int>& vis, vector<string>& wordList) {
    vector<int> idx;

    for (int i = 0;i < wordList.size();i++) {
        if (!vis[i]) {
            int c = 0;
            int cnt = 0;
            while (c < curr.size()) {
                if (curr[c] != wordList[i][c]) cnt++;
                c++;
            }
            // words which are diff. by 1 letter
            if (cnt == 1) {
                idx.push_back(i);
                vis[i] = 1;
            }
        }
    }

    return idx;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    vector<int> vis(wordList.size(), 0);

    queue<string> q;
    q.push(beginWord);

    int level = 1;

    while (!q.empty()) {
        int size = q.size();

        //  iterating by level
        while (size--) {
            string curr = q.front();
            q.pop();

            // endWord is not present
            if (curr == endWord) {
                return level;
            }

            vector<int> idx = diffByOneLetter(curr, vis, wordList);

            for (auto i : idx) q.push(wordList[i]);
        }

        // words with just diff from current q have been visited
        level++;
    }

    // endword was not reachable or wasn't present
    return 0;
}