read -p "Enter String: " S;
R=""
for (( i=0; i<${#S}; i++ ));
do
	R="${S:$i:1}$R" ;
done

[ "$S" = "$R" ] && echo "Palindrome" || echo "Not Palindrome";
# Output
# bash p1.sh
# Enter String: madam
# Palindrome
# bash p1.sh
# Enter String: telengana
# Not Palindrome