.include "macro.inc"

.section .text, "ax"

nonmatching rspbootTextStart, 0xD0

glabel rspbootTextStart
.incbin "bin/us/rev1/rspboot.textbin.bin"
.size rspbootTextStart, . - rspbootTextStart
endlabel rspbootTextStart
glabel rspbootTextEnd
endlabel rspbootTextEnd
