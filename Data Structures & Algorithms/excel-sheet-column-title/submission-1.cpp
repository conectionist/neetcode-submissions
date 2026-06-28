class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while(columnNumber > 0)
        {
            columnNumber--;
            int rem = columnNumber % 26;
            char c = 'A' + rem;
            result = c + result;
            columnNumber /= 26;
        }

        return result;
    }
};