class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        if(n < 2)
            return true;

        int i = 0;
        int j = n-1;

        while(i < j)
        {
            if(!std::isalnum(s[i]))
            {
                i++;
                continue;
            }

            if(!std::isalnum(s[j]))
            {
                j--;
                continue;
            }

            if(std::tolower(s[i]) != std::tolower(s[j]))
                return false;

            i++;
            j--;
        }
            
        return true;
    }
};
