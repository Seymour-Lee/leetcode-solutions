##  Week 1

### w1p1-Hanson99a-Efficient Reading of Papers in Science and Technology
* 记笔记
* 高亮关键点
* 不懂的地方标记
* 给 paper写总结



### w1p2-Jamin03a-Paper Reading and Writing Check Lists

* Nothing to record



### w1p3-Levin83a-An Evaluation of the Ninth SOSP Submissions or How to Write a Good System Paper

* Nothing to record



### w1p4-Heilmeier92a-Some Reflections on Innovation and Invention









## Week 2





## Week 3





## Week 4





## Week 5





## Week 6





## Week 7

### w7p22-Bharghavan94a-MACAW: A Media Access Protocol for Wireless LAN's

#### 1. Abstract && Introduction

1. 这篇文章讨论media access protocols for a single channel wireless LAN。文章从MACA（Multiple Access with Collision Avoidance） media access protocol（使用RTS-CTS-DATA 包交换+binary exponential backoff）出发，提出了一种叫做MACAW的新protocol。
2. Wireless media access protocols for a single channel 可被分为token-based或者multiple access的。本文使用multiple access
3. MACAW的设计基于四个点：
   * the relevant contention is at the receiver，not the sender。竞争发生在接收端，而非发送端。
   * congestion is location dependent。congestion是本地依赖的
   * to allocate media access fairly，learning about congestion levels must be a collective enterprise。换句话说，media access protocol 应该传播congestion info，而不是让每个device单独学习congestion情况
   * media access protocol 应该传播关于竞争的synchronization info，这样所有的device才能有效竞争



#### 2. Background（on PARC‘s radio network and MACA media access protocol）

##### 2.1 PARC’s Nano-Cellular Radio Network

PARC指的是Palo Alto Research Center

1. near-field radio tech使用低频，消除了multipath effects，非常适合室内wireless LAN
2. LAN的基础设施（infra）由base station（installed in the ceiling）和pad（portable device）组成。换言之LAN的infra由基站和移动设备组成
3. 在single channel内，所有的无线通信都发生在base station和pad内。传播距离3-4米，信号衰减很快。每个区域被称为nanocell（因为这个区域很小）
4. 当receiver在两个transmitting station的接收范围内，并且receiver无法分辨出信号来自哪个station时，出现collision。
5. 当receiver在两个transmitting station的接收范围内，并且receiver能分辨出信号来自哪个station时，出现capture。这种情况只可能是两个信号的power ration非常大。换言之，receiver应该离某一个station非常近。Capture的情况非常少见，因此在设计过程中，不被考虑。
6. Interference指receiver在一个范围内，稍稍偏出另一个范围，但是还是分不清信号来自哪个。这种情况也很少见，在设计时不被考虑。
7. 忽略capture和interference两种情况，让模型设计变得很简单。一个station成功收到packet当且仅当接收范围内只有一个active transmitter。论文的模型还基于一些假设：1）没有两个base station在彼此的范围之内。2）没有两个pad在两个base station的范围之内。这种假设对远距离radio是不利的，但是对LAN这种短距离是非常realistic的。
8. 当设备位置已知时，controlling access是非常简单的。但本文中，对pad和base station来说，是无法知道彼此的位置的。
9. 当没有noise的时候，本文设计的系统是symmetirc的，换言之A能听到B，B也应该能听到A。本文考虑noise的情况。
10. 本文选用multiple access approach为不是token是因为：1）多路准入更robust。2）本文希望pad的移动性非常高，cell的size非常小，token的话需要多次recover token

##### 2.2 CSMA（carrier sense multipel access）载波侦听多路访问（一种MAC层协议）

carrier应该指的是载波

**载波侦听**（Carrier Sense）指任何连接到介质的设备在欲发送帧（packet）前，必须对介质进行侦听，当确认其空闲时，才可以发送。**多路访问**（Multiple Access）指多个设备可以同时访问介质，一个设备发送的帧也可以被多个设备接收。

1. CSMA中，每个station在传输前，都侦听载波。如果站发现载波被占用，那么就defer自己。CSMA会决定啥时候重试。
2. CSMA通过测试信号强度来避免collision。CSMA的冲突在接收端发生。CSMA并没有提供避免冲突的info。
3. hidden terminal隐藏站问题。C想要传输，但此时A正在给B传。C不知道A在传，此时冲突。
4. exposed terminal暴露站问题。C想要传输，但此时B正在给A传。C知道B在传，但因为C不给B传，此时没理由defer。

A——B——C，A和C互相看不见，B能看见A和C

5. 载波侦听实际上在发送端提供了一种避免冲突的方案。

##### 2.3 MACA

1. MACA使用两种short，fixed size signaling packets。当A想给B发消息的时候，先发用一个RTS（Request to Send）给B，RTS里面包含了transmission的长度。如果B拿到了A的RTS，并且B这会儿没被defer，那么B回A一个CTS（Clear to Send），CTS里面也包含transmisson的长度。收到CTS后，A马上开始传data。任何station听到RTS后，都defer自己的传输，直到RTS所在的传输结束。任何station听到CTS后，也defer自己。
2. 所有听到RTS的station都会defer，为了让发RTS的站听到对应的CTS。所有听到CTS的station都会避免和正在传输的data有collision。
3. 根据对称，所有能和数据传输发生冲突的station，都在CTS的范围内。除非该站正忙。只收到RTS而收不到CTS说明该站在接收站以外，该站不影响传输。
4. 在隐藏站问题中，C能听到B的CTS，但听不到A的RTS，因此会defer，因为要避免B的接收冲突。在暴露站问题中，C能听到B的RTS，但听不到A的CTS，因此知道接收站在range外，自己的传输不影响对方。
5. MACA实际上是在接收端避免冲突。CTS其实是散播冲突info，告诉range内的station我这儿要传输。
6. A如果收不到B的CTS的话，会重传。MACA使用binary exponential backoff（BEB，二进制指数退避算法）来选择重传时间。

#### 3. Designing MACAW（Key Section）

1. 本文修改了MACA，使他能够适应PARC的wireless LAN。
2. 控制包（RTS，CTS）都是30字节长
3. 重传时间的单位为slot，为integer。重传当且仅当station没有收到发出的RTS对应的CTS。
4. station在1和BO之间randomly chooses with uniform distribution。BO指的是backoff counter。Backoff Algo通过两个函数Fdec和Finc，修改BO的值。收到CTS，BO=Fdec=BOmin；没收到CTS，BO=Finc=min（2*BO， BOmax）
5. 文章提到了实验的simulation环境。很细节，感觉对理解paper没有帮助
6. 文章主要讨论MAC（Media access protocol）的两方面：backoff algorithm和basic RTS-CTS信息交换
7. 文章在evalution的时候主要考虑对网络的利用率和对media的fair access。这俩原则冲突的时候，选fairness

##### 3.1 Backoff Algorithm

1. 文章认为MACA中的二进制指数退避，没有fairness。假设一个cell里面只有一个station和俩pad，这俩pad使用同样的算法，并且都能不停地产生足够的UDP去充满channel。那么其中一个pad会一直backoff，因为他一直被回退，并且被defer时，另一个又进行了新的传输。造成这种问题的原因在于，每一个station or pad不共享congestion的信息。
2. 为了解决这一问题，在header里面加一个backoff counter value，每当一个station收到一个包，就copy新的backoff counter到本地。
3. MACA的二进制指数退避还有一个问题，就是对backoff counter的修改幅度太大：dec是直接最小。 ins的时候直接乘2。这样在对media的需求量很大的，有很多station or pad的时候，不太好。
4. 上面的问题改成了：dec时减1。 ins的时候直接乘一个factor，like 1.5。

##### 3.2 Multiple Stream Model

1. 

##### 3.3 Basic Message Exchange

###### 3.3.1 ACK



###### 3.3.2 DS



###### 3.3.3 RRTS



###### 3.3.4 Multicast







##### 3.4 Backoff Algorithm Revisited

1. 3.1中提到的backoff algo只适用于single number，并且congestion是homogeneous。



##### 3.5 Preliminary Evalution of MACAW







#### 4. Future Design Issues



#### 5. Summary





## Week 8





## Week 9





## Week 10

### w10p28-



### w10p29-Dean04a-MapReduce



Q1. According to this paper, each mapper and reducer write their output into a seperate file. Why not write the output into the same file?

* For mappers, writting to one single file is unnecessary, because master node will assign the output of each mapper to a reducer. In this step, we only concern the output of each mapper.
* For reducer, writting to a single file seems to make sense. But I think, if we do this in our system, we have to take care of **data consistency**. In the example of counting the number of occurrences in documents, if reducers writting to one single file, we need to deal with **read-write conflict**, which will make our system more complex.(correctness)

Q2. The paper mentions if the master node fails, we will redo the work. Is there any other better way to deal with this?

* Maybe using a **monitor** node is a good idea. Master node keeps recoding checkpoints. And if monitor node finds master is down, it will recover master with checkpoints. (running stably)
* Maybe we can design an **algorithm** to elect a new master node of running nodes.
* I think there is not a 100% reliable way to avoid master failure.



#### Abstract && Introduction

1. Mapreduce: a programming model and an associated implementation for processing and generating large data sets.
   * Map: process a {key, value} pair to generate a **set** of intermediate {key, value} pairs
   * Reduce: merge **all** intermediate values assocaited with the same intermediate key (to a smaller set)
2. Programs with Mapreduce would automatically parallelized and executed on a large cluster of machines.
3. This paper desigend Mapreduce(a new abstraction) to parallelize the computation, distrubute the data, and handle failure conspire
4. The idea come from the map and reduce primitives in Lisp



#### Programming Model

1. The computation of Mapreduce takes a set of input {key, value} pairs, and produces a set of output {key, value} pairs.
2. Map and Reduce functions are written by users.

##### Example

counting the number of occurences of each word in a large collection of documents

```C++
void map(string key, string value){
  // key: document name
  // value: document contents
  for(each_word in value){
    emit_intermediate(w, "1"); // {key, value} = {w, "1"}, 1 means one time
  }
}

int reduce(string key, iterator values){
  // key: a word
  // values: a list of counts
  int result = 0;
  for(each_v in values){
    result += to_int(v);
  }
  return result; // the number of occurences of a word
}
```

##### Types

Conceptually, the map and reduce functions supplied by the user have associated types:

map	{k1, v1}         —> list(k2, v2)

reduce    {k2, list(v2)} —> list(v2)

#### Implementation

![Execution overview](paperimages/w10p29-Dean04a-01.jpg)

输入被分成好多份，map按照一定规则给workers；workers生成中间pairs，写在存储设备上；reduce读这些pairs，整合相同的key，输出。User只需要编写Map和Reduce的代码。Steps:

* split the input files into M pieces
* 



#### Refinements

