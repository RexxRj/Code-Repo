def dec_to_bin(num):
    
    res = ""
    while(num):
        res+= str(num%2)
        num = int(num/2)
    
    return res[::-1]

print(dec_to_bin(10))
print(dec_to_bin(3))
print(dec_to_bin(2))
print(dec_to_bin(5))