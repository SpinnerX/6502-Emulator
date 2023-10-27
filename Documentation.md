# Overview 6502 8-bit CPU Processor Emulator

### CPU Process Fetch, Decode, Execute cycle
1.) 6502 CPU Process Boot Process \
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
2.
