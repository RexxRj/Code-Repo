def anagram(str1,str2):
    
    if len(str1) != len(str2): return False
    
    return sorted(str1) == sorted(str2)

a = "listen"
b = "silent"
c = "silant"

print(anagram(a,b))
print(anagram(a,c))