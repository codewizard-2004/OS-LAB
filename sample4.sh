#!/bin/bash

# Prompt user for input
echo "Enter the first number:"
read num1

echo "Enter the second number:"
read num2

# Check if the second number is zero to avoid division by zero error
if [ $num2 -eq 0 ]; then
  echo "Error: Division by zero is not allowed."
else
  # Perform division
  division_result=$((num1 / num2))
  echo "The result of $num1 divided by $num2 is: $division_result"
fi
