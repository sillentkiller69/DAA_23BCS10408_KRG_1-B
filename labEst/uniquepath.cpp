class Solution {
public:
    int uniquePaths(int z, int x) {
        return uniquePath(z,x); 
    }

 long long uniquePath(int n, int m) {
    long long res = 1;
    int k = min(n - 1, m - 1);
    for (int i = 1; i <= k; i++) {
        res = res * (n + m - 2 - i + 1) / i;
    }
    return res;
}
   
};
 


 