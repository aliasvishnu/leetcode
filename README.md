# Leetcode

Hints for ~250 leetcode problems. Mostly medium, some hard.
Good practice list for internships/job hunt.

Solutions <a href = "https://github.com/aliasvishnu/leetcode/tree/master/Solutions" > here </a>

## Abbreviations
* BF - Brute Force,
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
| 81 | Binary Search, similar to Problem 33. | O(log(n)) |
| 88 | Array | Merging logic from merge sort | O(n+m) |
| 108 | Inorder traversal | Where does the root element fall during an inorder (sorted) traversal? | |
| 128 | DP | DP problem, find recurrence relation. | |

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
