def fibonacci(n):
    
    ls = [0,1]
    if(n == 1): return ls[0]
    if(n == 2): return ls[1]
    
    n = n-2
    while(n):
        ls.append(ls[-1]+ls[-2])
        n-=1
    
    return ls
print(fibonacci(1))
print(fibonacci(2))
print(fibonacci(3))
print(fibonacci(10))
        