read -p "Enter no. of integers: " n
i=0
max=0
min=9999
echo 'Enter the numbers: '
while [ $i -lt $n ]
do
	read a
	if [ $a -gt $max ]
	then
		max=$a
	fi
	if [ $a -lt $min ]
	then
		min=$a
	fi
	i=`expr $i + 1`
done
echo "Max = $max"
echo "Min = $min"

'''
Output
~$ sh p1.sh
Enter no. of integers: 4
Enter the numbers: 
40 
30
2 
9
Max = 40
Min = 2
'''