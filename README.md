# 8080 emulator.Emulator
My attempt at a functioning 8080 emulator.Emulator that can interpret
the binaries for 8080 games such as Space Invaders.

Previously written in C, but after considerable headache I'm switching
to Java.

As of now, the &lt;ComputerPart&gt;.java files are interfaces for changing
/ getting the various fields, and the emulator.OpcodeManager/emulator.Emulator is responsible
for actually doing the "thinking" related to these fields.

TODO:
- consider making a byte/word utils class to work around Java's lack of uint8_t
