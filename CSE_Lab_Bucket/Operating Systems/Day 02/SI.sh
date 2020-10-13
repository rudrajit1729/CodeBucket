echo "Enter principal amt : "
read P
echo "Enter rate of interest : "
read R
echo "Enter time in years : "
read T

interest=`expr $P \* $R \* $T / 100`

echo "Interest on $P at $R % per annum after $T years = $interest"

# Output 
# sh SI.sh
# Enter principal amt :
# 100
# Enter rate of interest :
# 10
# Enter time in years :
# 2
# Interest on 100 at 10 % per annum after 2 years = 20