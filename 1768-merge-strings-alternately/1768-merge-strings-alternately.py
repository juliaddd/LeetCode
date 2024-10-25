class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        i = 0
        for i in range(len(word1)):
            ans+=word1[i]
            if i < len(word2):
                ans+=word2[i]

        if i < len(word2):
            for j in range(i+1, len(word2)):
                ans+= word2[j]

        return ans