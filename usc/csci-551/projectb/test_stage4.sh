#! /bin/bash

IP_OF_ETH0=10.0.2.15

# IP_OF_ETH0=10.0.0.5

# FORWARD
ping -I $IP_OF_ETH0 wireless.csail.mit.edu -c 1
# REPLY
ping -I $IP_OF_ETH0 10.5.51.3 -c 1
# DROP
ping -I $IP_OF_ETH0 10.5.51.4 -c 1
# REPLY
ping -I $IP_OF_ETH0 10.5.51.25 -c 1
