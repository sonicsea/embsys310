/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for square
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
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
Function Name   : swapCharsAsm
Description     : swap 2 variable of char data type
C Prototype     : int swapCharsAsm(val1, val2)
                : Where val1 and val2 are the values to be swapped
Parameters      : R0: char val1, R1 char val2
Return value    : R0: char val2, R1 char val1
*******************************************************************************/  
  
swapCharsAsm
    PUSH {LR}        // save the input argument and return address
    LDR R4, [R0]     // save value at R0 to R4
    LDR R5, [R1]     // save value at R1 to R5
    STR R4, [R1]     // store value in R4 to address at R1
    STR R5, [R0]     // store value in R5 to address at R0
    POP {LR}         // LR
    BX LR            // return (with function result in R0, R1)

    END
