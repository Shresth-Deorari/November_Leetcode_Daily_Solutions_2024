class Solution {
private:
    int getUntoggled(const long long &x, long long untoggled) {
        while ((x & (1LL << untoggled)) != 0) {
            untoggled++;
        }
        return untoggled;
    }
public:
    long long minEnd(int n, int X) {
        long long bitToggle = n - 1;
        long long untoggled = 0;
        long long x = X;
        
        while (bitToggle) {
            long long toggle = (bitToggle & 1);
            untoggled = getUntoggled(x, untoggled);
            x = x | (toggle << untoggled);
            untoggled++;
            bitToggle >>= 1;
        }
        
        return x;
    }
};
