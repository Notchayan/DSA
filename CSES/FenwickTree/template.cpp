

class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int>& arr) {
        n = (int)arr.size();
        bit.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) update(i, arr[i - 1]);
    }

    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            bit[index] += value;
    }

    int prefixSum(int index) const {
        int result = 0;
        for (; index > 0; index -= index & -index)
            result += bit[index];
        return result;
    }

    int rangeSum(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }

};
