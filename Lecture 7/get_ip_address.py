import socket

hostname = socket.gethostname()
IPAddr = socket.gethostbyname(hostname)

print("Computer name is ", hostname)
print("IP address is ", IPAddr)


IPAddr = socket.gethostbyname('aws.amazon.com')
print("IP address of Amazon AWS is ", IPAddr)