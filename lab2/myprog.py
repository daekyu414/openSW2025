import os

# print(os.environ)

n_gpus = int(os.environ.get('N_GPUS', 0))

for i in range(n_gpus):
    print(f"Launching GPU # {i}")