# Atividade 04 - Visualização Inicial

### Fontes
Tutorial 1: https://raytracing.github.io/books/RayTracingInOneWeekend.html <br>
Tutorial 2: https://raytracing.github.io/books/RayTracingTheNextWeek.html

### Roadmap
1) - [X] Siga o "tutorial 1" até a seção 5
2) - [X] Implemente a visualização da esfera, integrando com as implementações anteriores (Atividade 1 e Atividade 2)
3) - [X] Veja a seção 6.2 do "tutorial 2"
4) - [] Implemente a visualização de um triângulo
5) - [] Com a implementação da Atividade 3, visualize um objeto todo, lido de um arquivo
6) - [X] Documente adequadamente

## Documentação

### Tutorial 1 até a seção 5
Para essa etapa bastou seguir os códigos e explicações deles disponíveis no tutorial 1 até a seção 5 para ter o resultado final correto, que é o modelo de uma esfera vermelha em um fundo de gradiente azul. Esse resultado está disponível no arquivo `tutorial1.ppm`, já os arquivos usados para formar a cena foram: `main.cpp`, `vec3.h`, `color.h` e `ray.h`.

![Circulo vermelho em fundo azul gradiente](image.png)

### Visualização da esfera, integrando com as implementações da Atividade 1 e Atividade 2
Nesse sentido, ocorre a integração das atividades 1, geração de imagens de formas geométricas, e atividade 2, manipulação de vetores e matrizes.

### Tutorial 2 seção 6.2
A seção 6.2 fala sobre "*Ray-Plane Intersection*", que trata sobre a interseção entre um raio e um plano, com o objetivo de implementar essa funcionalidade. Então, fala sobre o processo de calcular a interseção entre um raio e um plano, utilizando a fórmula implícita do plano e o produto escalar. 

Além disso, a função quad::hit() precisa ser implementada para verificar se um raio interage com o objeto, se sim, precisa determinar as propriedades dessa interseção, como: ponto de impacto, normal, coordenadas de textura. Para isso, é necessário encontrar o plano que contém o objeto, resolver a interseção entre um raio e o plano que contém o objeto e, assim, determinar se o ponto de impacto está dentro do objeto.

### Implementação da visualização de um triângulo
