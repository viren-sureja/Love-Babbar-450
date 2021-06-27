/*
    link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

    sol: https://www.geeksforgeeks.org/the-celebrity-problem/

    video (using stack explanation): https://youtu.be/CiiXBvrX-5A
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N)
    SC: O(N)
*/
int celebrity(vector<vector<int> >& M, int n)
{
    stack<int> st;

    // pushing all the member
    for (int i = 0;i < n;i++) {
        st.push(i);
    }

    // execute logic till the last person.
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // means a follows b hence a is not celebrity and b is pushed .
        if (M[a][b] == 1) st.push(b);
        // means a doesn't follow b hence b is not celebrity and a is pushed .
        else st.push(a);
    }

    // the only remaining at top **could** be a celebrity.
    int celeb = st.top();

    // now if celeb follows someone and if someone doesn't follows celeb means celeb doesn't exist.
    for (int i = 0;i < n;i++) {
        if (celeb != i && (M[celeb][i] == 1 || M[i][celeb] == 0)) {
            return -1;
        }
    }

    // after passing everything finally we got celeb.
    return celeb;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive solution
    TC: O(N^2)
    SC: O(1)
*/

int celebrity(vector<vector<int> >& M, int n)
{
    int ans = -1, flag = 1;

    // finding the celebrity who is not following anybody.
    for (int i = 0;i < n;i++) {
        flag = 1;
        for (int j = 0;j < n;j++) {
            if (M[i][j] == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = i;
            break;
        }
    }

    // if no such celeb is found.
    if (ans == -1) return -1;

    // now confirming is there any case where celeb is following someone, and someone is not following celeb.
    for (int j = 0;j < n;j++) {
        if (ans != j && (M[ans][j] == 1 || M[j][ans] == 0)) {
            return -1;
        }
    }

    return ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using graph (in array)
    TC: O(N^2)
    SC: O(1)
*/
// Returns -1 if celebrity is not present. If present, returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    //the graph needs not be constructed
    //as the edges can be found by
    //using knows function

    //degree array;
    int indegree[n] = { 0 }, outdegree[n] = { 0 };

    //query for all edges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = knows(i, j);

            //set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    //find a person with indegree n-1
    //and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;

    return -1;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(N)
    SC: O(1)
*/

// Returns -1 if a 'potential celebrity'
// is not present. If present,
// returns id (value from 0 to n-1).
int findPotentialCelebrity(int n)
{
    // base case - when n reaches 0 , returns -1
    // since n represents the number of people,
    // 0 people implies no celebrity(= -1)
    if (n == 0)
        return -1;

    // find the celebrity with n-1
    // persons
    int id = findPotentialCelebrity(n - 1);

    // if there are no celebrities
    if (id == -1)
        return n - 1;

    // if the id knows the nth person
    // then the id cannot be a celebrity, but nth person
    // could be one
    else if (knows(id, n - 1)) {
        return n - 1;
    }
    // if the nth person knows the id,
    // then the nth person cannot be a celebrity and the id
    // could be one
    else if (knows(n - 1, id)) {
        return id;
    }

    // if there is no celebrity
    return -1;
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
// a wrapper over findCelebrity
int Celebrity(int n)
{
    // find the celebrity
    int id = findPotentialCelebrity(n);

    // check if the celebrity found
    // is really the celebrity
    if (id == -1)
        return id;
    else {
        int c1 = 0, c2 = 0;

        // check the id is really the
        // celebrity
        for (int i = 0; i < n; i++)
            if (i != id) {
                c1 += knows(id, i);
                c2 += knows(i, id);
            }

        // if the person is known to
        // everyone.
        if (c1 == 0 && c2 == n - 1)
            return id;

        return -1;
    }
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using 2 pointer technique
    TC: O(N)
    SC: O(1)
*/
int celebrity(vector<vector<int> >& M, int n) {
    int i = 0, j = n - 1, celeb = -1;

    // eliminating those which are not celeb.
    while (i < j) {

        // i follows j, means i is not celeb
        if (M[i][j] == 1) {
            celeb = j;
            i++;
        }
        // i doesn't follow j, means j is not celeb
        else {
            j--;
            celeb = i;
        }
    }

    // checking if celeb is not following someone, and everyone is following celeb.
    for (int i = 0;i < n;i++) {
        if (celeb != i && (M[celeb][i] == 1 || M[i][celeb] == 0)) {
            return -1;
        }
    }
    return celeb;
}