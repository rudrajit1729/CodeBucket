read -p "Enter text: " text
lb=`echo $text | wc -c`
lb=`expr $lb - 1`
read -p "Enter sub string: " sub
ub=`echo $sub | wc -c`
ub=`expr $ub - 1`
n=1
m=1
pos=0
while [ $n -le $lb ]
do
	a=`echo $text | cut -c $n`
	b=`echo $sub | cut -c $m`
	if [ $a = $b ]
	then
	n=`expr $n + 1`
	m=`expr $m + 1`
	pos=`expr $n - $ub`
	r=`expr $m - 1`
	if [ $r -eq $ub ]
	then
	break
	fi
	else
	pos=0
	m=1
	n=`expr $n + 1`
	fi
done

echo "Substring Position in String = "  $pos

# Output
# ~$ bash p1.sh
# Enter text: Rudrajit Choudhuri
# Enter sub string: raj
# Substring Position in String =  4