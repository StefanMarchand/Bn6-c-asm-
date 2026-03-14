```c
static void sub_3005EF0(void);
static void sub_3005EF0(void)
{
    // Decompiled from 0x3005EF0 in asm00_0.s
    // Body requires assembly context for accurate reconstruction
    __asm__ volatile (
        "push {r4-r7, lr}\n"
        "add r7, sp, #0xc\n"
        "sub sp, #0x10\n"
        "str r0, [sp, #0xc]\n"
        "ldr r3, [sp, #0xc]\n"
        "ldr r2, [r3, #0x40]\n"
        "ldr r1, [r3, #0x44]\n"
        "str r1, [sp, #0x8]\n"
        "ldr r0, [r3, #0x48]\n"
        "str r0, [sp, #0x4]\n"
        "ldr r3, [r3, #0x4c]\n"
        "str r3, [sp]\n"
        "ldr r3, =0x3005F01\n"
        "bl sub_3006B2C\n"
        "add sp, #0x10\n"
        "pop {r4-r7, pc}\n"
        : : : "memory"
    );
}
```
