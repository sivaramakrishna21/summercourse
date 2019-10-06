def check(a,b):
    new_arr={}
    for i in a:
        k=0
        if 0 not in new_arr.keys():
            new_arr[0]=i
        else:
            while(1):
                if(new_arr[k]>i):
                    k=k*2+1
                    if k not in new_arr.keys():
                        new_arr[k]=i
                        break
                
                else:
                    k=k*2+2
                    if k not in new_arr.keys():
                        new_arr[k]=i
                        break
    arr2={}
    for i in b:
        k=0
        if 0 not in arr2.keys():
            arr2[0]=i
        else:
            while(1):
                if(arr2[k]>i):
                    k=k*2+1
                    if k not in arr2.keys():
                        arr2[k]=i
                        break
                
                else:
                    k=k*2+2
                    if k not in arr2.keys():
                        arr2[k]=i
                        break
    
    print(arr2,new_arr)
    return new_arr==arr2



a=[8, 10, 14, 3, 6, 4, 1, 7, 13]
b=[8, 3, 6, 1, 4, 7, 10, 14, 13]
print(check(a,b))