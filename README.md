# Leetcode

This is a log of all the problems that I have solved in Leetcode. </br>

</br><b>First hint list </b>
</br> ===================
</br> 5 - Build recurrence relation (may help to solve longest common substring problem).
</br> 17 - Possible approaches are trie, or more easy - building on smaller solution.
</br> 23 - Use a data structure which can give you minimum element at low cost.
</br> 27 - vector.erase() will not work, as vector overwrites the element everytime erase is called.
</br> 31 - There is no scope to increasing from the point where list is decreasing continuously.

</br><b>Second hint list</b>
</br> =================
</br> 5 - Use DP, P<i, j> = P<i+1, j-1> && S[i] == S[j] is the recurrence relation.
</br> 17 - Build solution for first k numbers, and modify solution vector for k+1 number.
</br> 23 - Use heap (this method uses extra memory)
</br> 27 - What if you count the number of occurences in a variable - acting as offset.
</br> 31 - Find the point where next element is larger than current element, think what to do from here.
