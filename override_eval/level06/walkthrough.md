Program behavior:
1. Reads from stdin to a buffer (username) using `fgets` function;
2. Reads from stdin to a variable (serial) using `scanf` function;
3. Checks with `ptrace` if the program is launched by another process;
4. Uses some complex hashing algorithm on username;
5. Opens a new shell if serial and hash are equal.

Solution:
Get a computed hash number using GDB.

# Launch the debugger
gdb level06
# Disassemble auth
disassemble auth
`0x08048866 <+286>:   cmp    -0x10(%ebp),%eax`
`0x08048869 <+289>:   je     0x8048872 <auth+298>`
# Set a breakpoint on ptrace function
break ptrace
# Set a breakpoint on comparison insturction
break *0x08048869
# Start the debugged program
run < <(python -c 'print("username\n" + "42")')
# Step program
step
# Change the result of ptrace function
set $eax = 0
# Step program
step
# Examine hash value
x/d $ebp-0x10
`0xffffd658:     6234463`
# Quit the debugger
quit
# Authenticate with the right serial
(python -c 'print("username\n" + "6234463\n")'; cat) | ./level06
# Check the flag
cat /home/users/level07/.pass
`GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8`
