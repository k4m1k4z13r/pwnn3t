#!/usr/bin/bash

# Author - k4m1k4z13r
# Copyright - Copy what you can

echo "----------------------------------"  >> recon.txt 
echo "Taking it for granted that you've set up pls and bangrab...." | tee >> recon.txt

echo "it's happening";
echo "Starting to scan all alive hosts on the network you're connected to" | tee >> recon.txt
for ip0 in $(seq 0 255)
do
	for ip1 in $(seq 0 255)
	do
		for ip2 in $(seq 0 255)
		do
			## TODO : ping broadcast (using -b)
			for ip3 in $(seq 0 255)
			do
				ip="$ip0.$ip1.$ip2.$ip3"
				ping -c 1 $ip -W 3 > /dev/null
				if [ $? = 0 ]
				then 
					echo "$ip was UP" | tee >> recon.txt
					echo "Port scanning host $ip" | tee >> recon.txt
					./pls $ip0.$ip1.$ip2.$ip3 | tee recon.txt
					echo "Banner grabbing host $ip"| tee >> recon.txt
					./bangrab $ip | tee recon.txt
				fi
			done
		done
	done
done
