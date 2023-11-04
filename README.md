# 6502 8-bit CPU Processor

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
`CPUConfigs.h`
1. Config struct contains the main registers used throughout the CPU
2. Using this struct to basically pass objects around the CPU
3. Reusing the variables across the CPU, storing and loading data
4. Data that are being passed, and resetted depending on the instruction.
5. Also contains the status flags that are used for the instructions
6. This is so I can know how to call these status flags when, we need to modify those bitfields.

`InstructionData`
1. Struct InstructionData is basically containing the opcodes, name of instruction, and address mode
2. This way of having a way to organize our data flow
3. Having a system for sending data throughout the CPU
4. Since these are common things for each instruction to have, we will have a few ways of retrieiving different information using InstructionData.
5. InstructionData also makes it convenient to have our data for these instructions and how they can be stored.

`InstructionSet.h`
1. Contains BaseInstruction allowing C++ to know Instruction that is a template to be a type
2. Instruction needs to have a default type, therefore we use BaseInstruction to note that.
3. Instruction inherits BaseInstruction because we can prevent object splicing by using ptrs.
4. Instruction templated class is what allows us to differentiate which instruction to run
5. Since opcodes are notedly how we know which instruction and address mode are based on the opcode we pass.
6. Templated class allows for a more generic way of having one generic thing that can basically do what it needs to do.

`CPU.h`
1. run() - is the function call to simply start running the CPU.
2. fetch() - returns the data we are reading from memory (essentially just fetches data in memory)
3. decode() - returns BaseInstruction pointer that searches using thhe opcodes we extract from fetching process
4. executeInstruction(BaseInstruction*) - is what executes our instructions after the fetching and decoding phase
5.  Once the loop finishes we reset the information back to a known state.
NOTE: Another thing to consider, is hhaving a way for the CPU to know when the go into a quitting state, or knowing when to go to specific states.
