leftpad-c
===

Inspired by [Keltia leftpad](https://github.com/keltia/leftpad) and asked by Stéphane Bortzmeyer in [this tweet](https://twitter.com/bortzmeyer/status/712925376717172737).

Usage
---

```c
#include "leftpad.h"

void main(void)
{
    char* a = left_pad("foo", 0), //  = "foo"
          b = left_pad("foo", 2), //  = "foo"
          c = left_pad("foo", 3), //  = "foo"
          d = left_pad("foo", 5), //  = "  foo"
          e = left_pad("foobar", 8), //  = "  foobar"
          f = left_pad_str("foobar", 10, 'X'); //  = "XXXXfoobar"
}
```

Tests
---

```sh
$ gcc -o leftpad-test leftpad-test.c leftpad.c
$ ./leftpad-test
```