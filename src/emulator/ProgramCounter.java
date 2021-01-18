package emulator;

public class ProgramCounter extends Register {
    public ProgramCounter() {
        MAX_VALUE = 0xffff;
    }

    public void increment() {
        this.value++;
    }

    public void increment(int n) {
        this.value += n;
    }
}