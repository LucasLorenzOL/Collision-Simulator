Aluno: Lucas Lorenzo Liberal Pedrosa
RA: 2878518

Esse projeto consiste em gerar uma janela e, baseado nas configurações colocadas, gerar uma quantia X de bolas e simular colisões entre elas.

-------------------------------------------------- Informações sobre a configuração e execução do projeto -----------------------------------------------------------------------

O projeto foi feito utilizando a biblioteca SFML e todo o código fonte está comentado (fiz em inglês porque acho bom já desenvolver esse costume).

O arquivo de configurações pode ser encontrado dentro da pasta config, com o nome de "config.txt". Você pode modificar algumas propriedades do simulador, como:

Largura da janela - width
Altura da janela - height
Número de bolas - num_balls
Raio das bolas - radius
Coeficiente de restituição da velocidade - cv

Para modificá-los, basta escrever a palavra chave (mostrada acima) e o valor ao lado. width, height e num_balls aceitam somente valores inteiros, enquanto radius e cv suportam valores reais.

# Se você quiser, também pode inicializar via terminal, usando o seguinte template:

(caminho até o diretório do programa)/SimuladorDeColisoes width height num_balls radius cv

-------------------------------------------------------------------------- Extra ----------------------------------------------------------------------------------------------

O programa mostra também o comportamento da energia cinética ao longo da simulação. O motivo de eu não utilizar a quantidade de movimento (Qm ou P) é devido à colisão entre as bolas e as bordas da janela, onde eu decidi apenas inverter o sentido da velocidade naquele eixo, então quando a bola bate na parede: ΔQm = Qmf - Qmi = m(-v) - mv = -2mv (as colisões entre bola e borda são sempre de CV = 1).

O código foi compilado usando a extensão CMake e auxílio do sistema Ninja, se houver algum problema ou dúvida na hora de compilar para executar, entre em contato.

# Usando a extensão CMake, a sequência de comandos foi (considerando que você está na root do projeto):

mkdir build && cd build
cmake -G Ninja ..
ninja

# Utilizando o compilador g++, utilize a sequência a seguir (também considerando que você está na root do projeto):

mkdir build && cd build
g++ -std=c++17 ../src/*.cpp -o SimuladorDeColisoes -lsfml-graphics -lsfml-window -lsfml-system

# Para executar
./SimuladorDeColisoes