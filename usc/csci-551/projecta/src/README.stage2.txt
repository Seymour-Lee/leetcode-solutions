a) Reused Code:
    I reused tun_alloc() from sample_tunnel.c and checksum() from icmp_checksum.c. Both are totally copied 
    and no big midifications made except some output.
   
b) Complete:
    Totally compelete

c) Portable:
    Personally, I think my program should work on different computer architecture, because I do not use
    CPU related codes. But my program may not work work in differnet operating system, because my program
    uses OS related C library, named #include <linux/if_tun.h>, which means it will not work on MacOS or 
    Windows.