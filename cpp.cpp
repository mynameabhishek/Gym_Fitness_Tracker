#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 1) Strip off the maximal matching prefix/suffix
        int l = 0, r = n-1;
        while (l < r && a[l] == a[r]) {
            l++; 
            r--;
        }

        // 2) If fully matched (or reduced to size ≤1), it's already a palindrome
        if (l >= r) {
            cout << "YES\n";
            continue;
        }

        // 3) If k == 1, we can delete one element at a time anywhere → always YES
        if (k == 1) {
            cout << "YES\n";
            continue;
        }

        // 4) After stripping, the “core” segment [l..r] must be shrunk below length k
        //    in order to stop there and have a palindrome.  So if its current length
        //    is already < k, we can delete down into it in exactly the right number of
        //    operations.
        int coreLen = r - l + 1;
        if (coreLen < k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
