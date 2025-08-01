## Memory Segmentation

- A compiled program's memory is divided into 5 segments:
  1. text/code segment
  2. data segment
  3. bss
  4. Heap
  5. Stack

# Text/code segment

- Stores assembled macchine instructions.
- EIP register is set to the first instruction in the text segment.
- The instructions are executed non linearly.
- And here's how the processor's execution loop looks like:
1. Reads the instruction EIP is pointing to.
2. Adds the byte length of instruction to EIP
3. Executes the instructions that was read in 1
4. Returns to 1

- This segment has no write permissions and takes on a fixed memory size as a result.

# Data and Bss segments

- The data segment is used to store gloabal and static variables, which by default ought to be initialized.
- Uninitialised variables are stored in the bss segment.
- These segments are writeable but tend to have fixed sizes.
- It is worth noting that global variables persist  since they are stored in their own memory segments.

# Heap Segment

- This is the segment which the programmer has direct access and control over.
- It is not fixed in size and hence can grow or shrink based on the requirements.
- the heap grows upwards towards higher memory addresses.

# Stack segment

- Has a variable size.
- Temporarily stores local variables, and context during function calls.
- the stack recalls/remembers:
  1. all passed variables.
  2. the location EIP should return to after the function execution is completed.
  3. Alll local variables used by the function. Collectively, these functions are effectively a stack frame.

- The stack also refers to a LIFO data structure
- It's operations are popping and pushing which respectively are removing and adding to the stack.

- ESP tracks the address of the end of stack which changes as the stack grows or shrinks.
- The stack grows towards lower memory addresses unlike the heap.

- The EBp(frame pointer(FP) or the local base pointer) marks the start of a stackframe, as an address.

# Contents of a stackframe.

1. Function parameters
2. local variables
3. Two pointers necessary to put things back as they were:
    1. the saved frame pointers(SFP)
       -Restores EBP to its previous value.
    3. Return address(restore EIP to the next instruction after function call)


# Procedure prologue or function prologue
- Sets up the stackframe.
- Save the frame pointer on the stack.
- save stack memory for local function variables.
- Handles stack alignment sometime.

- Values or functions are pushed to the stack in reverse order. For example int func_test(int a, int b, int c) willed pushed in the following order: c, b, a.