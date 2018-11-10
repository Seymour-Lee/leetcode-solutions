
# Python program to calculate RTT 
  
import time 
import requests 
  
# Function to calculate the RTT 
def RTT(url): 
  
    # time when the signal is sent 
    t1 = time.time() 
  
    r = requests.get(url) 
  
    # time when acknowledgement of signal  
    # is received 
    t2 = time.time() 
  
    # total time taken 
    tim = str(t2-t1) 
  
    print("Time in seconds :" + tim) 
  
# driver program  
# url address 
url = "http://www.google.com"
RTT(url) 