import time

def decorator(func):
    def func_wrapper(x):
        start_time = time.time()
        func(x)
        end_time = time.time()
        print(f"Execution time of Function: {end_time-start_time}")
    return func_wrapper

@decorator
def printer(string):
    print(string)

printer("test")
