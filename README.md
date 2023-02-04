# Seneca

A building block to help systems just keep on going.

## Purpose

Seneca is designed to be a pluggable and composable primitive that can be used
for many purposes. Even the storage layer does not force requirements of using
persistent media such as SSDs or HDDs. Our Paxos implementation of Write-Once
Registers (WORs) can be used as a library for building other systems such as
Replicated Logs, Replicated State Machines, or even just Compare-And-Swap.

The status quo has always been to implement consensus in the context of a
Replicated State Machine that is driven by transitions appended to a shared
log. Current approaches in open source software such as etcd, Consul,
FoundationDB, Cassandra, Kafka and many others couple their consensus
implementations to Key-Value stores, replicated logs, or transaction managers.

Newer research such as Flexible Paxos, Relaxed Paxos, and Write-Once Registers
show how less coupled primitives are not only easier to optimize but also
easier to implement correctly. Less coupled primitives are also more easily
repurposed.

Seneca is written in Ruby to experiment with using Fibers, FiberSchedule, and
IO::Buffers. Native extensions for io_uring will be written in Zig.

## Testing

Any coordination system is only useful if it is correctly implemented. Seneca
is designed with simulation testing as a first class concept. Each component is
designed to be replaceable with an in-memory implementation that can be
efficiently manipulated and inspected for correct behavior under wild
circumstances.

An entire collection of multiple components (Networking, Disk, Snapshots,
Garbage Collection, Reconfiguration etc.) that make up an instance of the
system can also be instantiated in memory to deterministically verify correct
protocol behavior.

A simple implementation could be single threaded. The throughput and latency
might be suitable for certain use cases where performance isn't required.
Inter-component concurrency can then be layered on and tested to ensure that
protocol invariants still hold for use cases where higher throughput or lower
latency are required.

## Design

