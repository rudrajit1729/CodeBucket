class Graph: 
  
    def __init__(self,vert): 
        self.V= vert
        #variable to store number of vertices 
        self.graph = []
        #variable to store graph
   
    def addEdge(self,u,v,w): 
        self.graph.append([u,v,w]) 
  
    def find(self, parent, i): 
        if parent[i] == i: 
            return i 
        return self.find(parent, parent[i]) 
  
    def union(self, parent, rank, x, y): 
        a = self.find(parent, x) 
        b = self.find(parent, y) 
  
        if rank[a] < rank[b]: 
            parent[a] = b 
        elif rank[a] > rank[b]: 
            parent[b] = a 
        else : 
            parent[b] = a 
            rank[a] +=1
  
    def KruskalMST(self): 
        result =[] 
        i = 0  
        c = 0 
        self.graph =  sorted(self.graph,key=lambda item: item[2])
        #sorting edges in increasing order of weight
        parent = [] 
        rank = []  
        for node in range(self.V): 
            parent.append(node) 
            rank.append(0) 
        while c < self.V -1 : 
            u,v,w =  self.graph[i] 
            i = i + 1
            x = self.find(parent, u) 
            y = self.find(parent ,v) 
            if x != y: 
                c = c + 1     
                result.append([u,v,w]) 
                self.union(parent, rank, x, y)               
        print ("Edges in final MST are as follows:")
        for x,y,w in result: 
            print ("%d - %d \t %d" % (x,y,w)) 

print("Enter number of vertices")
n = int(input())
g = Graph(n)
print("Enter edges and respective weights in <source,destination,weight> format")
i=0
while i==0:
    l=input().split(',')
    g.addEdge(int(l[0]),int(l[1]),int(l[2]))
    i=int(input("Enter 0 to continue or 1 to stop\n")) 
g.KruskalMST() 
