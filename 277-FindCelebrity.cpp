// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 1) return 0;


        int candidate = 0;

        // Assume 0 as candidate, 0 must definitely not know the other, if I find that candidate knows i, make i the candidate.
        // finally candidate wouldn't know any number after it.

        // Go through another loop to make sure our candidate is right.

        for(int i = 1; i < n; i++){
            if(knows(candidate, i)) candidate = i;
        }


        for(int i = 0; i < n; i++){
            if(i == candidate) continue;
            if(knows(candidate, i)) return -1;
            if(!knows(i, candidate)) return -1;
        }



        return candidate;
    }
};
