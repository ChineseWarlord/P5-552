import time
import threading

def sleep_function(index):
    print(f'Thread/Process with index {index} began execution')
    time.sleep(1)
    print(f'Thread/Process with index {index} finished execution after {time.thread_time()} s')

def dummy_function(index):          # Function to check execution time
    print(f'Thread/Process with index {index} began execution')
    while(time.thread_time()<1):
        a=0                         # Dummy instruction
    print(f'Thread/Process with index {index} finished execution after {time.thread_time()} s')

if __name__ == "__main__":
    number_of_threads = int(input('Enter number of threads to create\n'))
    threads = list()
    start_time = time.perf_counter()       # Get an initial timestamp
    for index in range(number_of_threads):
        f = threading.Thread(target=sleep_function, args=(index,))          # Select between sleep and dummy function 
        threads.append(f)
        f.start()
    thread_creation_t_elapsed = time.perf_counter() -start_time 
    for thread in threads:
        thread.join()                       # Join the threads one by one
    overall_t_elapsed = time.perf_counter() -start_time      # Compare actual timestamp to initial

    print('The time to create the threads is {:0.3f}'.format(thread_creation_t_elapsed))
    print('The overall elapsed time is {:0.3f}'.format(overall_t_elapsed))