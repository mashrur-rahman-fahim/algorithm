def input_graph():
    #[node,connected_node,cost,heuristic_cost]
    n=int(input("Enter the number of edges: "))
    graph=[]
    for i in range(n):
        node=int(input("Enter the node: "))
        connected_node=int(input("Enter the connected node: "))
        cost=int(input("Enter the cost: "))
        heuristic_cost=int(input("Enter the heuristic cost: "))
        graph.append([node,connected_node,cost,heuristic_cost])
    print(graph)  
    return graph

#input
# 17
# 0 
# 1 
# 7 
# 10
# 0 
# 2 
# 2 
# 10
# 0 
# 3 
# 3 
# 10
# 1 
# 4 
# 4 
# 9
# 1 
# 2 
# 3 
# 9
# 2 
# 4 
# 4 
# 7
# 2 
# 8 
# 1 
# 7
# 3 
# 12 
# 2 
# 8
# 4 
# 6 
# 5 
# 8
# 8 
# 6 
# 3 
# 6
# 8 
# 7 
# 2 
# 6
# 12 
# 9 
# 4 
# 6
# 12 
# 10 
# 4 
# 6
# 7 
# 5 
# 2 
# 3
# 9 
# 11 
# 4 
# 4
# 10 
# 11 
# 4 
# 4
# 11 
# 5 
# 5 
# 3