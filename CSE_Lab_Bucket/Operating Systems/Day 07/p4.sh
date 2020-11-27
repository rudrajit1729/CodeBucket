if [ $# -lt 3 ];
then
	echo "Insufficient parameters";
	exit;
fi	

n=$1

if ! [[ $n =~ ^-?[a-fA-F0-9]+$ ]];
then
	echo "Invalid number!";
	exit;
fi

ib=$2

if ! [[ $ib =~ ^-?[0-9]+$ ]];
then
	echo "Invalid input base";
	exit;
fi

ob=$3
if ! [[ $ob =~ ^-?[0-9]+$ ]];
then
	echo "Invalid output base";
	exit;
fi

n="` echo $n | tr [:lower:] [:upper:] `"

if [ $ib -lt 2 ] || [ $ib -gt 16 ]; 
then
	echo "Input base out of bounds";
	exit;
fi

if [ $ob -lt 2 ] || [ $ob -gt 16 ]; 
then
	echo "Output base out of bounds";
	exit;
fi
	
for (( i=0; i<${#n}; i++ ));
do
	dig="${n:$i:1}";	
	
	if [[ $dig =~ ^-?[a-fA-F0-9]+$ ]] 2> /dev/null;
	then
		dig="obase=10; ibase=$ib; "$dig"";
		dig="` echo $dig| bc `"
		if [ $dig -gt $ib ] 2> /dev/null;
		then
			echo "Digit in the number > input base ";
			exit;
		fi	
	fi
done


a="obase="$ob"; ibase="$ib"; $n"
echo $a|bc

# Output
#  bash p4.sh 10 10 2
# 1010
# ~$ bash p4.sh 1011 2 10
# 11
# ~$ bash p4.sh 11 10 8
# 13
# ~$ bash p4.sh 13 8 10
# 11
# ~$ bash p4.sh 13 10 16
# D
# ~$ bash p4.sh F 16 10
# 15
# ~$ bash p4.sh
# Insufficient params
# ~$ bash p4.sh 11 17 20
# Input base out of bounds