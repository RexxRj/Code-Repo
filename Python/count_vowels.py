def count_vowels(str):
    cnt = 0
    vowels = ['a','e','i','o','u']
    for char in str:
        if char.lower() in vowels:
            cnt+=1
    return cnt

a = "I am a dog of undetermined strength"
b = "Hello, World!"

print(count_vowels(a))
print(count_vowels(b))