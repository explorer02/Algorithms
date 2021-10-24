class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.key = key


class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self.insert2(self.root, key)

    def insert2(self, root, key):
        if root is None:
            return Node(key)
        if root.key > key:
            root.left = self.insert2(root.left, key)
        elif root.key < key:
            root.right = self.insert2(root.right, key)
        return root

    def inOrder(self,ptr):
        if ptr is None:
            return None
        # print(ptr.key,end=" ")
        self.inOrder(ptr.left)
        print(ptr.key,end=" ")
        self.inOrder(ptr.right)
        


myBST = BST()
myBST.insert(10)            #insertion
myBST.insert(15)
myBST.insert(12)
myBST.insert(5)
myBST.insert(18)
myBST.insert(20)
myBST.inOrder(Node(10))