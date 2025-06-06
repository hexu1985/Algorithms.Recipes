#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "random.hpp"
#include "bubble_sort.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"
#include "quick_sort.hpp"

// 测试不同排序算法的性能 
static void BM_std_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        std::sort(temp.begin(),  temp.end()); 
    }
}

static void BM_bubble_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        bubble_sort(std::span<int>(temp));
    }
}

static void BM_selection_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        selection_sort(std::span<int>(temp));
    }
}

static void BM_insertion_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        insertion_sort(std::span<int>(temp));
    }
}

static void BM_shell_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        shell_sort(std::span<int>(temp));
    }
}

static void BM_quick_sort_int(benchmark::State& state) {
    std::vector<int> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return randint(1, 10000); });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        quick_sort(std::span<int>(temp));
    }
}

BENCHMARK(BM_std_sort_int)->RangeMultiplier(10)->Range(10, 10000000)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_bubble_sort_int)->RangeMultiplier(10)->Range(10, 100000)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_selection_sort_int)->RangeMultiplier(10)->Range(10, 100000)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_insertion_sort_int)->RangeMultiplier(10)->Range(10, 100000)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_shell_sort_int)->RangeMultiplier(10)->Range(10, 10000000)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_quick_sort_int)->RangeMultiplier(10)->Range(10, 10000000)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

