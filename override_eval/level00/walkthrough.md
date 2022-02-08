Program behavior:
1. Reads from stdin to a variable (input) using `scanf` function;
2. Opens a shell if the input is right.

Solution:
Use GDB to inspect the number.

# Launch the debugger
gdb level00
# Inspect main function
disassemble main
`0x080484e7 <+83>:    cmp    $0x149c,%eax`
# Convert to digit
print/d 0x149c
`$1 = 5276`
# Quit the debugger
quit
# Use the right number
(python -c 'print 5276'; cat) | ./level00
# Check the flag
cat /home/users/level01/.pass
`uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL`
