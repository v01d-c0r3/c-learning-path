#include <stdio.h>
#include <stdint.h>

/* Simulated MMIO register (normally a hardware address) */
static volatile uint32_t GPIO_OUT = 0;
#define GPIO_PIN_13  (1u << 13)

static inline void gpio_set(uint32_t pin)   { GPIO_OUT |=  pin; }
static inline void gpio_clear(uint32_t pin) { GPIO_OUT &= ~pin; }

void delay_cycles(volatile int n) { while (n--); }

int main(void) {
    /* TODO 1: blink pin 13 ten times (set, delay, clear, delay)   */
    /* TODO 2: write a minimal linker script for a Cortex-M0 image */
    /* TODO 3: sketch the startup code that zeros .bss and calls main */
    return 0;
}
