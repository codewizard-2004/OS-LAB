#!/bin/bash

# Initialize the sum to 0
sum=0

# Loop through each argument
for num in "$@"; do
  sum=$((sum + num))  # Add each argument to sum
done

echo "The sum of the numbers is: $sum"
