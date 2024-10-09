dad=[10,20,'abc','cu',80.1,['a',[300,[1000,[2000,'b','Uni'],900,7],'b',90]]]
def find_index(nested_list, target):
    for index, element in enumerate(nested_list):
        if element == target:
            return [index]
        elif isinstance(element, list):
            path = find_index(element, target)
            if path is not None:
                return [index] + path
    return None

index = find_index(dad, 2000)
print(index)