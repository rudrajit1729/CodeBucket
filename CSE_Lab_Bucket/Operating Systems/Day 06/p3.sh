read -p "Enter String :" str
read -p "Enter Search Character :" ch
len=`expr ${#str} - 1`
i=1
ans=0
pos=0
while [ $i -le $len ]
do
	chr=`echo $str | cut -c $i`
	if [ "$chr" = "$ch" ]
	then
		ans=`expr $ans + 1`
	fi
	i=`expr $i + 1`
done
echo "No. of '$ch' occurence in text = $ans"

'''
Output
sh p3.sh
Enter String :hello
Enter Search Character :l
No. of 'l' occurence in text = 2
'''