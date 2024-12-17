def perfect(num):
    sum = 0
    
    for i in range(1,num):
        if(num%i == 0): 
            sum+= i
            
    return sum == num

print(perfect(6))
print(perfect(60))