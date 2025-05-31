#!/usr/bin/bash

current_dir=$( cd $(dirname ${BASH_SOURCE[0]}) && pwd )
#cd ${current_dir} && ./benchmark_sorting_algorighms --benchmark_out=results.json --benchmark_out_format=json

cd ${current_dir}
for benchmark_test in benchmark_std_sort benchmark_selection_sort benchmark_bubble_sort \
    benchmark_insertion_sort benchmark_shell_sort benchmark_quick_sort
do
    ./${benchmark_test} --benchmark_out=${benchmark_test}.json --benchmark_out_format=json
done

