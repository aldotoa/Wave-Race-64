#ifndef _OS_LIBC_H_
#define _OS_LIBC_H_

#include "ultratypes.h"

#undef bcopy
#undef bzero
#undef bcmp
#undef sprintf

extern void bcopy(const void *, void *, size_t);
extern void bzero(void *, size_t);

#endif /* !_OS_LIBC_H_ */
