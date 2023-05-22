#!/bin/bash
c_files=$(ls *.c 2>/dev/null)

if [ -z "$c_files" ]; then
  echo "No .c files found in the current directory."
  exit 1
fi

gcc -shared -o liball.so $c_files
exit_code=$?

if [ $exit_code -eq 0 ]; then
  echo "Dynamic library liball.so created successfully."
else
  echo "Failed to create the dynamic library."
fi
