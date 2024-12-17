
def unique_string(s):
    
    st = set()
    res = ""
    
    for char in s:
        if char not in st:
            res+=char
            st.add(char)
    
    return res

s = "Hello World!"
print(unique_string(s))