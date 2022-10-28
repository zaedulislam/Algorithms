/*
 * For all methods,
 * Time Complexity : O(logn)
 * Auxiliary Space : O(1)
 */


#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;


/**
  *  Method 1 (Using Log)
  *  The log2(n) logarithm in base 2 of n, which is the exponent to which 2 is raised to get n only integer,
  *  and we add 1 find total bit in a number in log(n) time.
 */


int countBitsUsingLog(int number){
    // log function in base 2 take only integer part
    return (int)log2(number) + 1;
}

int countSetBits(int number){
        int numberOfSetBits = 0, numberOfBits = countBitsUsingLog(number), bitmask = 1;

        while (numberOfBits){
            if ((number & bitmask) != 0) {
                numberOfSetBits++;
            }

            bitmask <<= 1;
            numberOfBits--;
        }

    return numberOfSetBits;
}


int main() {
    int n;
    cin >> n;

    cout << "Simple Method: " << countSetBits(n) << endl;

    return 0;
}




