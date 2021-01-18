package emulator.opcodes.miscOpcodes;

import emulator.CPUState;
import emulator.opcodes.Opcode;

public class Nop extends Opcode {
    @Override
    public void exec(CPUState state) {
        System.out.println("NOP");
        state.pc.increment();
    }
}
