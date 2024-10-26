class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
       
        for i in range(len(flowerbed)):
            if n != 0:
                if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == len(flowerbed)-1 or flowerbed[i+1] == 0 or len(flowerbed) == 1):
                    flowerbed[i] = 1
                    n-=1
                    if n == 0:
                        return True
            else:
                return True
        return False