#!/bin/bash

IP_OF_ETH0=10.0.2.15

# router1
ping -I $IP_OF_ETH0 10.5.51.11 -c 1
# router2
ping -I $IP_OF_ETH0 10.5.51.12 -c 1
# router1
curl http://wireless.csail.mit.edu
# router2
curl https://pdos.csail.mit.edu
