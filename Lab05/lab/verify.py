#!/usr/bin/env python3
import subprocess
import re

cmd = './newprog'.split()
output = subprocess.check_output(cmd, stderr=subprocess.STDOUT)[:-1].split(b'\n')

addr_pattern = b'(' + b'0x' + b'[0-9A-Fa-f]' * 12 + b')'
ans_patterns = [
    b'main: ' + addr_pattern,
    b' func1: ' + addr_pattern,
    b'  func2: ' + addr_pattern,
    b'   func3: ' + addr_pattern,
    b'   func4: ' + addr_pattern,
    b'    func5: ' + addr_pattern,
    b'  func4: ' + addr_pattern,
    b'   func5: ' + addr_pattern,
]

if len(ans_patterns) != len(output):
    print("Verify: WA")
    exit(1)

runtime_addrs = []
for i in range(len(ans_patterns)):
    result = re.match(ans_patterns[i], output[i])
    if result == None:
        print("Verify: WA")
        exit(1)

    if i < 6:
        runtime_addrs.append(int(result.group(1), 16))

funcnames = [
    'main',
    'func1',
    'func2',
    'func3',
    'func4',
    'func5'
]

base_addr = 0
for i in range(6):
    cmd = f'objdump -d -M intel newprog | grep -E "{funcnames[i]}>:"'
    offset = int(subprocess.getoutput(cmd).split(' ')[0], 16)
    
    if i == 0:
        base_addr = runtime_addrs[0] - offset
        if base_addr % 0x1000 != 0:
            print("Verify: WA")
            exit(1)
    elif runtime_addrs[i] - offset != base_addr:
        print("Verify: WA")
        exit(1)

print("Verify: AC")
exit(0)