import os
import sys

def find_getme_next_line(directory):
    for root, _, files in os.walk(directory):
        for file in files:
            if ".pcap" in file:
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        prev_line = None
                        for line in f:
                            if prev_line and "getme" in prev_line:
                                print(f"{file_path}: {line.strip()}")
                            prev_line = line
                except Exception as e:
                    print(f"Error reading {file_path}: {e}", file=sys.stderr)

if __name__ == "__main__":
    directory = sys.argv[1] if len(sys.argv) > 1 else '.'
    find_getme_next_line(directory)

