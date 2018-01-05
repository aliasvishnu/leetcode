# Leetcode

Hints for ~250 leetcode problems. Mostly medium, some hard.
Good practice list for internships/job hunt.

If this helps you, please star the repo (I commit a lot, so I suggest you unwatch the repo).

Solutions <a href = "https://github.com/aliasvishnu/leetcode/tree/master/Solutions" > here </a>

## Abbreviations
* BF - Brute Force, many times I use Array and BF interchangeably; just implement the obvious logic.
* DP - Dynamic Programming
* Array - Problem specific array logic
* D&C - Divide & Conquer

## First hint list

| # | Tags | Hints | Complexity |
|---| ---- | ----- | ---------- |
| 1 | Hash | Use hash map to store all values until current value. | O(n) |
| 2 | BF | Brute force. | O(n) |
| 3 | Array | Use a window. Extend if next element is not in the current window. | O(n) |
| 5 | DP | Build recurrence relation (may help to solve longest common substring problem) | O(n^2) |
| 7 | BF | Brute force. | O(log(n)) |
| 9 | BF | Brute force. | O(log(n)) |
| 10 | DP | Use a 2D matrix. DP[i][j] = whether p[0:i] matches with str[0:j]. | O(mn) |
| 15 | Array | Solve 2 sum before attempting this problem. | O(n^2) |
| 16 | Array | Similar to 3 sum, but use a sorted array and make front++, back-- updates to minimize abs(target - sum). | O(n^2) |
| 17 | Recursion | Possible approaches are trie, or more easy - building on smaller solution. | O(4^n)|
| 22 | Recursion | If less than n open brackets are open, we can add open bracket. But to add a close bracket you need count(')') < count('(') | . |
| 23 | Heap | Use a data structure which can give you minimum element at low cost.| . |
| 26 | Array | Maintain length of unique elements till current element.| O(n)|
| 27 | Array | vector.erase() will not work, as vector overwrites the element every time erase is called.| O(n)|
| 28 | BF | Brute force. | O(mn) |
| 31 | Array, Sorting | Find the location closest from the end which has segment ab of the form a < b, and make it ba. | O(n log(n))|
| 33 | Binary Search | Array increasing, sudden drop and then increasing again. Find out where the middle element is, can it's location help you? | O(log(n))|
| 36 | BF | Brute force.| O(1)|
| 42 | Stack + Array | Find next greater element index for each index, and prefix sum for each element. Can you build the solution from this? Check out problem 496 for next greater element. | O(n) |
| 43 | BF | Normal multiplication, like in school. | O(n log(d)) |
| 44 | DP | Solve problem 10 first. Construct a 2D box of size len(pattern)*len(string). DP[i][j] = whether p[0:i] matches with str[0:j] | O(mn) |
| 46 | Recursion | Combine str[0] with permutations of str[1:], use recursion. | O(n!) |
| 47 | Recursion | Eg, aaaabbcc, only one of each kind {a, b, c} can come at 0th index. Recurse. | O(n!) |
| 48 | Array | index <i, j> is i positions from left, j positions from top. Find a mapping to 3 other locations, and swap the values. | O(n^2) |
| 49 | Hash | Hashing | O(n) if O(1) hash |
| 50 | D&C/Recursion | 2^n = 2^(n/2)*2^(n/2) | O(log(n)) |
| 51 | Backtracking + Pruning | If a queen is in <i, j>, block that diagonal, row & column.  | O(n!) |
| 52 | Backtracking | Solution for 51 is more exhaustive than this problem. | O(n!) |
| 53 | Array | Keep extending window <i, j> to the right until sum > 0, if sum < 0, set i = j+1 | O(n) |
| 54 | Array/BF | Brute Force | O(n^2)|
| 56 | Sorting | Sort based on start time. | O(n log(n)) |
| 57 | Sorting | Insert interval and do problem 56. | O(n log(n)) |
| 66 | BF | Brute force | O(n) |
| 67 | BF | Simple array addition | O(log(n)) |
| 68 | Array | If you can fit in k words in a line, there must by atleast k-1 spaces, so L-(k-1)-sum(char's in words) must be divided mentioned in the question. | O(n) |
| 69 | Binary Search | start = 0, end = x/2, binary search | O(log(n)) |
| 70 | DP | DP[i] = DP[i-1] + DP[i-2] | O(n)|
| 71 | BF | Split by '/', use stack to handle '..' | O(n) |
| 75 | 2 pointer | Start & end indices. See if you can swap em into place. | O(n) |
| 76 | Array | Extend and contract window. | O(n) |
| 77 | Backtrack | Backtracking | O(nCk) |
| 78 | Backtrack | Backtracking Or generate all numbers between 0 & 2^n and use bit properties. | O(2^n) |
| 79 | DFS | DFS if letter match | O(nm * len(str)) |
| 80 | BF | Implementation based, maintain count. |  O(n) |
| 81 | Binary Search |  Similar to Problem 33. | O(log(n)) |
| 88 | Array | Merging logic from merge sort | O(n+m) |
| 90 | Array | Build the powerset starting from []. [[], [1]] + [2] -> [[], [1], [2], [1, 2]] + [2] = [[], [1], [2], [1, 2], [2, 2], [1, 2, 2]} | O(2^n) |
| 91 | DP | DP[i] = number of ways to decode until position i, relate it with DP[i-1] & DP[i-1] | O(n) |
| 98 | Tree Traversal | Both subtrees must be BST and max(left subtree) < min(right subtree) | O(n) |
| 101 | Tree Traversal | Assume you're at root, ll - left subtree of left subtree, and so on; Condition is ll = rr & lr = rl & l->val = r->val. | O(n) |
| 102 | BFS | Straighforward BFS | O(n) |
| 103 | BFS | BFS + stack at alternate levels. | O(n) |
| 104 | Tree Traversal | f(i) = 1 + max(f(i->left), f(i->right)) | O(n) |
| 105 | ||
| 106 | ||
| 107 | Tree Traversal | Problem 102 + reverse the result. | O(n) |
| 108 | Array | Middle element becoems root. | O(n) |
| 116 | BFS | BFS will give the ordering.  | O(n) |
| 117 | BFS | Same hint as 116. | O(n) |
| 118 | BF | Generate new row from old row. | O(n^2) |
| 119 | BF | Generate new row from old row. | O(n^2) |
| 128 | DP | DP problem, find recurrence relation. | O(n) |
| 133 | DFS/BF | Copy the original graph in a DFS like manner. | O(E+V) |
| 137 | Bit manipulation/Array | Consider 1 bit version, only 0's and 1's are allowed. If all numbers except one come 3 times, then there will be either 3k 1's, or 3k 0's followed by the bit of the actual number. So, whenever 1 comes 3 times make it 0. In the end, only the bit in the required number will be existing. Extend this logic to 32 bits. | O(n) |
| 139 | DP | DP[i] = whether sentence S[1:i] has a valid word break. DP[i] is true if some DP[j] is true and S[j:i] is a word. | O(n^2) |
| 140 | DP | Same as 139, keep track of all possible solutions at each i. | O(n^2) |
| 146 | Hashing/Array | Mostly brute force; keep track of which element needs to get evicted next, elements are stored in a hash. | O(1) per operation |
| 149 | Array | For each point X, check slope with every other point. If 5 points have same slope S then they all fall on the same line where X defines the intercept for slope S. | O(n^2) |
| 150 | Stack | Use stack to store operands and whenever operator is seen, evaluate. Use stoi() to convert string to number. | O(n) |
| 152 | Array | Maintain max and min values while iterating through the array. If A[i] is -ve, then swap max and min, as min is now a candidate to become max (after multiplying). While multiplying with A[i], only multiply if it can increase max or decrease min. If it cannot, then that subarray ends there and must start with A[i]. | O(n) |
| 161 | BF | When there is mismatch, check if A[i+1:] == B[j:], A[i+1:] == B[j+1:], A[i:] == B[j+1:]. | O(n) |
| 168 | BF | If n <= 26, then this is easy. Otherwise it is F(n) = F(n/26)+ (char)n%26; something like this. Calculate the exact relation. | O(log(n)) |
| 169 | Array | Assume A[0] is the majority element i.e. curmax = 0, whenever A[i] != A[curmax], reduce the count, if the count becomes -ve at any point, set curmax = i. Idea is that we are cancelling all non-equal elements, if some element occurs more than half times, then in the end curmax should point to that element. | O(n) |
| 172 | Math | [n/5] + [n/25] + [n/125] and so on .. where [] is floor operator. | O(log(n))|
| 173 | Stack | For every element, go right and then left repeatedly to get the next smallest element, can storing it in a stack help? | O(n) |
| 187 | Hash | Store all 10 letter substrings in a hashtable. | O(n) |
| 190 | BF | Remember to store answer in unsigned long. Construct answer from bits. | O(log(n)) |
| 191 | BF | Straighforward. | O(log(n)) |
| 198 | DP | DP[i] = max(DP[i-2]+nums[i], DP[i-1]). | O(n) |
| 200 | DFS | Do DFS whenever you encounter a 1; #islands = # of times the DFS routine is called from main(). | O(n*m) |
| 202 | Set | Use a set to keep track of all visited numbers. | Don't know. |
| 205 | Hash | Make sure you have a 1-1 mapping. | O(n) |
| 206 | BF | Use variables prevNode, curNode, nextNode. You need to do it this step by step, decide in how to and in what order to set the said variables. | O(n) |
| 207 | DFS | You're looking for a loop. So set the nodes whom you're visiting in the current loop as gray, and if you end up visiting a gray node then there is a loop. | O(V+E) |
| 208 | Tree | Multiway tree. | O(n) for both search and insert, n = # letters |
| 209 | Array | Expanding and shrinking window approach. | O(n) |
| 210 | Topological Sorting | Make sure to check for cycles. | O(V+E) |
| 212 | Trie+DFS | Problem is that you never know when a word ends. If no word starts with prefix "ab" and your path in DFS is currently "ab" you can break the current DFS chain. See if a trie can help with this kind of pruning. | O(n^2*m^2) in the absolute worst case, all words use all the letters in the matrix. |
| 214 | BF/KMP | KMP is faster. But BF works by asking .. what is the largest prefix of the string that is also a palindrome, and thus how many characters are needed to make it into a palindrome. | O(n) |
| 215 | QuickSort | Don't complete the sort. Partition, and if there are more than k characters in the first half, search for kth largest in the first half, else search for it in the second half (subtract number of elements in the first half). | O(log(n)) on average |
| 413 | Array | [1, 2, 3, 4, 5, 7, 9, 11]. can be written as [5, 3] i.e. 5 sequence of difference 1 and 3 sequence of difference 2, you need to figure out how many parts you can split 5 and 3 into. | O(n) |
| 694 | DFS | Keep track of the directions in which DFS proceeds in some form, maybe a string like ddr for down down right. | O(rows*cols) |
| 738 | Array | Find the first time Xi > Xi+1, Xi -= 1 and turn all Xi+k = 9, For eg, 321 becomes 299. Figure out cases like 33332. | O(n) |

## Second hint list

| # | Hints | Complexity |
|---| ----- | ---------- |
| 5 | Use DP, P<i, j> = P<i+1, j-1> && S[i] == S[j] is the recurrence relation.| O(n^2) |
| 10 | Manually solve [aab, c*a*b], [ab, .b], [aaa, ab*a] for corner cases. | O(mn) |
| 15 | 2sum for a sorted list gives a more optimal sub routine here. | O(n^2)|
| 17 | Build solution for first k numbers, and modify solution vector for k+1 number. |  O(4^n)|
| 22 | Backtracking based solution. | |
| 23 | Use heap (this method uses extra memory). | |
| 27 | Count the number of occurences in a variable - acting as offset. | |
| 31 | Sort from b onwards. Solution is done. | |
| 33 | Depending upon the location of the middle element and whether target is lower or greater than middle element, write 4 cases. | |
| 42 | Let nge(i) = k and p be prefix sum array, we can roughly say water trapped = Sigma[ (h_i x (k-i)) - (p[k]-p[i])] | |
| 44 | Write cases for when p[i] = '*' and not '*'. | O(mn) |
| 108 | Left node must be filled before right node.| |
| 128 | If L[k] represents the largest consecutive sequence, L[k] -> L[k-L[k]]+ L[k] | |
