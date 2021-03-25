class Node:
    def __init__(self,data):  #__init__ prende solo il data, il self solo nella definizione
        self.left = None
        self.right = None
        self.data = data 

    def insert(self,data):
    # conftonta il nodo da aggiungere con il nodo da aggiungere
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
             self.data = data
    #stampa albero
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
#inserimento
root = Node(12)
root.insert(6)
root.insert(14)
root.insert(3)

root.PrintTree()
