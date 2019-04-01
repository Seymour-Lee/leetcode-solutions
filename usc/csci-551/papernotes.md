### Script for today's mock interview

#### BQ

* Can you introduce yourself
* Talk about your internship or project, tech?
* What is the most chanllege thing?



#### Coding

* Given a list of pairs, eg A->B, B->C, C->D, A->C.
* Also given a source src, and a destination dst
* Find the shortest way from src to dst

时间复杂度？空间复杂度？

##### Follow up

* 假如把这个东西作为一个API放在Amazon的服务器上，那么这个东西会被call很多次，并且有很多重复的call，怎么加快拿到结果的速度
* 假如pair的元素不限于letter，而是任意长度的字符串，这样的话服务器不可能缓存下所有的结果，你该怎么办？设计数据结构，说明每个数据结构的用途





##  Week 1





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
   * the relevant contention is at the receiver，not the sender
   * congestion is location dependent
   * to allocate media access fairly，learning about congestion levels must be a collective enterprise。换句话说，media access protocol 应该传播congestion info，而不是让每个device单独学习congestion情况
   * media access protocol 应该传播关于竞争的synchronization info，这样所有的device才能有效竞争



#### 2. Background（on PARC‘s radio network and MACA media access protocol）

##### 2.1 PARC’s Nano-Cellular Radio Network

1. near-field radio tech使用低频，消除了multipath effects，非常适合室内wireless LAN
2. LAN的基础设施由base station（installed in the ceiling）和pad（portable device）组成
3. 在single channel内，所有的无线通信都发生在base station和pad内。传播距离3-4米，信号衰减很快。每个区域被称为nanocell
4. 

##### 2.2 CSMA



##### 2.3 MACA





#### 3. Designing MACAW（Key section）



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

