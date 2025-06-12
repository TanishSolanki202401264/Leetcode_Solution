class Solution {
public:
    string add(string num1, string num2) {
        string ans;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int carry = 0;
        while (index2 >= 0) {
            int sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans = c + ans;
            index1--;
            index2--;
        }
        while (index1 >= 0) {
            int sum = (num1[index1] - '0') + carry;
            carry = sum / 10;
            char c = '0' + (sum % 10);
            ans = c + ans;
            index1--;
        }
        if (carry > 0) {
            ans = (char)('0' + carry) + ans;
        }

        return ans;
    }

    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) {
            return add(num2, num1);
        } else {
            return add(num1, num2);
        }
    }
};

