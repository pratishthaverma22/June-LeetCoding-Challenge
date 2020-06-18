/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution(object):
     def solve(self, board):
         """
         :type board: List[List[str]]
         :rtype: void Do not return anything, modify board in-place instead.
         """
 
         if not board:
             return
 
         m = len(board)
         n = len(board[0])
 
         queue = []
 
         for i in range(m):
             for j in range(n):
                 if i == 0 or j == 0 or i == m -1 or j == n-1:
                     if board[i][j] == 'O':
                         queue.append([i,j])
 
         while queue:
             [p,q] = queue.pop(0)
             board[p][q] ='V'
             if self.isValid(p+1, q, m, n) and board[p+1][q] == 'O':
                 queue.append([p+1, q])
             if self.isValid(p-1, q, m, n) and board[p-1][q] == 'O':
                 queue.append([p-1, q])
             if self.isValid(p, q+1, m, n) and board[p][q+1] == 'O':
                 queue.append([p, q+1])
             if self.isValid(p, q-1, m, n) and board[p][q-1] == 'O':
                 queue.append([p, q-1])
 
         for i in range(m):
             for j in range(n):
                 if board[i][j] == 'V':
                     board[i][j] ='O'
                 elif board[i][j] == 'O':
                     board[i][j] ='X'
 
     def isValid(self, i,j, m, n):
         return i>0 and i<m and j>0 and j<n
