import time
import concurrent.futures


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
    sleep = False                          
    threads = list()
    t0 = time.time()                # Get an initial timestamp
    with concurrent.futures.ThreadPoolExecutor(max_workers=number_of_threads) as executor:
        executor.map(sleep_function, (range(number_of_threads)))
    overall_t_elapsed = time.time()-t0      # Compare actual timestamp to initial

    print(f'The overall elapsed time is {overall_t_elapsed}')



