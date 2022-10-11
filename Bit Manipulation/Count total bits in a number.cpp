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
  *   The log2(n) logarithm in base 2 of n, which is the exponent to which 2 is raised to get n only integer,
  *   and we add 1 find total bit in a number in log(n) time. 
 */


int countBitsUsingLog(int number){
    // log function in base 2 take only integer part
    return (int)log2(number) + 1;
}


// Method 2 (Using Bit Traversal)
int countBitsUsingBitTraversal(int number){
    int numberOfBits = 0;

    while(number){
        numberOfBits++;
        number >>= 1;
    }

    return numberOfBits;
}


// Method 3 ( Using conversion from binary to string)
int countBitsUsingConversionFromBinaryToString(int number){
    string binary = bitset<64>(number).to_string();

    return 64 - binary.find('1');
}


int main() {
    int n;
    cin >> n;

    cout << "Method 1 (Using Log): " << countBitsUsingLog(n) << endl;
    cout << "Method 2 (Using Bit Traversal): " << countBitsUsingBitTraversal(n) << endl;
    cout << "Method 3 ( Using conversion from binary to string): " << countBitsUsingConversionFromBinaryToString(n) << endl;

    return 0;
}
