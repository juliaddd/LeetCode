class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        while (word1 !="")
        {
            output.append(word1.substr(0,1));
            output.append(word2.substr(0,1));
            word1.erase(0,1);
            word2.erase(0,1);
        }

        output.append(word2);
        return output;
    }
};