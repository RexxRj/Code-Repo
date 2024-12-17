def is_prime(num):
    
    if(num in [0,1]): return False
    
    for i in range(2,int(num**0.5)+1):
        if(num%i == 0): return False
    
    return True

def find_prime(start,end):
    ls = []
    for i in range(start,end+1):
        if(is_prime(i)):
            ls.append(i)
    
    return ls

print(find_prime(1,50))