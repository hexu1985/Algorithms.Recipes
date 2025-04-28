#!/usr/bin/bash

current_dir=$( cd $(dirname ${BASH_SOURCE[0]}) && pwd )
cd ${current_dir} && ./benchmark_sorting_algorighms --benchmark_out=results.json --benchmark_out_format=json

