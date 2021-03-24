def push(stack,element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def load(stack,string):
    for char in string:
        if char == "(" or char == ")" or char == "[" or char == "]" or char == "{" or char == "}":
            push(stack,char)

def checkBrackets(stack): 
    dim=int(len(stack))
    if dim%2==0:
        ok=0
        for element in stack[:int(dim/2)]:
            popped=pop(stack)
            if element==chr(ord(popped)-2) or element==chr(ord(popped)-1):
                ok+=1
        if ok==int(dim/2):
            return True
        else:
            return False
    else:
        return False

def main():
    string = input()
    stack=[]
    load(stack,string)
    if checkBrackets(stack): 
        print("Le parentesi sono giuste")
    else:
        print("Le parentesi non sono giuste")

if __name__ == "__main__":
    main()