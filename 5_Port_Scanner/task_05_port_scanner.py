import socket
import time
from concurrent.futures import ThreadPoolExecutor, as_completed

ip = input("Target IP: ")
start = time.time()


def scan(port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(1)
    try:
        result = s.connect_ex((ip, port))
        if result == 0:
            return port
    except OSError:
        return None
    finally:
        s.close()


with ThreadPoolExecutor(max_workers=50) as executor:
    tasks = [executor.submit(scan, port) for port in range(1, 1025)]
    for task in as_completed(tasks):
        port = task.result()
        if port is not None:
            print("Open port:", port)

print("Total time:", round(time.time() - start, 2), "seconds")
