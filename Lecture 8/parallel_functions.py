import os
import time

def sleep_function(index):
    print(f'Thread/Process with index {index} began execution')
    time.sleep(1)
    print(f'Thread/Process with index {index} finished execution after {time.thread_time()} s')

def dummy_function(index):			# Function to check execution time
    print(f'Thread/Process with index {index} began execution')
    while(time.thread_time()<1):
        a=0                         # Dummy instruction
    print(f'Thread/Process with index {index} finished execution after {time.thread_time()} s')
    
def get_process_id(index,execution_time, global_array):
    pid = os.getpid()
    print(f'PID {pid} began executing instructions for {execution_time} seconds')
    while(time.thread_time()<execution_time):
        a=0                         # Dummy instruction
    print(f'PID {pid} finished execution after {time.thread_time()} seconds')
    global_array[index] = pid
    
    
def return_process_id(execution_time):
    pid = os.getpid()
    print(f'PID {pid} began executing instructions for {execution_time} seconds')
    while(time.thread_time()<execution_time):
        a=0                         # Dummy instruction
    print(f'PID {pid} finished execution after {time.thread_time()} seconds')
    return pid
