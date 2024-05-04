import os
import csv
import matplotlib.pyplot as plt
import pandas as pd

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
        writer.writerow(['Category', 'Algorithm', 'Expansions', 'Execution Time'])
        writer.writerows(data)

def plot_execution_time_by_algorithm(data_file, output_file_prefix):
    data = pd.read_csv(data_file)
    
    # Group data by 'Category' and 'Algorithm'
    grouped_data = data.groupby(['Category', 'Algorithm']).mean().reset_index()
    
    # Plotting for each difficulty level
    categories = ['easy', 'medium', 'hard']
    for category in categories:
        category_data = grouped_data[grouped_data['Category'] == category]
        
        plt.figure(figsize=(10, 6))
        plt.bar(category_data['Algorithm'], category_data['Execution Time'], color='blue')
        
        plt.xlabel('Algorithm')
        plt.ylabel('Execution Time (ms)')
        plt.title(f'Execution Time by Algorithm for {category.capitalize()} Difficulty')
        plt.xticks(rotation=0)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.savefig(f'{output_file_prefix}/{category}.png')
        
def plot_expansions_by_algorithm(data_file, output_file_prefix):
    data = pd.read_csv(data_file)
    
    # Group data by 'Category' and 'Algorithm'
    grouped_data = data.groupby(['Category', 'Algorithm']).mean().reset_index()
    
    # Plotting for each difficulty level
    categories = ['easy', 'medium', 'hard']
    for category in categories:
        category_data = grouped_data[grouped_data['Category'] == category]
        
        plt.figure(figsize=(10, 6))
        plt.bar(category_data['Algorithm'], category_data['Expansions'], color='blue')
        
        plt.xlabel('Algorithm')
        plt.ylabel('Expansions')
        plt.title(f'Expansions by Algorithm for {category.capitalize()} Difficulty')
        plt.xticks(rotation=0)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.savefig(f'{output_file_prefix}/{category}.png')

def plot_expansions_by_category(data_file, output_file_prefix):
    data = pd.read_csv(data_file)
    
    category_order = ['easy', 'medium', 'hard']
    
    # Group data by 'Category' and 'Algorithm'
    grouped_data = data.groupby(['Category', 'Algorithm']).mean().reset_index()
    
    # Plotting for each algorithm
    algorithms = ['B', 'I', 'U', 'G', 'A']
    for algorithm in algorithms:
        algorithm_data = grouped_data[grouped_data['Algorithm'] == algorithm]
        
        algorithm_data = algorithm_data.set_index('Category').reindex(category_order).reset_index()
        
        plt.figure(figsize=(10, 6))
        plt.bar(algorithm_data['Category'], algorithm_data['Expansions'], color='blue')
        
        plt.xlabel('Category')
        plt.ylabel('Expansions')
        plt.title(f'Expansions by Category for {algorithm.capitalize()}')
        plt.xticks(rotation=0)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.savefig(f'{output_file_prefix}/{algorithm}.png')
        
def plot_execution_time_by_category(data_file, output_file_prefix):
    data = pd.read_csv(data_file)
    
    category_order = ['easy', 'medium', 'hard']
    
    # Group data by 'Category' and 'Algorithm'
    grouped_data = data.groupby(['Category', 'Algorithm']).mean().reset_index()
    
    # Plotting for each algorithm
    algorithms = ['B', 'I', 'U', 'G', 'A']
    for algorithm in algorithms:
        # sort 'algorithm_data' to the order ['easy', 'medium', 'hard']
        algorithm_data = grouped_data[grouped_data['Algorithm'] == algorithm]
        
        algorithm_data = algorithm_data.set_index('Category').reindex(category_order).reset_index()
        
        plt.figure(figsize=(10, 6))
        plt.bar(algorithm_data['Category'], algorithm_data['Execution Time'], color='blue')
        
        plt.xlabel('Category')
        plt.ylabel('Execution Time (ms)')
        plt.title(f'Execution Time by Category for {algorithm.capitalize()}')
        plt.xticks(rotation=0)
        plt.grid(axis='y')
        plt.tight_layout()
        plt.savefig(f'{output_file_prefix}/{algorithm}.png')

def main():
    directory = 'test'
    data_file = f'{directory}/data.csv'
    data = process_directory(directory)
    write_to_csv(data, data_file)
    print(f"Data has been written to '{data_file}'")

    plot_execution_time_by_algorithm(data_file, "test/plots/exec_time_by_algo")
    plot_execution_time_by_category(data_file, "test/plots/execution_time_by_category")
    plot_expansions_by_algorithm(data_file, "test/plots/expansions_by_algo")
    plot_expansions_by_category(data_file, "test/plots/expansions_by_category")

if __name__ == "__main__":
    main()
