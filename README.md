# push_swap

Sort a stack using eleven permitted instructions and nothing else, in as few of them as possible.

**125 / 125.** The algorithm is mine rather than a known one — a problem with a number attached to it
is the most interesting kind there is, and I would rather spend two weeks pushing that number down
than an afternoon copying a solution that already works.

## Cost

100 runs per size, measured with the Makefile in this repository.

| Values | Best | Median | Worst | Top-band budget | Headroom |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 5 | 5 | **8** | 11 | ≤ 12 | 33 % |
| 100 | 539 | **573** | 611 | ≤ 700 | 18 % |
| 500 | 3 701 | **3 853** | 4 019 | ≤ 5 500 | 30 % |

The *top-band budget* is 42's threshold for full marks. The **worst** of a hundred random runs still
lands inside it at every size.

Correctness was checked separately: two hundred random stacks of two to five hundred values, sorted
and fed back through the `checker` in this repository — two hundred `OK`, zero failures.

## How it works

**1 — Rank, then label.** Every value is replaced by its rank, so nothing downstream ever compares raw
numbers again: `-2147483648` and `7` become 1 and 2. Each rank is then tagged with which of **eight
chunks** it belongs to. (`data_processing_func.c`)

**2 — Empty *A* from the middle outward.** Four passes, not one. The first sends the two middle chunks
to *B*, the last sends the two extremes — so the values that will be wanted back first end up nearest
the top of *B*. Inside each pass the upper chunk is kept at the top of *B* and the lower chunk at the
bottom, which leaves *B* ordered from both ends instead of churned. The three largest values never
leave *A* at all: they are sorted in place and become the seed the sorted run grows around.

**3 — Pull back whichever element is cheapest.** For every candidate in *B*, four ways of bringing it
and its insertion point together are priced: both stacks rotating up, both down, or one each way.
**Two stacks rotating together cost the larger of the two moves, not their sum** — `rr` advances both
for one instruction — so the schemas that share a direction usually win. The cheapest candidate moves,
and the search starts over. (`cost_functions.c`, `cost_getters.c`)

**4 — Rotate *A* until the smallest value is on top**, whichever way round is shorter.

### The tuning is what actually bought the numbers

Among candidates that cost the same, it takes the larger value; and it only accepts a strictly cheaper
candidate when that candidate is within **five ranks** of the one it would displace. Keeping *B* in
order is worth spending a few instructions on — but only a few. Finding where that line sits was most
of the work, and it is the difference between roughly 5 500 operations and 3 853.

## Build and run

```sh
make                      # builds push_swap
make bonus                # builds the checker as well

./push_swap 3 2 1         # prints the instruction stream
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG    # -> OK
```

`checker` is mine too, not the one 42 hands out: it replays an instruction stream against the input
and answers `OK` or `KO`. Every number in the table above was verified through it.

## Constraints

C, no external libraries. `ft_printf` is vendored in this repository because the curriculum bans
linking anything else — it is my own implementation, from an earlier project.

## Seeing it run

The instruction stream this program emits is replayed, one instruction at a time, at the top of
my portfolio — bar length is each value's rank, colour runs from blue at the smallest to copper at
the largest.
