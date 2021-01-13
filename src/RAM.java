import java.io.*;

public class RAM {
    public static final int TOTAL_BYTES = 65536; // 64 KB of addressable space in RAM
    private int[] memory;

    public RAM() {
        memory = new int[TOTAL_BYTES];
    }

    public int getByte(int address) {
        handleAddressExceptions(address);
        return memory[address];
    }

    public void setByte(int address, int value) {
        handleAddressExceptions(address);
        memory[address] = value;
    }

    public void populateRAMWithBuffer(int offset, InputStream buffer) {
        // do stuff with buffer
        // TODO: should I make offset a constant?
    }

    private void handleAddressExceptions(int address) {
        if (address < 0 || address > TOTAL_BYTES) {
            throw new IllegalArgumentException(address + " is not a valid address in RAM!");
        }
    }
}
