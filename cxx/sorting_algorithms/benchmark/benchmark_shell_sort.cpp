#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include "random.hpp"
#include "shell_sort.hpp"

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

BENCHMARK(BM_shell_sort_int)->RangeMultiplier(10)->Range(10, 10000000)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

