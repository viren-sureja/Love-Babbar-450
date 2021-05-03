/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    also refer to 26_sell_...twice.cpp
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int local = 0, global = 0;
    for (int i = 1;i < n;i++) {
        /*
            if the loss is going negative then make it 0 either continue with the profit as higher as possible.
        */
        local = max(0, local += prices[i] - prices[i - 1]);
        global = max(local, global);
    }
    return global;
}
