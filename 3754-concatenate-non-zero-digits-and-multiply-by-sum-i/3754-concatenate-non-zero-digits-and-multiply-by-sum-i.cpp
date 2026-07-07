class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n);
        string temp = "";

        for (char c : s) {
            if (c != '0')
                temp += c;
        }

        if (temp.empty())
            return 0;

        long long x = stoll(temp);
        long long sum = 0;

        for (char c : temp)
            sum += c - '0';

        return x * sum;
    }
};