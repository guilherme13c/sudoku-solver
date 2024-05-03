import os
import csv
import matplotlib.pyplot as plt

def parse_txt_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        expansions, execution_time = map(int, lines[0].strip().split())
        return expansions, execution_time

def process_directory(directory):
    data = []
    for subdir, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.txt'):
                subdir_name = os.path.basename(subdir)
                file_path = os.path.join(subdir, file)
                expansions, execution_time = parse_txt_file(file_path)
                data.append([subdir_name, file[:-4], expansions, execution_time])
    return data

def write_to_csv(data, output_file):
    with open(output_file, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Category', 'File', 'Expansions', 'Execution Time'])
        writer.writerows(data)

def main():
    directory = 'test'
    output_file = f'{directory}/data.csv'
    data = process_directory(directory)
    write_to_csv(data, output_file)
    print(f"Data has been written to '{output_file}'")
    
    # TODO: plot the data

if __name__ == "__main__":
    main()
