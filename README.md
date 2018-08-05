# hi

Filter lines from stdin matching a given string.

Description
-----------

Read from stdin and display only the lines containing an exact match
of the passed text. The matching text is highlighted when stdout
is a TTY.

Examples
--------

```console
$ cat foo
foo
bar
baz
```

```console
$ cat foo | hi ba
bar
baz
```

Or just redirecting stdin:

```console
$ < foo hi ba
bar
baz
```

It's not shown in this README, but `ba` will be highlighted.

You can also apply `hi` multiple times:

```console
$ cat foo | hi ba | hi r
bar
```

And in this case, only `r` will be highlighted.

Installation
------------

Install `hi` into `/usr/local/bin` with the following command:

```console
$ make install
```

You can use `make PREFIX=/some/other/directory install` if you wish
to use a different destination. If you want to remove `hi` from
your system, use `make uninstall`.

Motivation
----------

The original use case was to grep a very large file. For that
specific use case I didn't need to match a pattern: a strict match
was good enough. That meant I could also make it faster. While
developing this quick solution for a very specific problem, I decided
to highlight the matching text so that I could construct the resulting
set of lines incrementally. In the end, the tool turned out to be
useful by itself, and it can be combined with other tools if different
features are needed. For example, if I want to print the line numbers
along with the matched lines, I can use `cat -n file | hi foo`.

Contributing
------------

If you find a bug, please create an issue detailing the ways to
reproduce it. If you have a suggestion, create an issue detailing
the use case.
