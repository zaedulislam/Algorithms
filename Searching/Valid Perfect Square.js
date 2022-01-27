/**
 * Problem Link: https://leetcode.com/problems/valid-perfect-square/
 * Checks if any given number is a perfect square or not in O(logn) complexity
 */

/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    let first = 0.0, last = num;
    for(let step = 1; step <= 64; step++){
        let mid = (first + last) / 2;
        
        let square = Math.floor(mid) * Math.floor(mid);
        
        if(square === num){
            return true;
        } else if(square > num){
            last = mid;
        } else {
            first = mid;
        }
    }
    
    return false;
};