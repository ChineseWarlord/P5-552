import time
import multiprocessing as mproc
import os
from parallel_functions import *


if __name__ == "__main__":
    number_of_processes = int(input('Enter number of processes to create\n'))
    processes = list()                    
    exec_time = 1
    global_array = list(range(number_of_processes))
    print(f'%%%%%%%%%%%%%%%%\nCreating {number_of_processes} processes')
    t_start = time.perf_counter()                          # Get an initial timestamp
    for index in range(number_of_processes):
        f = mproc.Process(target=get_process_id, args=(index,exec_time,global_array,))        # Map function to process
        processes.append(f)                                         # Append process to list
        processes[-1].start()                                       # Start the newly appended process
    process_creation_t_elapsed = time.perf_counter()-t_start
    avg_process_creation_time = process_creation_t_elapsed/number_of_processes
    for process in processes:
        process.join()                                               # Join the processes one by one
    overall_t_elapsed = time.perf_counter()-t_start                         # Compare actual timestamp to initial
    print('%%%%%%%%%%%%%%%%\nAll processes finished execution')
    print(f'Process IDs: {global_array[:]}')
    print('The time to create the processes is {:0.3} milliseconds'.format(process_creation_t_elapsed*1e3))
    print('Average time to create a process is {:0.3} milliseconds'.format(avg_process_creation_time*1e3))
    print('The overall elapsed time is {:0.3} seconds'.format(overall_t_elapsed))
