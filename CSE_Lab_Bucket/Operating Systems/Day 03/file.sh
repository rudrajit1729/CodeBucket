filename=$1
if [ -f $filename ];
then
	echo "$(ls -la $filename | head -c 10)"
else
	touch "$filename"
	echo "created"
	echo "$(ls -la $filename | head -c 10)"
	
fi

# output 
# ~$ sh file.sh rudy.txt
# created
# -rw-r--r--
# ~$ sh file.sh rudy.txt
# -rw-r--r--