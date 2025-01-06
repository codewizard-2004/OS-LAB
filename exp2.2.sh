#!/bin/bash

# Prompt the user for a number
echo "Enter a number:"
read num

# Initialize the factorial variable to 1
factorial=1

# Calculate factorial using a for loop
for (( i=1; i<=num; i++ ))
do
  factorial=$((factorial * i))
done

# Output the result
echo "Factorial of $num is $factorial"
