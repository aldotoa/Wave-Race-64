import re
from find_iv_match import compile_and_check

with open("scratch/test_tmp.c") as f:
    orig = f.read()

# Replace ARR_VAL one by one with [player]
# Find all occurrences of ARR_VAL
matches = list(re.finditer(r"ARR_VAL\(([a-zA-Z0-9_]+)\)", orig))
print(f"Total ARR_VAL occurrences: {len(matches)}")

# Test replacing from N down to 0
for n_replace in range(0, len(matches) + 1):
    # replace first n_replace occurrences with \1[player]
    code = orig
    for m in reversed(matches[:n_replace]):
        arr = m.group(1)
        code = code[:m.start()] + f"{arr}[player]" + code[m.end():]
    
    res = compile_and_check(code)
    if res:
        delay, after = res
        print(f"Replace {n_replace:2d}: delay={delay}")
        for a in after[:5]:
            print(f"   {a}")
        print("-" * 40)

