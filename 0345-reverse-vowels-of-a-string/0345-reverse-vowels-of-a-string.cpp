class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        string temp ="";
        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.find(s[i]) !=-1)
            {
                temp+= s[i];
            }
        }
        
        for(int i = 0; i < s.size(); i++)
        {
             if (vowels.find(s[i]) !=-1)
            {
                s[i] = temp[temp.size()-1] ;
                temp.pop_back();
            }
        }
        return s;
    }
};