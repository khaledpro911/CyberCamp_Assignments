import socket

ip = input("Target IP: ")
port = int(input("Port: "))
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(3)

try:
    s.connect((ip, port))
    if port == 80:
        s.sendall(b"HEAD / HTTP/1.1\r\n\r\n")
    data = s.recv(1024)
    banner = data.decode('utf-8', errors='ignore').strip()
    if banner:
        print(banner.splitlines()[0])
    else:
        print("No banner received")
except socket.timeout:
    print("Connection timed out")
except OSError:
    print("Could not connect")
finally:
    s.close()
