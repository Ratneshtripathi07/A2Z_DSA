import datetime
import os

# Today's date
today = datetime.date.today().strftime("%Y-%m-%d")
entry = f"{today} ✅"

# Path to README.md
readme_file = "README.md"

# Check if README exists
if not os.path.exists(readme_file):
    with open(readme_file, "w") as f:
        f.write("# DSA Progress\n")

# Append date if not already present
with open(readme_file, "r+") as f:
    content = f.read()
    if entry not in content:
        f.write(f"\n{entry}")
        print(f"Added {entry}")
    else:
        print(f"{entry} already exists. No update needed.")
