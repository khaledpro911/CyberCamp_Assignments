import re

file_name = input("Log file: ")
patterns = {
    "SQL Injection": re.compile(r"UNION\s+SELECT", re.IGNORECASE),
    "Path Traversal": re.compile(r"\.\./etc/passwd", re.IGNORECASE)
}
counts = {"SQL Injection": 0, "Path Traversal": 0}
total = 0

with open(file_name, "r", errors="ignore") as f:
    for line_num, line in enumerate(f, 1):
        ip = line.split()[0] if line.split() else "Unknown"
        for name, pattern in patterns.items():
            if re.search(pattern, line):
                print("Alert:", name, "at line", line_num, "from IP", ip)
                counts[name] += 1
                total += 1

print("Total attacks:", total)
for name, count in counts.items():
    print(name + ":", count)
