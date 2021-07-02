/*
    link: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

    video: https://youtu.be/1LkOrc-Le-Y
    (watch video as this problem is having many logic, hence require precise steps)

    => other solution to go through
    sol: https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
    sol2: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/


    left side will be maxHeap and right side will be minHeap
*/


// ----------------------------------------------------------------------------------------------------------------------- //
class MedianFinder {
public:
    priority_queue<int> maxheap; //1st half (left half)
    priority_queue<int, vector<int>, greater<int>> minheap; //2nd half (Right half)
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize == 0)    //num is the 1st element in stream
            maxheap.push(num);
        else if (lsize == rsize)   //Push one element in maxheap for sure
        {
            if (num < minheap.top())   //num can be pushed to maxheap (1st half) to maintain order
                maxheap.push(num);
            else    //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minheap.top();   //Save root of minheap
                minheap.pop();  //Pop the root from minheap
                minheap.push(num);  //Push num in minheap
                maxheap.push(temp); //Push the previous saved root of minheap in the maxheap
            }
        }
        else    ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if (minheap.size() == 0)
            {
                if (num > maxheap.top()) //Push num to 2nd half
                    minheap.push(num);
                else //Push num to 1st half
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if (num >= minheap.top()) //Push the element directly in minheap (2nd half)
                minheap.push(num);
            else    //Push root of maxheap to minheap
            {
                if (num < maxheap.top())   //Push num to 1st half
                {
                    int temp = maxheap.top();   //Save root of maxheap
                    maxheap.pop();  //Pop root of maxheap
                    maxheap.push(num);  //Push num to maxheap
                    minheap.push(temp); //Push previous saved root of maxheap to minheap
                }
                else    //Push num to 2nd half
                    minheap.push(num);
            }
        }
    }

    double findMedian() {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(maxheap.top());
        else    //Else return avg of top of maxheap and minheap
            return (double(maxheap.top()) + double(minheap.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */







// ----------------------------------------------------------------------------------------------------------------------- //
/* ACCEPTED CODE for GFG */
class Solution {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
//Function to insert heap.
    void insertHeap(int& num)
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize == 0)    //num is the 1st element in stream
            maxheap.push(num);
        else if (lsize == rsize)   //Push one element in maxheap for sure
        {
            if (num < minheap.top())   //num can be pushed to maxheap (1st half) to maintain order
                maxheap.push(num);
            else    //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minheap.top();   //Save root of minheap
                minheap.pop();  //Pop the root from minheap
                minheap.push(num);  //Push num in minheap
                maxheap.push(temp); //Push the previous saved root of minheap in the maxheap
            }
        }
        else    ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if (minheap.size() == 0)
            {
                if (num > maxheap.top()) //Push num to 2nd half
                    minheap.push(num);
                else //Push num to 1st half
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if (num >= minheap.top()) //Push the element directly in minheap (2nd half)
                minheap.push(num);
            else    //Push root of maxheap to minheap
            {
                if (num < maxheap.top())   //Push num to 1st half
                {
                    int temp = maxheap.top();   //Save root of maxheap
                    maxheap.pop();  //Pop root of maxheap
                    maxheap.push(num);  //Push num to maxheap
                    minheap.push(temp); //Push previous saved root of maxheap to minheap
                }
                else    //Push num to 2nd half
                    minheap.push(num);
            }
        }
    }

    //Function to balance heaps.
    void balanceHeaps()
    {

    }

    //Function to return Median.
    double getMedian()
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if (lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(maxheap.top());
        else    //Else return avg of top of maxheap and minheap
            return (double(maxheap.top()) + double(minheap.top())) / 2;
    }
}