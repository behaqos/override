Program behavior:
1. Reads from stdin to a variable (input) using `scanf` function;
2. Subtracts the input number from 0x1337d00d;
3. Uses the result as XOR key to decrypt initial passphrase (Q}|u`sfg~sf{}|a3);
4. Opens a shell if the decrypted string is equal to "Congratulations!".

Solution:
If A ^ B = C then A ^ C = B. Calculate the right key.

# Calculate the key
print 'C' ^ 'Q'
`$1 = 18`
# Inject the right integer
(python -c 'print 0x1337d00d - 18'; cat) | ./level03
# Check the flag
cat /home/users/level04/.pass
`kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf`
