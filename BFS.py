from input_graph_BFS import input_graph
from heapq import heappush, heappop
def BFS(graph,start,goal):
    visited=[]
    #open_list
    n=len(graph)
    open_list=[]
    parent_node={}
    #find start node in graph
    for i in range(n):
        if graph[i][0]==start:
            parent_node[graph[i][0]]=None
            visited.append(graph[i][0])
            heappush(open_list,[graph[i][2]+graph[i][3],graph[i][0]])
            break
    
    if len(open_list)==0:
        return "No path found"
    cost,node=heappop(open_list)
    parent_node[node]=None
    for i in range(n):
        if graph[i][0]==node and graph[i][1] not in visited:
            heappush(open_list,[graph[i][2]+graph[i][3],graph[i][1]])
        
    if len(open_list)==0:
        return "No path found"
    while open_list:                
        cost,node1=heappop(open_list)
        open_list=[]
        
        
        parent_node[node1]=node
        visited.append(node1)
        if node1==goal:
            return parent_node
        
        for i in range(n):
            if graph[i][0]==node1 and graph[i][1] not in visited:
                heappush(open_list,[graph[i][2]+graph[i][3],graph[i][1]])
        node=node1
    return "No path found"

def print_path(parent_node,start,goal):
    path=[]
    path.append(goal)
    while parent_node[goal] is not None:
        path.append(parent_node[goal])
        goal=parent_node[goal]
    
    path.reverse()
    return path

graph=input_graph()
start=int(input("Enter the start node: "))
goal=int(input("Enter the goal node: "))
parent_node=BFS(graph,start,goal)
path=print_path(parent_node,start,goal)
print(path)
        
    

        

        
        


    
   


