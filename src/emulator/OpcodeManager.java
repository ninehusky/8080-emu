package emulator;

import java.util.HashMap;
import java.util.Map;

import emulator.opcodes.Opcode;
import emulator.opcodes.miscOpcodes.*;

public class OpcodeManager {
    private static Map<Integer, Opcode> cache;
    private CPUState state;

    public OpcodeManager(CPUState state) {
        this.state = state;
    }

    public void executeInstruction(int opcode) {
        Opcode instruction = this.cache.get(opcode);
        if (instruction == null) {
            throw new IllegalArgumentException("0x" + Integer.toHexString(opcode) + " is invalid/unimplemented!");
        }
        instruction.exec(this.state);
    }

    static {
        cache = new HashMap<Integer, Opcode>();
        cache.put(0x0, new Nop());
    }
}
