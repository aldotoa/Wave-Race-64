#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define TARGET_MAC 1
#define IS_64_BIT 1
#define IS_BIG_ENDIAN 0

#define BSWAP16(x) __builtin_bswap16(x)
#define BSWAP32(x) __builtin_bswap32(x)
#define BSWAP64(x) __builtin_bswap64(x)

#endif /* PORT_CONFIG_H */
