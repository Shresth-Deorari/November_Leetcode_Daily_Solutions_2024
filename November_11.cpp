class Solution {
    vector<int> Primes;

private:
    void getPrimes(int n) {
        vector<bool> markPrime(n + 1, 1);
        markPrime[0] = 0;
        markPrime[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (markPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    markPrime[j] = 0;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (markPrime[i]) Primes.push_back(i);
        }
    }

    void getFloor(int x, int low, int high, int &ans) {

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (Primes[mid] <= x) {
                ans = Primes[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        getPrimes(maxi);

        int prime = -1;
        getFloor(nums[0]-1, 0, Primes.size() - 1, prime);
        if (prime != -1) nums[0] -= prime;

        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i - 1];
            prime = -1;
            getFloor(diff - 1, 0, Primes.size() - 1, prime);
            if (prime != -1) nums[i] -= prime;
        }
        cout<<nums[0]<<" ";
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }
};