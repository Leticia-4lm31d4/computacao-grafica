# Atividade 01 - I/O de imagens. 
**Objetivo**: Classe própria para salvar imagens.

### Documentação
Nessa Primeira atividade, como indicado no roadmap, segui o tutoria até a seção 2, assim, consegui a realiza a saída de uma imagem (quadrado degradê) para o formato `.ppm` por meio do código `main.cpp`. Para vizualizar a imagem, utilizei uma extensão do VScode que permite a vizualização do arquivo `.ppm`.

Com isso iniciei o desenvolvimento de uma classe própria para salvar imagens no formato `,png`, utilizando a biblioteca libpng. Nesse sentido, primeiro construi uma classe chamada `class_save_img` com métodos para salvar a imagem .

Para a documentação houve a construçaõ deste `README`, mas também o uso do `doxygen` no código. Para utilizar o `doxygen` instalei a extensão da ferramenta para o VSCode.

### Fontes
https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview <br>
https://raytracing.github.io/books/RayTracingInOneWeekend.html?authuser=0#outputanimage <br>
http://www.libpng.org/pub/png/libpng.html <br>
https://www.doxygen.nl/

### Roadmap
1. [x] Seguir o “tutorial” até a seção 2;
2. [] Criar uma classe própria para salvar imagens, utilize bibliotecas como libpng, CImg e ImageMagick;
3. [x] Gere pelo menos três imagens. Exemplos: 
    - [x] degradê, 
    - [x] círculo, 
    - [x] quadrado, etc...
4. [] Faça uma breve documentação: 
    - [x] doxygen +
    - [x] readme;