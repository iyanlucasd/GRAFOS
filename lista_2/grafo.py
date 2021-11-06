class Graph(object):

    def __init__(self, grafo_d=None):
        """ inicializa um objeto gráfico
            Se nenhum dicionário ou nenhum for fornecido,
            um dicionário vazio será usado
        """
        if grafo_d == None:
            grafo_d = {}
        self._grafo_d = grafo_d

    def limite(self, vertice):
        """ retorna uma lista de todos os limites de um vértice"""
        return self._grafo_d[vertice]
        
    def all_vertices(self):
        """ retorna os vértices de um gráfico como um conjunto"""
        return set(self._grafo_d.keys())

    def max_limite(self):
        """ retorna o limite de um gráfico"""
        return self.__limite_gerado()

    def add_vertice(self, vertice):
        """ Se o vértice "vértice" não estiver em
            self._grafo_d, um "vértice" chave com um vazio
            lista como um valor é adicionado ao dicionário.
            Caso contrário, nada precisa ser feito. 
        """
        if vertice not in self._grafo_d:
            self._grafo_d[vertice] = []

    def add_limite(self, limite):
        """ assume que a borda é do tipo conjunto, tupla ou lista;
            entre dois vértices pode haver limite múltiplo!
        """
        limite = set(limite)
        vertice1, vertice2 = tuple(limite)
        for x, y in [(vertice1, vertice2), (vertice2, vertice1)]:
            if x in self._grafo_d:
                self._grafo_d[x].append(y)
            else:
                self._grafo_d[x] = [y]

    def __limite_gerado(self):
        """ Um método estático que gera o limite do
            gráfico "gráfico". limite são representados como conjuntos
            com um (um loop de volta ao vértice) ou dois
            vértices
        """
        limite = []
        for vertice in self._grafo_d:
            for vizinho in self._grafo_d[vertice]:
                if {vizinho, vertice} not in limite:
                    limite.append({vertice, vizinho})
        return limite
    
    def __iter__(self):
        self._iter_obj = iter(self._grafo_d)
        return self._iter_obj
    
    def __next__(self):
        """ allows us to iterate over the vertices """
        return next(self._iter_obj)

    def __str__(self):
        res = "vertices: "
        for k in self._grafo_d:
            res += str(k) + " "
        res += "\nlimite: "
        for limite in self.__limite_gerado():
            res += str(limite) + " "
        return res

    def find_path(self, primeiro_vertice, ultimo_vertice,caminho=None):
        """ find acaminho from primeiro_vertice to ultimo_vertice 
            in grafo """
        ifcaminho == None:
           caminho = []
        grafo = self._grafo_d
       caminho =caminho + [primeiro_vertice]
        if primeiro_vertice == ultimo_vertice:
            returncaminho
        if primeiro_vertice not in grafo:
            return None
        for vertice in grafo[primeiro_vertice]:
            if vertice not incaminho:
                extended_path = self.find_path(vertice, 
                                               ultimo_vertice, 
                                              caminho)
                if extended_path: 
                    return extended_path
        return None
    
    
    def find_all_caminho(self, primeiro_vertice, ultimo_vertice,caminho=[]):
        """ find all caminho from primeiro_vertice to 
            ultimo_vertice in grafo """
        grafo = self._grafo_d 
       caminho =caminho + [primeiro_vertice]
        if primeiro_vertice == ultimo_vertice:
            return [path]
        if primeiro_vertice not in grafo:
            return []
        caminho = []
        for vertice in grafo[primeiro_vertice]:
            if vertice not incaminho:
                extended_caminho = self.find_all_caminho(vertice, 
                                                     ultimo_vertice, 
                                                    caminho)
                for p in extended_caminho: 
                    caminho.append(p)
        return caminho