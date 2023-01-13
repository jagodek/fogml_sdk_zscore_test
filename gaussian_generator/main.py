import numpy as np

FILE_NAME = "../data.txt"
VECTOR_SIZE = 12

def generate_gaussian():
    return np.random.normal(size=VECTOR_SIZE).round(2)

def generate_anomaly():
    return np.random.uniform(4, 5, VECTOR_SIZE).round(2)

def save_to_file(file, values):
    for value in values:
        file.write(f'{value} ')
    file.write('\n')

with open(FILE_NAME, 'w') as f:
    for _ in range(10): save_to_file(f, generate_gaussian())
    for _ in range(5): save_to_file(f, generate_anomaly())
    for _ in range(5): save_to_file(f, generate_gaussian())