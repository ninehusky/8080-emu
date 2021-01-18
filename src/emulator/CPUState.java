package emulator;

/**
 * An interface (whatever tf that means) to the internals of the 8080.
 */
public class CPUState {
    public CPUState() {
        a = new Register();
        b = new Register();
        c = new Register();
        d = new Register();
        e = new Register();
        f = new Register();
        h = new Register();
        l = new Register();
        pc = new ProgramCounter();

        ram = new RAM();
    }

    // Registers
    public Register a;
    public Register b;
    public Register c;
    public Register d;
    public Register e;
    public Register f;
    public Register h;
    public Register l;

    public ProgramCounter pc;

    // Condition Bits
    public boolean zero;
    public boolean carry;
    public boolean sign;
    public boolean parity;
    public boolean auxCarry;

    public RAM ram;
}
