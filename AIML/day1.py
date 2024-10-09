li=[19,20,21,34,44]
li1=li[::-1]
li.reverse()
print(li)
print(li1)
list=["m","na","i","bhu"]
list1=["y","me","s","vesh"]
list2=[]
list3=[i+j for i,j in zip(list,list1)]
list4=[list[i]+list1[i] for i in range(len(list))]
for i in range(len(list)):
    list2.append(list[i]+list1[i])
print(list2)
print(list3)
print(list4)