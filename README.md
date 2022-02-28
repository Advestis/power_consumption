# Power consumption

Remakes some of the experiments described in https://greenlab.di.uminho.pt/wp-content/uploads/2017/10/sleFinal.pdf to prove that if one uses numpy and/or pandas packages to tackle cleverly some algorithmic problems (which is what most developpers do), the energy consumption drops dramatically and is comparable to that of C itself.

## Setup

Uses Rapl.h from https://github.com/kentcz/rapl-tools/blob/master/AppPowerMeter.cpp, so check this page to see how to setup the code.

## Building

```bash
make
sudo setcap cap\_sys\_rawio+ep ./launch
```

## Running

```bash
./launch sleep.sh N
```

Will produce a file named 'rapl.csv' containing the energy consumption of "sleep.sh" each of the N steps.

The command to launch, "sleep.sh" here, can not take any argument.
