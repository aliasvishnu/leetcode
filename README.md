# Leetcode

This is a log of all the problems that I have solved in Leetcode along with the hints. Please forgive the low hint quality, if you'd like you are welcome to contribute to the hints as well. </br>

</br><b>First hint list </b>
</br> ===================
|5 | Build recurrence relation (may help to solve longest common substring problem) | 
</br> 15 - Solve 2 sum before attempting this problem.
</br> 17 - Possible approaches are trie, or more easy - building on smaller solution.
</br> 22 - If less than n open brackets are open, we can add open bracket. But to add a close bracket you need #close < #open.
</br> 23 - Use a data structure which can give you minimum element at low cost.
</br> 27 - vector.erase() will not work, as vector overwrites the element everytime erase is called.
</br> 31 - There is no scope to increasing the given number from the point where list is decreasing continuously.
</br> 108 - Where does the root element fall during an inorder (sorted) traversal?
</br> 128 - DP problem, find recurrence relation.

</br><b>Second hint list</b>
</br> =================
</br> 5 - Use DP, P<i, j> = P<i+1, j-1> && S[i] == S[j] is the recurrence relation.
</br> 15 - 2sum for a sorted list gives a more optimal sub routine here.
</br> 17 - Build solution for first k numbers, and modify solution vector for k+1 number.
</br> 22 - Backtracking based solution.
</br> 23 - Use heap (this method uses extra memory)
</br> 27 - What if you count the number of occurences in a variable - acting as offset.
</br> 31 - Find the point where next element is larger than current element, think what to do from here.
</br> 108 - Left node must be filled before right node.
</br> 128 - If L[k] represents the largest consecutive sequence, L[k] -> L[k-L[k]]+ L[k]
