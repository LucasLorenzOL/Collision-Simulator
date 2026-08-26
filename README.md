Aluno: Lucas Lorenzo Liberal Pedrosa

RA: 2878518

## Resumo

&nbsp;&nbsp;&nbsp;&nbsp;Esse projeto consiste em gerar uma janela e, baseado nas configurações colocadas, gerar uma quantia X de bolas e simular colisões entre elas. A simulação é bidimensional utilizando a biblioteca gráfica SMFL em C++ puro. Fórmulas e explicação do código podem ser encontrados [aqui](#video-demonstrativo-e-explicativo-do-projeto).



> **Sumário**
  
  
  
* [Sobre o projeto](#sobre-o-projeto)
* [Compilação e execução](#compilacao-e-execucao)



  

<h2 id="video-demonstrativo-e-explicativo-do-projeto"> Vídeo demonstrativo e explicativo do projeto </h2>

<p align="center">
  <a href="https://www.youtube.com/watch?v=V6SmgQayk9c">
    <img src="https://img.youtube.com/vi/V6SmgQayk9c/hqdefault.jpg" alt="Vídeo do Projeto">
  </a>
</p>





## Sobre o projeto

O projeto foi feito utilizando a biblioteca SFML e todo o código fonte está comentado.    

  > ## Configurando

  O arquivo de configurações pode ser encontrado dentro da pasta config, com o nome de "config.txt". Você pode modificar algumas propriedades do simulador, como:  



  - Largura da janela - `width`  


  - Altura da janela - `height`


  - Número de bolas - `num_balls`


  - Raio das bolas - `radius`  


  - Coeficiente de restituição da velocidade - `cv`



Para modificá-los, basta escrever a palavra chave (mostrada acima) e o valor ao lado. width, height e num_balls aceitam somente valores inteiros, enquanto radius e cv suportam valores reais.





> **Se você quiser, também pode inicializar via terminal, usando o seguinte template:**


  
`(caminho até o diretório do programa)/SimuladorDeColisoes width height num_balls radius cv`








<h2 id="compilacao-e-execucao">Compilação e execução</h2>



O código foi compilado usando a extensão CMake e auxílio do sistema Ninja, se houver algum problema ou dúvida na hora de compilar para executar, entre em contato.





> **Usando a extensão CMake, a sequência de comandos foi (considerando que você está na root do projeto):**



``` bash
mkdir build && cd build

cmake -G Ninja ..

ninja

```





> **Utilizando o compilador g++, utilize a sequência a seguir (também considerando que você está na root do projeto)**:




``` bash

mkdir build && cd build

g++ -std=c++17 ../src/*.cpp -o SimuladorDeColisoes -lsfml-graphics -lsfml-window -lsfml-system

```





> **Para executar:**



``` bash
./SimuladorDeColisoes
```
