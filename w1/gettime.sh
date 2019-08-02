#!/bin/sh

# Here's some shell commands to get you started on automating your data
# collection for task 2, as it's quite tedious to do manually. There's some missing bits here,
# namely how to integrate this into a shell script that will loop over all your
# cases. However, that's left as an exercise to the reader :). Hint: You can
# mimic the shell script given to you in the lab spec.

# BIG NOTE: SHELL SCRIPTS AREN'T ASSESSABLE! This is some extension material
# that I find useful irl. To learn more about shell scripts and the wonderful
# world of software tooling and making your life easier, enrol in COMP2041 :)

# (1) Run your command and direct both stdout and stderr to stdout for further
# processing down the pipeling.
# (2) Find the line which has the "user" time and push down the pipeling
# (3) Regex for stripping the minutes and the seconds of the user time
curr_user_time=`(time seq 100000) 2>&1 | egrep "user" | egrep -o "\d+m\d+\.\d+"`
# ^ NOTE: the call (time seq 10000) should be replaced with the ./useIntList or
# sort -n sorting commands found in the lab specification (the commands you want
# to time)

# Split our time by the char 'm'. The first element will be num_mins (int)
num_mins=`echo "$curr_user_time" | cut -dm -f1`

# As above, get the second element which corresponds to num_secs (float)
num_secs=`echo "$curr_user_time" | cut -dm -f2`

# Compute the total number of seconds that the operation took to complete.
total_secs=`echo "$num_mins * 60 + $num_secs" | bc`

# to do floating point division, we can defer the command to bc
# (suppose we did 3 trials here, to 2 decimal places)
division_example=`echo "scale=2; $total_secs/3" | bc`

# Print the state of all the values
echo "time: $curr_user_time"
echo "num_mins: $num_mins"
echo "num_secs: $num_secs"
echo "total_secs: $total_secs"
echo "division_example: $division_example"
