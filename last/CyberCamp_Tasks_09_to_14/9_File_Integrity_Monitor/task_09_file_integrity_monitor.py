import hashlib
import time

file_name = input("File to monitor: ")


def get_hash(file_name):
    h = hashlib.sha256()
    with open(file_name, "rb") as f:
        data = f.read(4096)
        while data:
            h.update(data)
            data = f.read(4096)
    return h.hexdigest()


old_hash = get_hash(file_name)
print("Monitoring file:", file_name)

while True:
    time.sleep(3)
    new_hash = get_hash(file_name)
    if new_hash != old_hash:
        print("Critical Alert: File has changed")
        old_hash = new_hash
