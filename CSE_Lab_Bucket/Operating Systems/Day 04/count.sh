read -p "Enter string: " str
c=`echo $str | wc -c`
c=`expr $c - 1`
w=`echo $str | wc -w`
w=`expr $w`
wsp=0
a=0
sp=\` \`
n=1
while [ $n -le $c ]
do
    ch=`echo $str | cut -c $n`
    if [ $ch ==  $sp ]
    then
        wsp=`expr $wsp + 1`
    else
        case $ch in
            [a-z]|[A-Z]) a=`expr $a + 1`;;
    esac
    fi
    n=`expr $n + 1`
done

spec=`expr $c - $wsp - $a`
echo chars=$c
echo spaces=$wsp
echo spec symbols=$spec
echo words=$w

# Output
# sh count.sh
# Enter string: Rudy Ch
# chars=7
# spaces=1
# spec symbols=0
# words=2 