# Distributed System

## Architechture

- single/multi master
- all nodes can be a leader
- fault tolerant algorithms
- Zookeeper: FT, consensus, failure detection

### policy

- consistency - linearization, causality
- consensus - quorum with nodes
- leaderless system and multi-leader replication (do not use global consensus)
- act of god (human restart machine)

### CAP theorem

1. consistency, Availability, Partition tolerance

- Partition tolerance - consistent hashing
- consistency - quorum consensus (strong, weak, eventual consistency)
- eventual consitency - dynamo, cassandra 
- vector clock for consistency (add complexity, could grow rapidly so need threshold)

2. availability - handling and failures detection

- decentralized failure detection using protocol like gossip protocol. We maintain a centralized table with a heartbeat counter and the last time updated.
- temporary failures. sloppy quorum : ignoring nodes down and choose healthy servers.
- permanent failures. anti-entropy protocol to keep replicas in sync. a Merkle/Hash tree is used for inconsistency detection. It is more fast to detect when to servers have differences.

3. data centre outage.

### Issues and partial failures

A distributed system has to be fault tolerant.

- network failures
- synch of clock (enven if you use NTP)
- process pause (stop-the-world garbage collector example)
- driver bug

### FT

Byzantine algo: The objective of a BFT mechanism is to safeguard against the system failures by employing collective decision making(both – correct and faulty nodes).

https://www.geeksforgeeks.org/practical-byzantine-fault-tolerancepbft/#:~:text=Practical%20Byzantine%20Fault%20Tolerance%20is,optimized%20for%20low%20overhead%20time.

### replication

serve several purposes:

- hight availability, running when one machine goes down
- disconnected operation, continue to work with a network interruption
- latency, placing data close to the user
- scalability

approaches:

- single-leader replication, send write to a single node, which sends a stream of data change events to the other replicas
- multi-leader replication, sends to one of several nodes, which sends a stream of data change events to the other nodes
- leaderless replication, sends to several nodes and read from several nodes in parallel in order to detect and correct nodes with stale data.
- single is easy to use (no conflict resolution), while multi and leaderless are robust to faulty nodes, network failures, and latency spikes, but providing only very weak consistency guarantees.
- Can be synch/asynch. Asynch can be fast when the system is running smoothy.

strange effect cause by replicatin lag:

- read after write consistency, users should see data that they submitted themselves
- monotimic reads, tehy shouldn't later see teh data from some earlier point in time
- consitent prefix reads, should causal sense. seeing question and response in the correct order 


### partitioning

- range or interval partition: key are sorted (can be by time). Very efficient but can create hot spot on a specific key/date. Efficiet for range queries
- hash partition : range of hashes break the ordering keys and kill range queries, but may distribute load more evenly.
- hybrid parition: one part of the key to identify the partition and another part for the sorted order
- by definition, every partition operates mostly independently -> scale easily
- issue: write on several partition is hard because if one request fails. Prevent by snapshot isolation
### transaction

- without transctions, various error scenarios mean data can become inconsistent 
- concurrency control is the goal of transaction
- race condition: dirty reads, one reads another write before they have been committed
- rc: dirty writes, one overwrites data that another has written but not yet committed
- rc: read skew, a client sees different parts of the database at different points in time
- lost update, 2 concurrently perform q read-modify-write cycle
- write skew, between a read and a write the decision is no longer true
- phantom reads, one writes and affects the result. snapshot isolation prevent it
- serializable snapshot isolation (SSI), fairly new algo that avoids most of the downsides. When transaction wants to commit, it is checked, and it is aborted if the execution was not serializable

## Batch processing

### mapReduce

- https://datascientest.com/mapreduce
- https://www.researchgate.net/figure/Word-count-program-flow-executed-with-MapReduce-5_fig6_270448794
- issue - partitioning and FT: frequently read/write to disk 

Join algorithm:

- sort-merge joins, inputs being joined goes through a mapper that extracts the join key. By partitioning, sorting, and merging, all records with the same key, finish going to the same call of teh reducer
- hash joins, when a large dataset is joined with a small dataset. Data is partitioned by some hash function.

## stream processing

1. AMQP

- delete when consumer acknowledge
- exact order is not important
- no need to go back and read old

2. Log-based message broker

- assign all messages in a partition to the same consumer node, and always delivers messages in the same order.
- maintain meassages on disk, so it is possible to jump back and reread old messages

### Event driven batch processing

- copier, create 2 flows
- filter, remove certain values of the queue
- splitter, create several different flows
- sharder, slighty more generic form of splitter. route the flux on diffrent flow but can aggregate if there is a failed
- merger, merge several flows


