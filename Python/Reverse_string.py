# Reverse a string

a = "I am a dog"

rev_a = a[::-1]
# print(rev_a)

def reverse(a):
    ans = ""
    for char in a:
        ans = char + ans
    
    return ans

print(reverse(a))


