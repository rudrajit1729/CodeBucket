read -p "Enter 1st number : " a
read -p "Enter 2nd number : " b

if [ $a -gt $b ];
then
	echo "First number $a is greatest"
else
	echo "Second number $b is greatest"
fi

# Output
# sh max.sh
# Enter 1st number : 3
# Enter 2nd number : 9
# Second number 9 is greatest