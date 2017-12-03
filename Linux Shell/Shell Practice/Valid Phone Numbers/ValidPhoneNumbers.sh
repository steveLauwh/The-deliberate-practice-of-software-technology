# Read from the file file.txt and output all valid phone numbers to stdout.
#!bin/bash

#awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

sed -n '/^\([0-9]\{3\}-\|([0-9]\{3\}) \)[0-9]\{3\}-[0-9]\{4\}$/p' file.txt
