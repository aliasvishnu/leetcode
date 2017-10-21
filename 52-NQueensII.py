class Solution(object):

    def __init__(self):
        self.answer = 0
    def function(self, r, c, s2, s3, s4, n):
        # print r, c
        if(r == n-1):
            self.answer += 1
            return


        s2.add(c)
        s3.add(r-c)
        s4.add(r+c)

        for j in range(0, n):
            if j not in s2 and r+1+j not in s4 and r+1-j not in s3:
                self.function(r+1, j, s2, s3, s4, n)

        s2.remove(c)
        s3.remove(r-c)
        s4.remove(r+c)

    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """

        for j in range(0, n):
            self.function(0, j, set(), set(), set(), n)
        return self.answer



        
