.include "macro.inc"

.section .text, "ax"

nonmatching gspFast3DTextStart, 0x1430

glabel gspFast3DTextStart
.incbin "bin/us/rev1/f3d.textbin.bin"
.size gspFast3DTextStart, . - gspFast3DTextStart
endlabel gspFast3DTextStart
glabel gspFast3DTextEnd
endlabel gspFast3DTextEnd
