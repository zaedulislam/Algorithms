// Implementation of Rabin-Karp Algorithm.cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
typedef unsigned long long llu;

using namespace std;
const int _size = 1e6 + 5;
char text[_size];
char pattern[1000];
int Base = 256; // fixed the base for 52 distinct character, can be increased; the base of the numeral system
int Prime = 999983; // A big enough prime number

// Correctly calculates Base mod Modulus even if Base < 0
inline int mod(int Base, int Modulus)
{
	return (Base % Modulus + Modulus) % Modulus;
}

void RABIN_KARP_MATCHER(int len_txt, int len_pattern)
{
	if (len_txt < len_pattern) {
		printf("No Match Possible\n");
		return;
	}
	// Loop variables
	int I, P, Index;

	int hash_pattern = 0;      // hash value for text.
	// Calculate the hash value of the pattern
	for (I = 0; I < len_pattern; I++)
		hash_pattern = mod(hash_pattern * Base + pattern[I], Prime);
	
	int hash_txt = 0;              // hash value for pattern.
	// Calculate the hash value of the first segment of the text of length (len_str)
	for (I = 0; I < len_pattern; I++)
		hash_txt = mod(hash_txt * Base + text[I], Prime);

	// Check character by character if the first segment of the text matches the pattern
	if (hash_txt == hash_pattern) {
		for (I = 0; I < len_pattern; I++)
			if (text[I] != pattern[I])    // Mismatch any of the character
			break;                               // Break the inner loop
		if (I == len_pattern)
			printf("Match Found at Index %d.\n", 0);
	}

	// Start the "Rolling Hash" - for every next character in
	// the text & Calculate the hash value of the new segment
	// of length m; E = (Bm-1) modulo M 

	int E = 1;
	// E is Base^(len_pattern-1)
	for (I = 0; I < len_pattern - 1; I++)
		E = (E * Base) % Prime;

	Index = 1;
	for (I = len_pattern; I < len_txt; I++) {

		hash_txt = mod(hash_txt - mod(text[I - len_pattern] * E, Prime), Prime);

		hash_txt = mod(hash_txt * Base, Prime);

		hash_txt = mod(hash_txt + text[I], Prime);

		// Check character by character if the first segment of the text matches the pattern
		if (hash_txt == hash_pattern) {
			for (P = 0; P < len_pattern; P++) {
				if (text[Index + P] != pattern[P])      // Mismatch any of the character
					break;                                              // Break the inner loop
			}
			if (P == len_pattern)
				printf("Match Found at Index %d.\n", Index);
		}
		Index++;
	}
}

int main()
{
	printf("Enter Text: ");
	fgets(text, _size, stdin);
	int len_txt = strlen(text);
	if (text[len_txt - 1] != '\0')
		text[len_txt - 1] = '\0';
	len_txt--;

	printf("Enter Pattern to Search: ");
	fgets(pattern, 1000, stdin);
	int len_pattern = strlen(pattern);
	if (pattern[len_pattern - 1] != '\0')
		pattern[len_pattern - 1] = '\0';
	len_pattern--;

	RABIN_KARP_MATCHER(len_txt, len_pattern);

	return 0;
}
