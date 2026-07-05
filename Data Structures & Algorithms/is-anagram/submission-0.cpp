class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> appearances;

        for(int i = 0 ; i < s.size() ; i++)
        {
            appearances[s[i]]++;
            appearances[t[i]]--;
        }

        for(const auto& [ch, count] : appearances)
            if(count != 0)
                return false;
        
        return true;
    }
};
