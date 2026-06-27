class Solution {
public:
    pair<char, char> getOrderedLetters(const string& word1, const string& word2)
    {
        int i = 0;
        int len = std::min(word1.size(), word2.size());

        while(i < len && word1[i] == word2[i])
            i++;

        if(i == len)
        {
            // word1 longer than word2 and is a prefix -> invalid
            if(word1.size() > word2.size())
                return {'\1', '\1'};
            
            return {'\0', '\0'};    // word1 is a prefix of word2 --> valid
        }

        return {word1[i], word2[i]};
    }

    string foreignDictionary(vector<string>& words) {
        string result;
        unordered_map<char, int> inDegrees;

        unordered_map<char, vector<char>> adj;

        // Seed every character that appears in the word list
        for(const auto& word : words)
            for(const char ch : word)
                inDegrees.try_emplace(ch, 0);

        // build the adjacency list
        for(int i = 0 ; i < words.size() - 1 ; i++)
        {
            auto [ch1, ch2] = getOrderedLetters(words[i], words[i+1]);

            if(ch1 == '\1') 
                return "";  // invalid input

            if(ch1 == '\0') 
                continue;   // valid but no ordering info, skip

            adj[ch1].push_back(ch2);
        }

        // Initialize all known nodes to 0
        // for (const auto& [ch, neighbors] : adj) 
        // {   
        //     inDegrees.try_emplace(ch, 0); // source nodes
        //     for (const auto& neighbor : neighbors)
        //         inDegrees.try_emplace(neighbor, 0); // sink nodes
        // }

        for(const auto& [ch, neighbors] : adj)
            for(const auto& neighbor : neighbors)
                inDegrees[neighbor]++;
        
        queue<char> q;
        
        for(const auto& [ch, inDegree] : inDegrees)
            if(inDegree == 0)
                q.push(ch);
        
        while(!q.empty())
        {
            auto ch = q.front();
            q.pop();
            result += ch;

            for(const auto& neighbor : adj[ch])
            {
                inDegrees[neighbor]--;

                if(inDegrees[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if(result.size() == inDegrees.size())
            return result;

        return "";
    }
};
