def push_(stack,element):
    stack.append(element)

def pop_(stack):
    return stack.pop()

def main():
    pila = ["a","b","c","d"]
    push_(pila,"z")
    print(pila)
    x = pop_(pila)
    print(x)

if __name__ == "__main__":
    main()
