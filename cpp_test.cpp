//
// Created by bczhc on 05/11/23.
//

#include <cstdio>
#include "pico/stdlib.h"
#include <iostream>
#include <cstdint>

extern "C" {
#include "third_party/bczhc_cpp/third_party/crypto-algorithms/sha256.h"
}

#include "def.h"

using namespace std;

void print_hex(u8 *a, usize length) {
    for (usize i = 0; i < length; ++i) {
        printf("%02x", a[i]);
    }
    printf("\n");
}

void sha256_n(u8 *hash, u8 *data, usize length, u64 iter_num = 1) {
    sha256((BYTE *) hash, (BYTE *) data, length);

    for (u64 i = 1; i < iter_num; ++i) {
        sha256((BYTE *) hash, (BYTE *) hash, 32);
    }
}

void led_hint() {
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    sleep_ms(10);

    gpio_put(PICO_DEFAULT_LED_PIN, false);
}

void do_loop() {
    const char init_msg[] = "好";
    char hash[32];
    sha256_n((BYTE *) hash, (BYTE *) init_msg, sizeof(init_msg) - 1, 10000);
    print_hex((u8 *) hash, 32);
    while (true) {
        sha256_n((BYTE *) hash, (BYTE *) hash, 32, 10000);
        print_hex((u8 *) hash, 32);
        led_hint();
    }
}

int main() {
    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    do_loop();
}
