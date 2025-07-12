#Introduction

The command required to generate firstprog_asm.txt is:

$ objdump -M intel -D firstprog | grep -A20 main.: > firstprog_asm.txt

For extra familiarity with objdump run 'man objdump'

The second tool I will be using here is the GNU debugger(gdb), which will be useful to step through compiled programs, examine program memory, and view processor registers. To replicate the results contained in firstprog_asm.txt using gdb, run:

$ gdb -q ./firstprog

gdb man page has more details on how on use the GNU debugger.  In this section I will highlight some of the basic commands and their use. PS, I have configured my gdb to use Intel disassembly syntax using the command:

$ echo "set disassembly" > ~/.gdbinit

# Assembly Language

- To generate the assembly code for our compiled binaries, run:

(gdb) disassemble main

- The assembly instructions in Intel syntax generally  follow this style:

   operation <destination> <source>

- The destination and source values will either be a rtegister, a memory address, or a value.

- To understand how computer memory is organized, we will use gdb  to examine the individual registers while pausing  program execution at certain points using gdb.
- Effectively, I am going to include basic gdb commands and then discuss the output.
- Computer memory is like a row of houses on a local street, each with its own address( a row of bytes, each with its own memory address).
- The CPU which is effectively the brain of a computer accesses the memory in a given address to retrieve the machine language instructions that make up the compiled program.

#Registers.

- CPUs/Processors have a special set of variables called registers. Most of the machine language instructions use these registers to read or write data.

- Registers are divided into three categories:
1. General purpose registers
 - EAX, EBX, ECX, EDX - (Accumulator, Base, Counter and Data)
 - They act as temporary variables for the CPU when it is executing machine instructions.

2. Pointers and Indexes.
   - ESP, EBP, ESI, EDI - (Stack Pointer, Base Pointer, Source Index, Destination Index)
   -  The first two point to locations in memory.
   - The latter point to source and destination when data needs to be read or written to.
3. EFLAGS - Consist of bit flags that are used for comparisons and memory segmentations.
- Not fundamentally accessible directly.

4. EIP register is the Instruction Pointer register which points to the current instruction the processor is reading.


# Operations in assembly:
* mov - move from source to destination
* inc- increment
* sub - subtract
* cmp - compare values
* jle(jump if less than or equal to)
* jmp - unconditional jump

<img src="disassemble.png" alt="terminal screenshot" style="width: 300px; height: 200px;">

































































































































