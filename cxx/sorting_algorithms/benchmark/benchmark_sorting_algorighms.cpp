#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>

// 测试不同排序算法的性能 
template <typename T>
static void BM_Sort(benchmark::State& state) {
    std::vector<T> data(state.range(0)); 
    std::generate(data.begin(),  data.end(),  []{ return rand() % 1000; });

    for (auto _ : state) {
        state.PauseTiming();
        auto temp = data; // 复制数据避免原地排序影响 
        state.ResumeTiming();

        std::sort(temp.begin(),  temp.end()); 
    }
    state.SetBytesProcessed(state.iterations()  * data.size()  * sizeof(T));
}

BENCHMARK_TEMPLATE(BM_Sort, int)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

