#!/bin/bash

# Ask for the number to start the countdown
echo "Enter a number to start the countdown:"
read num

# Loop to count down
while [ $num -ge 0 ]; do
  echo $num
  ((num--))  # Decrease the number by 1
  sleep 1    # Pause for 1 second
done

echo "Countdown finished!"
