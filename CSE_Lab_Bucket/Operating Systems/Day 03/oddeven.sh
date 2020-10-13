read -p "Enter a number: " num

if [ $((num%2)) -eq 0 ];
then
	echo "Even Number"
else
	echo "Odd Number"
fi

# Output
# ~$ sh oddeven.sh
# Enter a number: 3
# Odd Number
# ~$ sh oddeven.sh
# Enter a number: 6
# Even Number