#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try out our custom printf!\n");
    _printf("Length: %d\n", len);

    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Decimal: %d\n", 12345);
    _printf("Unsigned Decimal: %u\n", 98765);
    _printf("Hexadecimal (lowercase): %x\n", 255);
    _printf("Hexadecimal (uppercase): %X\n", 255);
    _printf("Binary: %b\n", 19);
    _printf("Octal: %o\n", 63);
    _printf("Pointer Address: %p\n", (void *)0x12345678);
    _printf("Percent Sign: %%\n");

    _printf("Reversed String: %r\n", "Reversed");
    _printf("String in ROT13: %R\n", "Hello, World!");
    _printf("Non-Printable String: %S\n", "Hello\t\tWorld\n");

    len = _printf("Formatted Integers: %+d, % d, %+d\n", 42, 42, -42);
    _printf("Length: %d\n", len);

    return (0);
}
