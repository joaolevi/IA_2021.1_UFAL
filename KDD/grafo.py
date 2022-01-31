from collections import defaultdict

class Node():
    def __init__(self, data):
        self.data = data


class Grafo(object):

    def __init__(self, direcionado=False):
        self.adj = defaultdict(set)
        self.direcionado = direcionado


    def get_vertices(self):
        return list(self.adj.keys())


    def get_arestas(self):
        return [(k, v) for k in self.adj.keys() for v in self.adj[k]]


    def adiciona_arestas(self, node1, node2):
        self.adiciona_arco(node1, node2)


    def __adiciona_arco__(self, node1, node2):
        self.adj[node1].add(node2)
        if not self.direcionado:
            self.adj[node2].add(node1)


    def existe_aresta(self, node1, node2):
        return node1 in self.adj and node2 in self.adj[node1]


    def __len__(self):
        return len(self.adj)


    def __str__(self):
        return '{}({})'.format(self.__class__.__name__, dict(self.adj))


    def __getitem__(self, node2):
        return self.adj[node2]


grafo = Grafo()

grafo.__adiciona_arco__(1, 2)