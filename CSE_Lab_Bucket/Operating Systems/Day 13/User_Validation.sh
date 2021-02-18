result=$(grep -c "$1" /etc/passwd)
if [ $result -eq 1 ]
then
        echo "User exists"
else
        echo "User does not exist"
fi

# # Output: 
# # rudrajit1729@DESKTOP-22VPBBI:$ sh User_Validation.sh rudrajit1729
# # User exists