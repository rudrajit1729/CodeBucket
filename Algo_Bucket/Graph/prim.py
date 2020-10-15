class Graph():
 
    def __init__(self, vert):
        self.V = vert
        #variable to store number of vertices
        self.graph = [[0 for column in range(vert)] for row in range(vert)]
        #variable to store graph
        
    def printTree(self, parent):
        print ("Edge \tWeight")
        for i in range(1, self.V):
            print (parent[i], "-", i, "\t", self.graph[i][ parent[i] ])
        #displaying the minimum cost spanning tree
 
    def minKey(self, key, mstSet):
        min = 999999 #initializing min variable
        for v in range(self.V):
            if key[v] < min and mstSet[v] == False:
                min = key[v]
                min_index = v
                #finding and storing minimum weight
        return min_index
        #returning minimum weight
 
    def primMST(self):
        key = [999999] * self.V
        parent = [None] * self.V 
        key[0] = 0
        mstSet = [False] * self.V
        parent[0] = -1 
        for i in range(self.V):
            x = self.minKey(key, mstSet)
            mstSet[x] = True
            for y in range(self.V):
                if self.graph[x][y] > 0 and mstSet[y] == False and key[y] > self.graph[x][y]:
                        key[y] = self.graph[x][y]
                        parent[y] = x
        #finding minimum cost spanning tree by Prim's algorithm method
        self.printTree(parent)

print("Enter number of vertices")
n = int(input())
g = Graph(n)
print("Enter adjacency matrix, one row at a time, with the values separated by a ','")
for i in range(n):
    l= input().split(',')
    for j in range(n):
        g.graph[i][j]=int(l[j])
g.primMST();
