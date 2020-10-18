# The travelling salesman problem (also called the traveling salesperson problem[1] or TSP) asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?" 
# It is an NP-hard problem in combinatorial optimization, important in theoretical computer science and operations research.
# solvable in time O((n**2)*(2**n))

class BitDp:
    def __init__(self, V:int):
        self._V = V
        self._cost = [[10**10]*V for _ in range(V)]  # move weight table
        self._dp = [[-1] * V for _ in range(1<<V)]   # memo table
    
    def cost_setter(self, root:list):
        for start, end, cost in root:
            self._cost[start][end] = cost
    
    def dfs(self, S:int, v:int) -> int:
        if self._dp[S][v] != -1:  # Return notes if visited
            return self._dp[S][v]
        if S==(1<<V)-1 and v==0:  # Visited all vertices and returned to vertex 0
            return 0  # No need to move anymore
        
        res = 10**10
        for u in range(self._V):
            if S>>u & 1 == 0:  # Whether you have not visited
                res = min(res, self.dfs(S|1<<u, u)+self._cost[v][u])
        self._dp[S][v] = res
        return res

V = 4  # Number of vertices(A value of 20 or less is appropriate)
move_cost = [[0, 1, 2],  # [start_point, end_point, move_cost],
            [1, 2, 3],
            [1, 3, 9],
            [2, 0, 1],
            [2, 3, 6],
            [3, 2, 4]
        ]

b = BitDp(V)
b.cost_setter(move_cost)
result = b.dfs(0, 0)  # Start from vertex 0. However, vertex 0 is not visited
if result == 10**10:
    print(-1)         # There is no answer that visits all the vertices
else:
    print(result)     # 16 (The shortest path that goes through all points at least once)