import Matrices
from Base3DObjects import Vector

m = Matrices.ModelMatrix()
v = Matrices.ViewMatrix()
p = Matrices.ProjectionMatrix()


p.set_perspective(90, 800/600, 10, 100)

for el in p.get_matrix():
    print(el)
