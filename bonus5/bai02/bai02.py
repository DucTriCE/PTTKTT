import random

def insert(item, x):
    return x + [item]

def gen_subset(A):
    S = [[]]
    if not A:
        return S

    for i in range(0, len(A)):
        P = []
        for x in S:
            P.append(insert(A[i], x))
        S.extend(P)
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
                results = gen_subset(A)
                print(f"There are a total of {len(results)} subsets, including: ")
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

            results = gen_subset(A)
            print(f"There are a total of {len(results)} subsets, including: ")
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
