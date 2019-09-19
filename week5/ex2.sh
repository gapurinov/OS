ans=0
while :
do
	ans=$(( ans+1 ))
	if [ $ans -eq 500 ];
	then
		break
	fi
	ln ex2.txt ex2.lock
	num=$(tail -n 1 ex2.txt)
	num=$(( num+1 ))
	echo $num >> ex2.txt
	rm ex2.lock
done