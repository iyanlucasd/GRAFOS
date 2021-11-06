from grafo import Graph


g = { "a" : {"b", "d", "e"},
      "b" : {"c", "d", "e"},
      "c" : {"f"},
      "d" : {"f", "c"},
      "e" : {"c", "f"},
      "f" : {}
    }


graph = Graph(g)

print("Vertices of graph:")
print(graph.all_vertices())

print("Edges of graph:")
print(graph.all_edges())

jorge = []
print('The path from vertex "a" to vertex "f":')
path = graph.find_all_paths("a", "f", jorge)
print(path)
