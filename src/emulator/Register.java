package emulator;

/**
 * An 8-bit src.Register
 */
public class Register {
    protected static int MAX_VALUE;
    protected int value;

    public Register() {
        MAX_VALUE = 0xff;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        if (value > MAX_VALUE) {
            throw new IllegalArgumentException("Cannot store value greater than 0x" +
                    Integer.toHexString(MAX_VALUE) + " in register.");
        }
        this.value = value;
    }
}
