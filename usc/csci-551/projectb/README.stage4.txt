a) Reused Code
no

b) Complete
Complete all others, but not totally complete reliable transmit.
Primary can get ack from secondary but I do not know how to use timer.
So I do not finish packet resending.

c) Reliability
I try to use timer library, but I can not seperate the callbacks functions with previous 
timeout event(shutdown program if not getting packet within 10 second)

d) Chance of failure
If the secondary routers are busy and the control messages are dropped, like getting into a quite heavy traffic.
Also, if we can not reach secondary routers, out control messages will also get lost.