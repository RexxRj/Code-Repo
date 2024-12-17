def sum_of_digits(num):
    
    sum = 0
    
    while(num):
        sum+= num%10
        num = int(num/10)
    return sum

print(sum_of_digits(123456789))
print(sum_of_digits(12345))