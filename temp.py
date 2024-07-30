def gcdOfStrings(str1: str, str2: str):
        check = len(str1)>len(str2)
        if(len(str1) == len(str2)):
            if(str1 == str2):
                return str1
            else:
                print(str1, str2)
                return ""
        if (len(str1) % len(str2) == 0) and (str2 * int(len(str1) / len(str2)) == str1):
            return str2
        temp1 = []
        for i in range(len(str2)):
            mul = str2[:i+1] * int( len(str1) / len(str2[:i+1]))
            if( mul == str1 and len(str2[:i+1]) != len(str1) ):
                temp1.append(str2[:i+1])
        temp2 = []
        for i in range(len(str1)):
            mul = str1[:i+1] * int( len(str2) / len(str1[:i+1]) )
            if(mul == str2 and len(str1[:i+1]) != len(str2)):
                temp2.append(str1[:i+1])
        array = list(set(temp1).intersection(temp2))
        print(max(array))
        if len(array) > 0:
            return array[-1]
        else: 
            return ""
x = gcdOfStrings("ABCABCABC", "ABCABCABC")
print(x)