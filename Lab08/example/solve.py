import angr
import sys

main_addr = 0x4011c9
find_addr = 0x4012b0
avoid_addr = 0x4012c6

def handle_fgets_real_input(raw_input):
    idx = 0
    for c in raw_input:
        if c == ord('\n') or c == ord('\0'):
            break
        idx += 1
    return raw_input[:idx]

class my_fgets(angr.SimProcedure):
    def run(self, s, num, f):
        simfd = self.state.posix.get_fd(sys.stdin.fileno())
        data, ret_size = simfd.read_data(0x20)
        self.state.memory.store(s, data)
        return ret_size

proj = angr.Project('./src/prog', load_options={'auto_load_libs': False})
proj.hook_symbol('fgets', my_fgets(), replace=True)

state = proj.factory.blank_state(addr=main_addr)

simgr = proj.factory.simulation_manager(state)
simgr.explore(find=find_addr, avoid=avoid_addr)
if simgr.found:
    print(simgr.found[0].posix.dumps(sys.stdin.fileno()))

    input1 = simgr.found[0].posix.dumps(sys.stdin.fileno())[:0x20]
    input1 = handle_fgets_real_input(input1)

    input2 = simgr.found[0].posix.dumps(sys.stdin.fileno())[0x20:]
    input2 = handle_fgets_real_input(input2)

    print('Account: ' + input1.decode())
    print('Passwd : ' + input2.decode())
else:
    print('Failed')