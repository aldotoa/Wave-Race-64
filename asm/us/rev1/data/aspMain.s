.include "macro.inc"

.section .text, "ax"

nonmatching aspMainTextStart, 0xE20

glabel aspMainTextStart
.incbin "bin/us/rev1/aspMain.textbin.bin"
.size aspMainTextStart, . - aspMainTextStart
endlabel aspMainTextStart
glabel aspMainTextEnd
endlabel aspMainTextEnd
