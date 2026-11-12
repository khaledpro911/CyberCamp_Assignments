import secrets
import string
import hashlib

chars = string.ascii_letters + string.digits + string.punctuation
password = "".join(secrets.choice(chars) for i in range(16))
hash_value = hashlib.sha256(password.encode()).hexdigest()

print("Password:", password)
print("SHA-256:", hash_value)
