class Solution(object):

    def printBoard(self, board):
        ans = []
        for lst in board:
            ans.append("".join(lst))
        return ans

    def function(self, answers, board, r, c, s2, s3, s4, n):
        # print r, c
        if(r == n-1):

            board[r][c] = 'Q'
            # print board
            answers.append(self.printBoard(board))
            board[r][c] = '.'
            return

        board[r][c] = 'Q'
        # print board
        s2.add(c)
        s3.add(r-c)
        s4.add(r+c)

        for j in range(0, n):
            if j not in s2 and r+1+j not in s4 and r+1-j not in s3:
                self.function(answers, board, r+1, j, s2, s3, s4, n)

        board[r][c] = '.'
        s2.remove(c)
        s3.remove(r-c)
        s4.remove(r+c)

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        if n == 0:
            return [[]]
        board = d = [['.' for i in xrange(n)] for x in xrange(n)]
        answers = []

        for j in range(0, n):
            self.function(answers, board, 0, j, set(), set(), set(), n)
        return answers


        
