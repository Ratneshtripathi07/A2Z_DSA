import datetime
import os

# Today's date
today = datetime.date.today().strftime("%Y-%m-%d")
entry = f"----------------------------------------\n\n{today} ✅\n\n----------------------------------------"

# Path to README.md
readme_file = "README.md"

# Check if README exists
if not os.path.exists(readme_file):
    with open(readme_file, "w") as f:
        f.write("# DSA Progress\n\n")

# Append entry if today's date not already present
with open(readme_file, "r+") as f:
    content = f.read()
    if today not in content:
        f.write(f"\n{entry}\n")
        print(f"Added entry for {today}")
    else:
        print(f"Entry for {today} already exists. No update needed.")
