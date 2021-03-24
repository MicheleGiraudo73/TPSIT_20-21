def push_(stack,element):
    stack.append(element)

def pop_(stack):
    return stack.pop()

def dequeu(queue):
    return queue.pop(0)


def enqueue(queue, element):
    queue.append(element)

def main():
    coda = []
    stack = []
    while True:
        element = int(input("inserire un valore: "))
        enqueue(coda,element)
        risp = input("inserisci s per continuare e n per terminare: ")
        if risp == 'n' or risp == 'N':
            break

    for _ in range(len(coda)):
        push_(stack,dequeu(coda))

    for _ in range(len(stack)):
        enqueue(coda,pop_(stack))
        
    for _ in range(len(coda)):
        print(dequeu(coda))    

if __name__=="__main__":
    main()