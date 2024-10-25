class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n = min(len(str1), len(str2))
        ans = ""
        for i in range(1,n+1):
            substr = str1[0:i]
            if str1.find(substr) == str2.find(substr):
                if str1.count(substr) == len(str1) / len(substr):
                    if str2.count(substr) == len(str2)/ len(substr):
                        ans = substr
                    else:
                        continue
            else:
                return ans
        return ans