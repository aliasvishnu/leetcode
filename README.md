# Leetcode

Hints + solutions for ~250 leetcode problems. Mostly medium, some hard. Currently adding more hints as I revisit my solutions. Please help me add more hints if you can.

I commit a lot, many a times unnecessarily in this repo, it could be better solution or some optimization, or alternate solution, or variable renaming. I apologize for that as well.

## First hint list


| # | Hints | Complexity |
|---| ----- | ---------- |
| 1 | Use hash map to store all values until current value. | O(n) |
| 2 | Brute force. | O(n) |
| 3 | Use a window. Extend if next element is not in the current window. | O(n) |
| 5 | Build recurrence relation (may help to solve longest common substring problem) | O(n^2) |
| 7 | Brute force. | O(log(n)) |
| 9 | Brute force. | O(log(n)) |
| 10 | Use a 2D matrix. DP[i][j] = whether p[0:i] matches with str[0:j]. | O(mn) |
| 15 | Solve 2 sum before attempting this problem. | O(n^2) |
| 16 | Similar to 3 sum, but use a sorted array and make front++, back-- updates to minimize abs(target - sum). | O(n^2) |
| 17 | Possible approaches are trie, or more easy - building on smaller solution. | O(4^n)|
| 22 | If less than n open brackets are open, we can add open bracket. But to add a close bracket you need count(')') < count('(') | . |
| 23 | Use a data structure which can give you minimum element at low cost.| . |
| 26 | Maintain length of unique elements till current element.| O(n)|
| 27 | vector.erase() will not work, as vector overwrites the element every time erase is called.| O(n)|
| 28 | Brute force. | O(mn) |
| 31 | Find the location closest from the end which has segment ab of the form a < b, and make it ba. | O(n log(n))|
| 33 | Array increasing, sudden drop and then increasing again. Find out where the middle element is, can it's location help you? | O(log(n))|
| 36 | Brute force.| O(1)|
| 42 | Find next greater element index for each index, and prefix sum for each element. Can you build the solution from this? Check out problem 496 for next greater element. | |
| 43 | Normal multiplication, like in school. | O(n log(d)) |
| 44 | Solve problem 10 first. Construct a 2D box of size len(pattern)*len(string). DP[i][j] = whether p[0:i] matches with str[0:j] | O(mn) |
| 46 | Combine str[0] with permutations of str[1:], use recursion. | O(n!) |
| 47 |
| 108 | Where does the root element fall during an inorder (sorted) traversal? | |
| 128 | DP problem, find recurrence relation. | |

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
