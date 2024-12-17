import math

def lcm(a, b):
    gcd = 1
    
    for i in range(2,min(a,b)+1):
        if a%i == 0 and b%i == 0:
            gcd = i
    print(gcd)
    return abs(a*b)/gcd

# Example usage
num1 = 12
num2 = 18
print(lcm(num1,num2))
print(math.lcm(num1,num2))