def computeHash(string):
    # Assuming that the input may contain both uppercase and lowercase letters
    prime: int = 53

    prime_pow = 1
    hashValue: int = 0
    m: int = 1000000000 + 9

    for ch in string:
        hashValue += ((ord(ch) + 1) * prime_pow) % m
        prime_pow = (prime_pow * prime) % m

    print(hashValue)
