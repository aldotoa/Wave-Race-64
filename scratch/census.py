import os, re, glob

rows = []
for p in glob.glob('asm/us/rev1/nonmatchings/**/func_*.s', recursive=True):
    txt = open(p, errors='ignore').read()
    instr = [l for l in txt.split('\n')
             if re.match(r'\s*/\* [0-9A-F]+ ', l)]
    n = len(instr)
    body = '\n'.join(instr)
    calls = len(re.findall(r'\bjal\b', body))
    floats = len(re.findall(r'\.\.float|mtc1|lwc1|swc1|mul\.s|add\.s|sub\.s|div\.s|c\.\w+\.s', body))
    rodata = len(re.findall(r'dlabel', txt))
    jr = len(re.findall(r'\bjr\b', body))
    fname = os.path.basename(p)
    rows.append((n, calls, floats, rodata, jr, p))

rows.sort()
print(f"{'instr':>6} {'jal':>4} {'flt':>4} {'rod':>4} {'jr':>3}  path")
for r in rows[:40]:
    print(f"{r[0]:>6} {r[1]:>4} {r[2]:>4} {r[3]:>4} {r[4]:>3}  {r[5]}")
print('...')
print('total func stubs:', len(rows))
