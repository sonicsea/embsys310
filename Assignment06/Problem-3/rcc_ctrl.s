/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC enable_rcc        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/  

// Bitband address calculation formula
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;

enable_rcc
    PUSH {R0, LR}       // save input argument and return address
    MOVW R1, #0x0000    // move wide of 0x42000000 into R1
    MOVT R1, #0x4200    // move top of 0x42000000 into R1
    MOVW R2, #0x104C    // move wide of 0x2104C into R2
    MOVT R2, #0x0002    // move top of 0x2104C into R2
    MOV R3, #32         // move number 32 into R3
    MUL R2, R2, R3      // multiple R2 and R3, store the result in R2
    ADD R1, R1, R2      // add R1 and R2, store the result in R1
    MOV R3, #4          // move number 4 into R3
    MUL R2, R0, R3      // multiple R0 and R3, store the result in R2
    ADD R1, R1, R2      // add R1 and R2, store the result in R1
    MOV R0, #0x1        // move number 0x1 into R0
    STR R0, [R1]        // store value of R0 to address at R1
    POP {R0, LR}        // restore R0 and LR
    BX LR               // return
    
    END
