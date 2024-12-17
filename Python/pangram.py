def pangram(str):
    
    s = "abcdefghijklmnopqrstuvwxyz"
    
    str = str.replace(" ","").lower()
    
    for char in s:
        if char not in str:
            return False
    
    return True

word1 = "The quick brown fox jumps over the lazy dog"
word2 = "The quick brown fox jumps over the dog"

print(pangram(word1))
print(pangram(word2))