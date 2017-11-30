# Read from the file file.txt and output the tenth line to stdout.
#!/bin/bash
sed -n 10p file.txt
# awk 'NR == 10' file.txt
