# Liftcalc

A little warm up weight calculator, based on the pattern described in Starting
Strength 3rd edition, by Mark Rippetoe.

It is unit agnostic, since it just does a little math for you. It doesn't care
about kilograms or pounds.

## Usage

    liftcalc START WORK [STEPS]

Where START is your starting weight (presumably the empty bar), and WORK is your
target working weight. STEPS is how many times you will add weight to the bar.

For example:

    # liftcalc 45 315 5
    45x5x2 95x5 150x3 205x2 260x2 315x5x3

## Installation

Tested with GCC 4.9.2 and GNU Make 4.1, as well as glibc 2.21.

Just run `make` and place the resulting binary somewhere on `$PATH`.
