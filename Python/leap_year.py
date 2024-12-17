def leap_year(num):
    
    if(num%4 == 0 and num%100 != 0) or (num%400 == 0):
        return True
    return False

print(leap_year(2024))
print(leap_year(2014))