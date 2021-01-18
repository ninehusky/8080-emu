package emulator;

/**
 * Represents the src.RAM of the 8080, which is best summarized as an array of bytes.
 */
public class RAM {
    private static final int MEMORY_SIZE_IN_BYTES = 65536; // 64 KB src.RAM
    private static final int MAX_BYTE_VAL = 0xff;
    private int[] memory;

    /**
     * Constructs a new src.RAM.
     */
    public RAM() {
        memory = new int[MEMORY_SIZE_IN_BYTES];
    }

    /**
     * Getter.
     * @param address
     * @return byte at the given address in src.RAM
     */
    public int getByte(int address) {
        if (address < 0 || address >= MEMORY_SIZE_IN_BYTES) {
            throw new IllegalArgumentException("Address " + address + " out of bounds!");
        }
        return memory[address];
    }

    /**
     * Sets the byte at the given address to the given value.
     * @param address
     * @param val
     */
    public void setByte(int address, int val) {
        if (val > MAX_BYTE_VAL) {
            throw new IllegalArgumentException("src.RAM at address " + address + " cannot hold 0x" +
                    Integer.toHexString(val));
        }
        memory[address] = val;
    }
}
