# AVL Tree implementation - Insertion, traversals, searching, deletion
# Author - rudrajit1729 

# Utility Class that represents node of a AVL tree
class Node(object):
    def __init__(self, key):
        self.value = key
        self.left = None
        self.right = None
        self.height = 1

# AVL tree Class

class AVL_Tree(object):
    # Utility function to insert node
    def insert(self, root, key):
        # Step 1 - Perform normal BST insert
        if root is None:
            return Node(key)
        elif key < root.value:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        
        # Step 2 - Update height of ancestors
        root.height = 1 + max(self.getHeight(root.left),
                             self.getHeight(root.right))
        # Step 3 - Get Balance Factor
        balance = self.getBalance(root)

        # Step 4 - If node is unbalanced, then perform 4 cases
        # Case 1 - Left Left
        if balance > 1 and key < root.left.value:
            return self.rightRotate(root)
        
        # Case 2 - Right Right
        if balance < -1 and key > root.right.value:
            return self.leftRotate(root)
        
        # Case 3 - Left Right
        if balance > 1 and key > root.left.value:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        
        # Case 4 - Right Left
        if balance < -1 and key < root.right.value:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        
        return root
    
    def delete(self, root, key):
        # Step 1 - Perform Standard BST delete

        # Base Case
        if root is None:
            return root
        # If key smaller than root value delete from left subtree
        if key < root.value:
            root.left = self.delete(root.left, key)
        # Else If key greater than root value delete from right subtree
        elif key > root.value:
            root.right = self.delete(root.right, key)
        # Else we found the node we are looking for
        else: 
            # If node has one or no children
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            
            # Else it has two children
            else:
                # Find inorder successor of the node
                temp = self.minValNode(root.right)
                # Replace root value with successor value
                root.value = temp.value
                # Delete successor from right subtree
                root.right = self.delete(root.right, temp.value)
            
        # If tree has only one node simply return it
        if root is None:
            return root

        # Step 2 - Update height of the ancestors
        
        root.height = 1 + max(self.getHeight(root.left),
                                self.getHeight(root.right))
        
        # Step 3 - Get the Balance Factor

        balance = self.getBalance(root)

        # Step 4 - If node is unbalanced, then perform 4 cases
        
        # Case 1 - Left Left
        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)
        
        # Case 2 - Right Right
        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)
        
        # Case 3 - Left Right
        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        
        # Case 4 - Right Left
        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root
    
    # Utility functions for rotations
    def leftRotate(self, root):
        new_root = root.right
        lsubTree = new_root.left

        # Perform rotation
        new_root.left = root
        root.right = lsubTree

        # Update Heights
        root.height = 1 + max(self.getHeight(root.left), 
                              self.getHeight(root.right))
        new_root.height = 1 + max(self.getHeight(new_root.left),
                                  self.getHeight(new_root.right)) 
        
        # Return the new root
        return new_root

    def rightRotate(self, root):
        new_root = root.left
        rsubTree = new_root.right

        # Perform rotation
        new_root.right = root
        root.left = rsubTree

        # Update Heights
        root.height = 1 + max(self.getHeight(root.left), 
                              self.getHeight(root.right))
        new_root.height = 1 + max(self.getHeight(new_root.left),
                                  self.getHeight(new_root.right)) 
        
        # Return the new root
        return new_root
    
    # Utility functions 
    def getHeight(self, root):
        if root is None:
            return 0
        return root.height
    
    def getBalance(self, root):
        if root is None:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)
    
    def minValNode(self, root):
        curr = root
        while curr.left:
            curr = curr.left
        return curr

    # Utility functions for traversals
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.value, end = " ")
            self.inorder(root.right)

    def preorder(self, root):
        if root:
            print(root.value, end = " ")
            self.preorder(root.left)
            self.preorder(root.right)

    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.value, end = " ")
    
    # Searching for a node
    def findNode(self, root, key):
        # Base Case
        if root is None:
            return False
        # If root value greater than key then search in left subtree only
        if root.value > key:
            return self.findNode(root.left, key)
        # Else If root value lesser than key then search in right subtree only
        elif root.value < key:
            return self.findNode(root.right, key)
        # Else key found
        else:
            return True
        
# Demonstration
def main():
    r'''
    AVL tree:
                30
             /      \
            20       40
          /    \    /  \
        10     25  38   50
    '''

    tree = AVL_Tree()
    root = None

    # Insertion
    root = tree.insert(root, 10)
    root = tree.insert(root, 20) 
    root = tree.insert(root, 30) 
    root = tree.insert(root, 40) 
    root = tree.insert(root, 50) 
    root = tree.insert(root, 25) 
    root = tree.insert(root, 38)

    # Traversal
    def printTree():
        print("Inorder traversal :")
        tree.inorder(root) # AVL sort - O(nlogn)
        print()
    printTree()

    # Deletion
    root = tree.delete(root, 10) # No children
    printTree()
    root = tree.delete(root, 20) # 1 child
    printTree()
    root = tree.delete(root, 40) # 2 children
    printTree()

    # Searching
    print("Finding 30 : ", tree.findNode(root, 30))
    print("Finding 40 : ", tree.findNode(root, 40))
        
if __name__ == "__main__":
    main() 
