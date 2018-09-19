for i in {1..100}
do 
	while ! ln in.txt in.txt.lock
	do
		sleep 1
	done
	
	line=$(tail -n 1 in.txt)
	echo "$(($line+1))">>in.txt 

	rm -f in.txt.lock
done