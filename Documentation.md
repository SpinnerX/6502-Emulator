## CPU Process


# Fetch, Decode, Execute Cycle
## Fetch
1. Using Program counter to fetch data in memory
2. Storing data in to the IR (instruction register)

## Decode
1. From fetching data in memory, we use that data during the decoding phase
2. During the decoding phase we get the opcode to know which instruction to execute
3. Opcodes give us the idea of knowing which instruction with which address mode to execute


## Execute
1. Executing the operation
2. Considering the address mode, to indicate when to add additional cycles.
3. Once the execution phase is done, then we reset()


## reset()
What reset does, is let the CPU reset to a known state. In other words,
have the values be resetted to run specific instructions, and the cpu continues to run,
until otherwise.



## Code Overview
CPUConfigs.h
1. Config struct contains the main registers used throughout the CPU
2. Using this struct to basically pass objects around the CPU
3. Reusing the variables across the CPU, storing and loading data
4. Data that are being passed, and resetted depending on the instruction.


InstructionSet.h
1. Contains BaseInstruction allowing C++ to know Instruction that is a template to be a type
2. Instruction needs to have a default type, therefore we use BaseInstruction to note that.
3. Instruction inherits BaseInstruction because we can prevent object splicing by using ptrs.
4. Where 