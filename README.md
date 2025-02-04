Sistema de Semáforo com Raspberry Pi Pico

Este código implementa um sistema de semáforo utilizando o Raspberry Pi Pico. O sistema alterna entre três LEDs representando as cores vermelho, amarelo e verde em um intervalo de 3 segundos.

Requisitos

Raspberry Pi Pico

Três LEDs (Vermelho, Amarelo e Verde)

Resistores apropriados para os LEDs

Fios de conexão

Ambiente de desenvolvimento configurado para programação do Raspberry Pi Pico (VSCode, SDK do Pico, etc.)

Explicação do Código

Inclusão de Bibliotecas: São incluídas as bibliotecas necessárias para controle dos GPIOs e manipulação de tempo.

Definição dos Pinos: São definidos os pinos GPIO onde os LEDs estão conectados.

Variável de Estado: status_semaforo controla a cor atual do semáforo.

Função alternar_semaforo:

Desliga todos os LEDs.

Liga o LED correspondente ao próximo estado do semáforo.

Atualiza a variável status_semaforo para o próximo estado.

Função main:

Inicializa a comunicação serial para depuração.

Configura os pinos dos LEDs como saída.

Configura um temporizador que chama alternar_semaforo a cada 3 segundos.

Entra em um loop infinito exibindo o tempo decorrido a cada segundo.

Como Usar

Conecte os LEDs aos pinos especificados no código.

Compile e carregue o código no Raspberry Pi Pico.

Observe o funcionamento do semáforo, alternando entre as cores vermelho, amarelo e verde.