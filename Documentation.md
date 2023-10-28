# Overview 6502 8-bit CPU Processor Emulator

### CPU Process Fetch, Decode, Execute cycle
6502 CPU Process Boot Process \
  1.1.) Bootup and Fetching \
    - Once 6502 cpu is initialized during boot up phase \
    - CPU fetches the reset vector, stack, and program counter in memory \
    - There are different regions of memory, RAM, ROM, and any external devices (if connected) \
    - Fetching memory from RAM and ROM. \
  1.2.) Decoding \
    - During decoding is a phase where the CPU, evaluates which instruction to execute \
    - To decode to know which instruction to execute, use the opcodes. \ 
    - Using opcodes to evaluate instructions to execute, and know the address modes. \
    - Address modes are initially how we allow accessing data from internal RAM \
    - Address modes are for specifying memory locations, allowing efficient access to variables or data arrays. \
    Example: LDA loads the accumulator to Memory. \
  1.3.) Executing Instructions \
    - After fetching, and decoding instructions the CPU processor would use its ALU. \
    - Using ALU to perform an operation, then to store that in memory. \
    - Executing depends on instruction, such as to load/store memory \
    - Loading values in memory and then does the operation before storing the output back into memory again




### 6502 CPU Emulator Design Choice
** Going over design choices when and during implementing the emulator, as to why I implemented it the way I did.
** Also going over mistakes in previous designs, that led to the design choices that is there now.

1.) Class Design
  1.1.) Implementing the registers and other instructions during the design decision making
    - When developing the registers, I wanted to hahve a way of accessing these registers with a known ID.
    - I was looking at the ID wrong at the start when implementing the registers, and tried to have an enum as templated types
    - Including declaring std::unordered_map to type opcode_t as the key, and Register<EnumType> as the value, which is not an actual type.
    - Therefore went withh using a lambda functions that returns the BaseRegister pointer.
  1.2.) Creating Register and BaseRegister
    ** BaseRegister **
    - Before implementing the Register class, I created BaseRegister class
    - BaseRegister acts as a base class containing necessary information about how the registers would work.
    - Involving functions that'll be used, member variables that'll be accessed. To help prevent recreating the same variables.
    - At least multiple instances of those variables
    - A discovery I made, was I needed these to be a type due to object splicing we are allowed to have a pointer of based class \
      and whhen we pass in the subclass we
    ** Register **
    - Implementing register class as a specialized templated class inheriting from BaseRegister
    - Reason for this is because we need the templated class to be an actual type
    - Also instead of copy and pasting the same member variables and functions we inherit from a single source that already contains those variables
    - BaseRegister contains information about execution, RegisterTraits, InstructionStatuses, etc.
    - RegisterTriats simply containing information about Address Mode, size of bytes, cycles, and contains opcode of the instruction we want to run.