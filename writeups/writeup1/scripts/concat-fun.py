import sys
import os
import re

def extract_file_number(line):
    match = re.search(r'//file(\d+)', line)
    return int(match.group(1)) if match else None

def concat_files(directory, output_file):
    files_with_numbers = []
    
    for root, _, files in os.walk(directory):
        for file in files:
            if ".pcap" not in file:
                continue
            file_path = os.path.join(root, file)
            try:
                with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                    lines = f.readlines()
                    if lines and (file_number := extract_file_number(lines[-1])) is not None:
                        files_with_numbers.append((file_number, file_path))
            except Exception as e:
                print(f"Error reading {file_path}: {e}", file=sys.stderr)
    
    files_with_numbers.sort()  # Sort by file number
    
    with open(output_file, 'w', encoding='utf-8') as out_f:
        for _, file_path in files_with_numbers:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                out_f.writelines(f.readlines())
            out_f.write('\n')  # Ensure separation between files
    
    print(f"Concatenation complete. Output saved to {output_file}")

if __name__ == "__main__":
    directory = sys.argv[1] if len(sys.argv) > 1 else 'ft_fun'
    output_file = sys.argv[2] if len(sys.argv) > 2 else 'output.c'
    concat_files(directory, output_file)
