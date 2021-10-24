class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.key = key


class BST:
    def __init__(self):
        self.root = None

    def insert1(self, key):
        self.root = self.insert2(self.root, key)

    def insert2(self, root, key):
        if root is None:
            return Node(key)
        if root.key > key:
            root.left = self.insert2(root.left, key)
        elif root.key < key:
            root.right = self.insert2(root.right, key)
        return root

    def delete(self, key):
        self.root = self.delete2(self.root, key)

    def delete2(self, root, key):
        if root is None:
            return None
        if root.key > key:
            root.left = self.delete2(root.left, key)
        elif root.key < key:
            root.right = self.delete2(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            else:
                temp = self.getS(root)
                root.key = temp.key
                root.right = self.delete2(root.right, temp.key)
        return root

    def getS(self, root):
        temp = root.right
        while (temp is not None) and (temp.left is not None):
            temp = temp.left
        return temp

    def printBST(self,root):
        if root is not None:
            self.printBST(root.left)
            print(root.key,end=" ")
            self.printBST(root.right)
        


myBST = BST()
myBST.insert1(10)
myBST.insert1(15)
myBST.insert1(12)
myBST.insert1(5)
myBST.insert1(18)
myBST.insert1(20)
myBST.printBST(myBST.root) 
myBST.delete(18)                #deletion
myBST.insert1(13)               #insertion
print()
myBST.printBST(myBST.root)
