read -p "Enter 1st number: " n1
read -p "Enter 2nd number: " n2
read -p "Enter 3rd number: " n3

for i in $n1 $n2 $n3
do
	for j in $n1 $n2 $n3
	do
		for k in $n1 $n2 $n3
		do
		echo $i $j $k
		done
	done
done

'''
Output
~$ sh p3.sh
Enter 1st number: 4
Enter 2nd number: 8
Enter 3rd number: 1
4 4 4
4 4 8
4 4 1
4 8 4
4 8 8
4 8 1
4 1 4
4 1 8
4 1 1
8 4 4
8 4 8
8 4 1
8 8 4
8 8 8
8 8 1
8 1 4
8 1 8
8 1 1
1 4 4
1 4 8
1 4 1
1 8 4
1 8 8
1 8 1
1 1 4
1 1 8
1 1 1
'''