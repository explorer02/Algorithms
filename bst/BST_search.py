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

    def search(self, root, key):
        if root is None:
            return False
        if root.key is key:
            return True
        if root.key > key:
            return self.search(root.left, key)
        return self.search(root.right, key)


myBST = BST()
myBST.insert(10)
myBST.insert(15)
myBST.insert(12)
myBST.insert(5)
myBST.insert(18)
myBST.insert(20)

if myBST.search(myBST.root, 7):
    print("Found in BST")
else:
    print("Not found in BST")

if myBST.search(myBST.root, 15):
    print("Found in BST")
else:
    print("Not found in BST")
