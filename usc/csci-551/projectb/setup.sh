#!/usr/bin/sh

IP_OF_ETH0=10.0.2.15

# IP_OF_ETH0=10.0.0.5

ip tuntap add dev tun1 mode tun
ifconfig tun1 10.5.51.2/24 up
ip route add table 9 to 128.52/16 dev tun1

ip rule add from $IP_OF_ETH0 table 9 priority 8
ip route add table 9 to 18/8 dev tun1
ip route add table 9 to 128.30/16 dev tun1

iptables -A OUTPUT -p tcp --tcp-flags RST RST -j DROP

ifconfig eth1 192.168.201.2/24 up
ifconfig eth2 192.168.202.2/24 up


