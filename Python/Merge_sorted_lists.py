def merge(ls1,ls2):
    
    i = 0
    j = 0
    ans = []
    while(i<len(ls1) and j<len(ls2)):
        
        if(ls1[i]<ls2[j]):
            ans.append(ls1[i])
            i+=1
        else:
            ans.append(ls2[j])
            j+=1
    
    while(i<len(ls1)):
        ans.append(ls1[i])
        i+=1
        
    while(j<len(ls2)):
        ans.append(ls2[j])
        j+=1
    
    return ans

list1 = [1, 3, 5, 7, 9]
list2 = [2, 4, 6, 8, 10]

print(merge(list1,list2))