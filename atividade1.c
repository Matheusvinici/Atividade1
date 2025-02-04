#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h" // Biblioteca para manipulação de tempo

// Definição dos pinos para os LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Estado atual do semáforo (0=vermelho, 1=amarelo, 2=verde)
int status_semaforo = 0;

// Função acionada pelo temporizador
bool alternar_semaforo(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ativar o próximo
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Atualiza o estado do semáforo
    if (status_semaforo == 0) {
        gpio_put(LED_VERMELHO, 1);
        status_semaforo = 1;
    } else if (status_semaforo == 1) {
        gpio_put(LED_AMARELO, 1);
        status_semaforo = 2;
    } else {
        gpio_put(LED_VERDE, 1);
        status_semaforo = 0;
    }

    return true;
}

int main() {
    stdio_init_all(); // Configuração inicial da comunicação serial
    printf("Sistema de semáforo ativado\n");

    // Configuração dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, alternar_semaforo, NULL, &timer); // Configuração do temporizador

    // Loop principal para exibir informações periódicas
    while(true) {
        printf("Contagem de tempo: %lld ms\n", time_us_64()/1000);
        sleep_ms(1000);
    }

    return 0;
}
