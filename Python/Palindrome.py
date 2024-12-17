a = "I am ma I"
b = "I am not ton maI"

def palindrome(a):
    a = str(a)
    a = a.replace(" ","").lower()
    b = a[::-1]
    return b == a

# print(palindrome(a))
# print(palindrome(b))

c = 123
d = 12521

print(palindrome(c))
print(palindrome(d))