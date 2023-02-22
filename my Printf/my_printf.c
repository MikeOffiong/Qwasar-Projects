#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define INT_TO_STRING_BUF_SIZE (sizeof(long long) * 3 + 1)

int int_to_string(long long value, char* buffer, int base, bool uppercase) {
    char* p = buffer;
    char* p1, *p2;
    int digits = 0;
    int is_negative = 0;

    // Check if base is in range 2 to 16
    if (base < 2 || base > 16) {
        return 0;
    }

    // Handle negative integers
    if (value < 0) {
        is_negative = 1;
        if (value == LLONG_MIN) {
        // Special case for minimum negative long long value
        value = LLONG_MAX;
        is_negative = 0;
        } else {
        value *= -1;
        }
    }

    // Output digits in reverse order
    do {
        long long remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : ((base == 16) && (remainder >= 10)) ? (uppercase ? remainder + 'A' - 10 : remainder + 'a' - 10) : remainder + 'A' - 10;
        digits++;
    } while (value /= base);

    // Add minus sign for negative integers
    if (is_negative) {
        *p++ = '-';
        digits++;
    }

    // Terminate string
    *p = 0;

    // Reverse string
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2) {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
    return digits;
}

int my_printf(const char* format, ...) {
    va_list args;
    int count = 0;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
        // Process format specifier
        format++;
        switch (*format) {
            case 'd': {
            // Process int argument
            int value = va_arg(args, int);
            char buffer[INT_TO_STRING_BUF_SIZE];
            int digits = int_to_string((long long)value, buffer, 10, false);
            fputs(buffer, stdout);
            count += digits;
            break;
            }
            case 'o': {
            // Process integer argument as octal
            int value = va_arg(args, int);
            char buffer[INT_TO_STRING_BUF_SIZE];
            count += int_to_string((long long)value, buffer, 8, false);
            fputs(buffer, stdout);
            break;
            }
            case 'u': {
            // Process integer argument as unsigned
            unsigned int value = va_arg(args, unsigned int);
            char buffer[INT_TO_STRING_BUF_SIZE];
            count += int_to_string((long long)value, buffer, 10, false);
            fputs(buffer, stdout);
            break;
            }
            case 'x': {
            // Process integer argument as hexadecimal
            int value = va_arg(args, int);
            char buffer[INT_TO_STRING_BUF_SIZE];
            int digits = int_to_string((long long)value, buffer, 16, true);
            fputs(buffer, stdout);
            count += digits;
            break;
            }
            case 'c': {
            // Process character argument
            char value = (char)va_arg(args, int);
            fputc(value, stdout);
            count++;
            break;
            }
            case 's': {
            // Process string argument
            char* value = va_arg(args, char*);
            if (value == NULL) {
                fputs("(null)", stdout);
                count += 6;
            } else {
                fputs(value, stdout);
                count += strlen(value);
            }
            break;
            }
            case 'p': {
            // Process pointer argument
            void* value = va_arg(args, void*);
            char buffer[INT_TO_STRING_BUF_SIZE];
            fputs("0x", stdout);
            int digits = int_to_string((unsigned long long)value, buffer, 16, false);
            fputs(buffer, stdout);
            count += 2 + digits;
            break;
            }
            default: {
            // Output percent sign for unknown format specifiers
            fputc('%', stdout);
            count++;
            break;
            }
        }
        } else {
        // Output regular characters
        fputc(*format, stdout);
        count++;
        }
        format++;
    }
    va_end(args);
    return count;
}

int main(void) {
    printf("Hello, world!\n");
    return 0;
}