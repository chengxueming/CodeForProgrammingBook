<?php

function getbits($x, $p, $n) {
    return ($x >> ($p+1 -$n)) & ~(~0 << $n);
}

echo getbits(28, 4, 3);