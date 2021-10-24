1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program 
only once to increment “counter”. 
    1. "Locals" window: -2147483648
    2. "Registers" window: 0x80000000
    3. "N" flag is set because the most significant bit was changed to 1; "V" flag is set because instruction result doesn't fit in the 32 bit register. Overflow occurred.

2. If your write all Fs (0xFFFFFFFF) in the Register value for “counter” then step thru the program 
once to increment “counter” 
    1. "Locals" window: 0
    2. "Z" flag is set because the instruction result is zero; "C" flag is set because the instruction result has one more significant bit. Carry condition.

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values 
“0x7FFFFFFF” then step thru the program to increment the “counter” once
    1. "Locals" window: 2147483648
    2. "N" flag is set because the most significant bit was changed to 1; "V" flag is set because the instruction result doesn't fit in a 32 bit register. Overflow occurred. Processor doesn't care about whether this is signed or unsigned.

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” 
then step thru the program to increment the “counter” once
    1. "Locals" window: 0
    2. "Z" flag is set because the instruction result is zero; "C" flag is set because the instruction result has one more significant bit. Carry condition.

5. Move the “counter’ variable outside of main (at the top of the file)
    1. Scope is global. 
    2. No
    3. "Watch" window and "Memory" window
    4. 0x20000000

6. Change the source code to the following, then run the program in the simulator:
    1. "counter" values is 4 at the end of the program
    2. "p_int" points to the memory address where value of "counter" is stored. We increase the value stored at that address via "p_int" 3 times. Eventually increment "counter" by 1. Final value of "counter" becomes 4.

7. Change the setting of IAR to run the same program on the evaluation board
    1. "counter" address is 0x20000000
    2. "counter" variable is stored in RAM
    3. Final value of "counter" is 4