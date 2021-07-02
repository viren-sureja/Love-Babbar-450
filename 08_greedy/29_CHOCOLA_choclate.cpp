/*
	link: https://www.spoj.com/problems/CHOCOLA/

	video: https://youtu.be/9DckVBRzuQU

	refer: 12_min_cost....

	Note (read this para. in que. carefully): A single break of a part of the chocolate....
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int m, n;
		cin >> m >> n;

		m--;
		n--;

		vector<int> col(m), row(n);

		for (int& a : col) cin >> a;
		for (int& b : row) cin >> b;

		sort(col.begin(), col.end(), greater<>());
		sort(row.begin(), row.end(), greater<>());

		// debug(row);
		// debug(col);

		int rcnt = 1, ccnt = 1, i = 0, j = 0, res = 0;

		while (i < m && j < n) {
			if (col[i] > row[j]) {
				res += rcnt * col[i];

				ccnt++;
				i++;
			}
			else {
				res += ccnt * row[j];

				j++;
				rcnt++;
			}
		}

		int total = 0;
		while (i < m) {
			total += col[i++];
		}
		res += total * rcnt;

		total = 0;
		while (j < n) {
			total += row[j++];
		}
		res += total * ccnt;

		// return res;
		cout << res << endl;
	}

}