//
// Created by bczhc on 05/11/23.
//

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    setup_default_uart();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    printf("Hello, world!\n");
    char s[20];
    scanf("%s\n", s);
    printf("You input: %s\n", s);

    gpio_put(LED_PIN, 1);
    return 0;
}