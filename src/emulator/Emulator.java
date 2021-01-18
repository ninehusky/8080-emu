package emulator;


public class Emulator {
    public static void main(String[] args) {
        CPUState state = new CPUState();
        OpcodeManager manager = new OpcodeManager(state);
        manager.executeInstruction(0x0);
    }
}
