class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info): 
          self.info = info  
          self.left = None  
          self.right = None 
           

       // this is a node of the tree , which contains info as data, left , right
'''

from collections import deque

def lca(root, v1, v2):
    if root is None: 
        return None
    
    # Find path from root to target node
    def findPathToTarget(root, target_int):
        dq = deque([(root, [])])
        while dq:
            node, path = dq.popleft()
            new_path = path + [node]  # Create a new path list
            if node.info == target_int:
                return new_path
            if node.left:
                dq.append((node.left, new_path))
            if node.right:
                dq.append((node.right, new_path))
        return []

    # Get paths to v1 and v2
    path_to_v1 = findPathToTarget(root, v1)
    path_to_v2 = findPathToTarget(root, v2)

    # Compare paths to find LCA
    lca = None
    for a, b in zip(path_to_v1, path_to_v2):
        if a == b:
            lca = a
        else:
            break
    return lca

tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

v = list(map(int, input().split()))

ans = lca(tree.root, v[0], v[1])
print (ans.info)
