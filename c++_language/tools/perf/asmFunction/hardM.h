#pragma once

namespace hardM
{

// real time stamp counter
// Numlber of ticks since last processeur reset
static inline uint64_t rdtsc()
{
    uint64_t rax, rdx;
    __asm__ __volatile__("rdtsc" : "=a"(rax), "=d"(rdx));
    return (rdx << 32) + rax;
}

static inline uint64_t rdtscp()
{
    uint64_t rax, rcx, rdx;
    __asm__ __volatile__("rdtscp" : "=a"(rax), "=d"(rdx), "=c"(rcx));
    return (rdx << 32) + rax;
}

static inline void cpuid()
{
    uint64_t rax, rbx, rcx, rdx;
    __asm__ __volatile__("cpuid" : "=a"(rax), "=b"(rbx), "=d"(rdx), "=c"(rcx));
}

static inline uint64_t rdtscp(int& chip, int& core)
{
    uint64_t rax, rcx, rdx;
    __asm__ __volatile__("rdtscp" : "=a"(rax), "=d"(rdx), "=c"(rcx));
    chip = (rcx & 0xFFF000) >> 12;
    core = rcx & 0xFFF;
    return (rdx << 32) + rax;
}

}