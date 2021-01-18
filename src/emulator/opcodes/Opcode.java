package emulator.opcodes;

import emulator.CPUState;

public abstract class Opcode {
    public abstract void exec(CPUState state);
}
