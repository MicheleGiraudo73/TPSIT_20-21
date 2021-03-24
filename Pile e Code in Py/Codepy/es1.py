
def dequeu(queue):
    return queue.pop(0)


def enqueue(queue, element):
    queue.append(element)

def main():
    coda = []
    while True:
        element = int(input("inserire un valore: "))
        enqueue(coda,element)
        risp = input("inserisci s per continuare e n per terminare: ")
        if risp == 'n' or risp == 'N':
            break
    for _ in range(len(coda)):
        print(dequeu(coda))

if __name__=="__main__":
    main()