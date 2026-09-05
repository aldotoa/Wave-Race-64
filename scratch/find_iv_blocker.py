import subprocess
import re

# Read test_for_loop.c
with open("scratch/test_for_loop.c") as f:
    code = f.read()

# Let's see if test_for_loop without switch statements gets the IV
# Replace the switch statements with dummy code
