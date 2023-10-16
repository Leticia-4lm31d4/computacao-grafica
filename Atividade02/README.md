# Atividade 02 - Operações Matriciais. 
**Objetivo**: Criar uma classe própria para manipular vetores e matrizes.

### Documentação
A princípio, segui o **tutorial da seção 3** copiando e depois estudando os códigos `vec3.h`, `color.h` e `main.cpp` que geram a imagem da seção 2 (um quadrado degrade) no formato *ppm*. Nesse sentido, esse conjunto de códigos geram a imagem com cores *rgb* `degrade.ppm`. Para visualização da imagem utilizei uma extensão do VSCode para o formato *.ppm*. Porém, a fim de documentação também a salvei como *.png*:

![Imagem Degrade](./tutorial/degrade.png)

Dessa maneira, para continuar o desenvolvimento e expandi-lo para manipulação de outros vetores e de matrizes, criei um arquivo para cada tipo de vetor e matriz para armazenar as classes `vec3`, `vec2`, `vec4`, `mat2`, `mat3` e `mat4`.

Com isso, iniciei o desenvolvimento das **classes de vetores, `vec2` e `vec4`**, utilizando o código do `vec3` como base. Com as classes construídas, as funções globais foi o mesmo processo de semelhança ao vetor tridimensional, entretanto, as classes *vec2* e *vec4* não possuem a função de produto vetorial, pois apenas vetores tridimensionais podem realizar essa operação. Assim, realizei os testes unitários para as classes do vetores, no arquivo `vetores.cpp` imprimindo os resultados no arquivo `vec_teste.txt`.

Para a criação das **classes de matrizes `mat2`, `mat3` e `mat4`**, também utilize o código do *vec3* como base, porém o que mudou foi a adição de linhas na definição do objeto matriz (mat[i][i]). Com as três classes criadas iniciei o desenvolvimento dos métodos.

Para os **testes unitários** não utilizei biblioteca, por isso, para melhor vizualização dos resultados das saídas dos códigos `vetores.cpp` e `matrizes.cpp`, onde estão os testes, foram impressos nos arquivos *txt*: `vet_teste.txt` e `mat_teste.txt`, respectivamente.

**Legenda** <br>
`vec3` - Vetor tridimensional <br>
`vec2` - Vetor bidimensional <br>
`vec4` - Vetor de 4 componentes <br>

`mat2` - Matriz 2x2 <br>
`mat3` - Matriz 3x3 <br>
`mat3` - Matriz 4x4 <br>

Para a **documentação**, este `README` foi construido ao longo do desenvolvimento da atividade e para documentar os códigos utilizei da extensão do *doxygen* para o *VSCode* a fim de gerar comentários que explicasse os códigos de modo objetivo.

### Fontes
https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class <br>


### Roadmap
- [x] Seguir o “tutorial” até a seção 3
- [] Criar uma classe própria para manipular vetores e matrizes, expanda para:
    - [x] vec2, vec4, 
    - [] mat2, mat3 e mat4
- [] Faça testes unitários, escolha uma biblioteca que facilite
- [x] Faça uma breve documentação