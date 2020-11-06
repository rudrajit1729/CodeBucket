read -p "Enter number of terms: " n
a=0
b=1
c=0
x=0
while [ $c -le $n ]
do
	c=`expr $a + $b`
	a=$b
	b=$c
	d=`expr $a + $b`
	x=`expr $c + 1`
	while [ $x -lt $d ]
	do
		if [ $x -le $n ]
		then
			echo $x
		else
			break
		fi
		x=`expr $x + 1`
	done
done

'''
Output
sh p3.sh
Enter number of terms: 10
4
6
7
9
10
'''