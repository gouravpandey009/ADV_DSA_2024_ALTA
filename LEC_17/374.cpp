class Solution {
public:
    int guessNumber(int n) {

        int left = 1;
        int right = n;

        while(left <= right){
             //guess middle number

        int  mid = left + (right - left) /2;

        //correct answer found

        if(guess(mid) == 0)
        return mid;

        //guess too small

        if(guess(mid) == 1)
        left = mid + 1;

        else 
             right = mid - 1;
        
    }
    return -1;
    
     }

       
};