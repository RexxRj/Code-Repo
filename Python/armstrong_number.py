def armstrong(number):
    num = number
    powsum = 0
    n = len(str(num))
    while(num):
        
        powsum+= (num%10)**n
        num = int(num/10)
        
    return powsum == number

print(armstrong(153))
print(armstrong(4546))
