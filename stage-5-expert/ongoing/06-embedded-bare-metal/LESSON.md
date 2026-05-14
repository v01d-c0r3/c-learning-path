# Lesson: Embedded & bare-metal C

## What is bare-metal programming?

Writing C that runs directly on hardware with no OS. You control everything: startup, memory layout, peripheral access.

## Memory-mapped I/O (MMIO)

Hardware peripherals are controlled by reading/writing specific memory addresses. On an STM32 microcontroller:

```c
// GPIO registers live at fixed addresses in the memory map
#define GPIOA_ODR  (*(volatile uint32_t*)0x40020014)

// Toggle PA5 (LED on Nucleo board)
GPIOA_ODR ^= (1 << 5);
```

`volatile` is critical — it tells the compiler not to optimise away reads/writes to hardware registers.

## Linker script

Tells the linker where to place code and data in the device's memory map:

```ld
MEMORY {
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
    .text : { *(.text*) } > FLASH
    .data : { *(.data*) } > RAM AT > FLASH
    .bss  : { *(.bss*)  } > RAM
}
```

## Startup code

Before `main` runs, the CPU needs:
1. Stack pointer initialised
2. `.data` section copied from flash to RAM
3. `.bss` section zeroed

```c
extern uint32_t _sdata, _edata, _sidata;  // from linker script
extern uint32_t _sbss,  _ebss;

void Reset_Handler(void) {
    // copy .data from flash to RAM
    uint32_t *src = &_sidata, *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;

    // zero .bss
    for (uint32_t *p = &_sbss; p < &_ebss; p++) *p = 0;

    main();
    while (1);  // trap if main returns
}
```

## Interrupt service routines (ISR)

```c
void TIM2_IRQHandler(void) __attribute__((interrupt));

void TIM2_IRQHandler(void) {
    // handle timer interrupt
    TIM2->SR &= ~TIM_SR_UIF;   // clear interrupt flag
}
```

ISRs must be fast, non-blocking, and async-signal-safe (same rules as POSIX signal handlers).

---

## My notes

**What confused me:**

**What clicked:**

**volatile in MMIO — why it matters:**

**Things to look up later:**
