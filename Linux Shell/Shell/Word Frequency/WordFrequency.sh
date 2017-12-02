# Read from the file words.txt and output the word frequency list to stdout.
#!bin/bash

grep -oE '[a-z]+' words.txt | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
