import random

def insert(item, x):
    mylst = []
    for i in range(len(x) + 1):
        tmp = x[:i] + [item] + x[i:]
        print("tmp ", tmp)
        if tmp not in mylst:
            mylst.append(tmp)
    return mylst

def permutation(A):
    if not A:
        return []
    S = [[A[0]]]

    for i in range(1, len(A)):
        P = []
        for x in S:
            P.extend(insert(A[i], x))
        print(P)
        S = P
    return S

'''-------------MAIN FUNCTION-----------------'''

flag = False
while True:
    if not flag:
        user_choice = int(input("Choose an option:\n1. Input an Array\n2. Create Random Array\nEnter choice (1 or 2): "))
    if user_choice in [1, 2]:
        if user_choice==1:
            #Input from user
            if not flag:
                n = int(input("Number of elements in an array: "))
            A = list(map(int, input("Enter an array separated by space: ").split()))

            if len(A)>n:
                print(f"\nPlease enter no more than {n} element !!!\n")
                flag=True
            elif len(A)<n:
                print(f"\nPlease enter no less than {n} element !!!\n")
                flag=True
            else:
                flag=False
                results = permutation(A)
                print(f"There are a total of {len(results)} permutations, including: ")
                for item in results:
                    print(item)

                cont = int(input("\nDo you want to continue ?:\n1. Yes\n2. No\nEnter choice (1 or 2): "))
                if cont == 1:
                    print("\n")
                    continue
                elif cont==2:
                    print("\nENDING PROGRAM !!!")
                    break;
                
        else:
            #Random array
            A=[]
            n = int(input("Number of elements in an array: "))
            A = random.sample(range(0, 9), n)
            print(f"Here is the random array that is created from {n} elements: {A}")

            results = permutation(A)
            print(f"There are a total of {len(results)} permutations, including: ")
            for item in results:
                print(item)
    
            cont = int(input("\nDo you want to continue ?:\n1. Yes\n2. No\nEnter choice (1 or 2): "))
            if cont == 1:
                print("\n")
                continue
            else:
                print("ENDING PROGRAM !!!\n")
                break
    else:
        print("\nWrong input format, please type again !!!\n")
    
'''----------------------------------------------'''
