#!/usr/bin/bash

cat bipartite-graph.txt
./code_13_5 < ./bipartite-graph.txt

echo
echo

cat non-bipartite-graph.txt
./code_13_5 < ./non-bipartite-graph.txt

